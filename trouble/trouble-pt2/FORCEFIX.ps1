<#
.SYNOPSIS
    修复“WLAN 没有有效的 IP 配置”问题
.DESCRIPTION
    执行以下操作：
    - 释放并更新 DHCP 租约
    - 重置 Winsock 和 TCP/IP 堆栈
    - 重启 WLAN 自动配置服务
    - 重启无线网卡
.NOTES
    需要管理员权限
#>

# 确保以管理员身份运行
if (-NOT ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole] "Administrator")) {
    Write-Host "此脚本需要管理员权限。正在请求提升..." -ForegroundColor Yellow
    Start-Process PowerShell -Verb RunAs "-NoProfile -ExecutionPolicy Bypass -File `"$PSCommandPath`""
    exit
}

Write-Host "=== WLAN IP 配置修复脚本 ===" -ForegroundColor Cyan

# 获取无线网卡名称（通常包含 "WLAN" 或 "Wi-Fi"）
$wlanAdapter = Get-NetAdapter | Where-Object { $_.InterfaceDescription -like "*Wireless*" -or $_.Name -like "*WLAN*" -or $_.Name -like "*Wi-Fi*" } | Select-Object -First 1
if (-not $wlanAdapter) {
    Write-Host "未找到无线网卡，请确认网卡名称。" -ForegroundColor Red
    exit
}
$adapterName = $wlanAdapter.Name
Write-Host "找到无线网卡: $adapterName" -ForegroundColor Green

# 显示当前 IP 配置
Write-Host "`n[当前 IP 配置]" -ForegroundColor Yellow
ipconfig /all | Select-String -Pattern "$adapterName|IPv4|DHCP|自动配置"

# 1. 释放 IP
Write-Host "`n[1] 释放当前 IP 地址..." -ForegroundColor Yellow
ipconfig /release "$adapterName" 2>&1 | Out-Null
Start-Sleep -Seconds 2

# 2. 更新 DHCP 租约
Write-Host "[2] 更新 IP 地址 (请求 DHCP)..." -ForegroundColor Yellow
ipconfig /renew "$adapterName" 2>&1 | Out-Null
Start-Sleep -Seconds 3

# 3. 重置 Winsock
Write-Host "[3] 重置 Winsock 目录..." -ForegroundColor Yellow
netsh winsock reset
Start-Sleep -Seconds 1

# 4. 重置 TCP/IP 堆栈
Write-Host "[4] 重置 TCP/IP 堆栈..." -ForegroundColor Yellow
netsh int ip reset
Start-Sleep -Seconds 1

# 5. 重启 WLAN 自动配置服务
Write-Host "[5] 重启 WLAN AutoConfig 服务..." -ForegroundColor Yellow
Restart-Service -Name WlanSvc -Force
Start-Sleep -Seconds 3

# 6. 禁用并重新启用无线网卡（模拟拔插）
Write-Host "[6] 重启无线网卡硬件..." -ForegroundColor Yellow
Disable-NetAdapter -Name $adapterName -Confirm:$false
Start-Sleep -Seconds 5
Enable-NetAdapter -Name $adapterName -Confirm:$false
Start-Sleep -Seconds 8

# 最终检查
Write-Host "`n[修复完成] 当前 IP 配置状态：" -ForegroundColor Cyan
$ipconfig = ipconfig /all | Select-String -Pattern "$adapterName|IPv4 地址|DHCP 已启用|自动配置已启用" -Context 0,1
$ipconfig

# 判断是否成功获取 IP (排除 169.254.x.x 自动私有地址)
$ipv4 = (Get-NetIPAddress -InterfaceAlias $adapterName -AddressFamily IPv4 -ErrorAction SilentlyContinue).IPAddress
if ($ipv4 -and $ipv4 -notlike "169.254.*") {
    Write-Host "`n✅ 成功获取有效 IP 地址: $ipv4" -ForegroundColor Green
} else {
    Write-Host "`n❌ 仍未获取到有效 IP 地址 (可能是 DHCP 服务器问题或热点限制)" -ForegroundColor Red
    Write-Host "建议手动操作：" -ForegroundColor Yellow
    Write-Host "  1. 重启路由器/热点设备" -ForegroundColor White
    Write-Host "  2. 尝试连接其他 Wi-Fi (如手机热点)" -ForegroundColor White
    Write-Host "  3. 更新无线网卡驱动 (当前 Intel 8260 驱动 20.70.3.3 可升级)" -ForegroundColor White
}

Read-Host "`n按 Enter 键退出"