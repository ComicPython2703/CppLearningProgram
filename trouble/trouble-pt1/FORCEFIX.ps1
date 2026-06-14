<#
.SYNOPSIS
    修复 Windows 中“WLAN 适配器驱动程序可能导致 IP 协议堆栈无法绑定”的问题。
.DESCRIPTION
    该脚本会执行以下操作：
    1. 重置 Winsock 目录和 TCP/IP 堆栈。
    2. 释放并更新 IP 地址。
    3. 刷新 DNS 缓存。
    4. 重启 WLAN AutoConfig 服务。
    5. 禁用并重新启用无线网络适配器（尝试自动选择）。
    6. 重新注册网络相关的 DLL 文件（可选）。
.NOTES
    必须以管理员身份运行。
#>

# 要求以管理员权限运行
if (-NOT ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole] "Administrator")) {
    Write-Host "错误：该脚本需要管理员权限。请右键选择“以管理员身份运行”。" -ForegroundColor Red
    exit 1
}

Write-Host "开始修复 WLAN 网络堆栈问题..." -ForegroundColor Cyan

# 1. 重置 Winsock 和 TCP/IP
Write-Host "1. 重置 Winsock 目录..."
netsh winsock reset
if ($LASTEXITCODE -eq 0) { Write-Host "   Winsock 重置成功。" -ForegroundColor Green }
else { Write-Host "   Winsock 重置失败，错误代码: $LASTEXITCODE" -ForegroundColor Red }

Write-Host "2. 重置 TCP/IP 堆栈..."
netsh int ip reset
if ($LASTEXITCODE -eq 0) { Write-Host "   TCP/IP 重置成功。" -ForegroundColor Green }
else { Write-Host "   TCP/IP 重置失败，错误代码: $LASTEXITCODE" -ForegroundColor Red }

# 2. 释放 IP 地址
Write-Host "3. 释放当前 IP 地址..."
ipconfig /release
Start-Sleep -Seconds 2

# 3. 更新 IP 地址
Write-Host "4. 重新获取 IP 地址..."
ipconfig /renew
Start-Sleep -Seconds 2

# 4. 刷新 DNS
Write-Host "5. 刷新 DNS 缓存..."
ipconfig /flushdns

# 5. 重启 WLAN 服务
Write-Host "6. 重启 WLAN AutoConfig 服务..."
Restart-Service -Name WlanSvc -Force -ErrorAction SilentlyContinue
if ($?) { Write-Host "   WLAN 服务已重启。" -ForegroundColor Green }
else { Write-Host "   重启 WLAN 服务失败，请手动检查服务状态。" -ForegroundColor Yellow }

# 6. 查找并重置无线网络适配器
Write-Host "7. 查找无线网络适配器并执行禁用/启用..."
$wlanAdapter = Get-NetAdapter | Where-Object { $_.InterfaceDescription -match "wireless|wlan|wi-fi|802.11" }
if ($wlanAdapter) {
    $adapterName = $wlanAdapter.Name
    Write-Host "   找到无线适配器: $adapterName"
    Write-Host "   正在禁用适配器..."
    Disable-NetAdapter -Name $adapterName -Confirm:$false -ErrorAction SilentlyContinue
    Start-Sleep -Seconds 3
    Write-Host "   正在启用适配器..."
    Enable-NetAdapter -Name $adapterName -Confirm:$false -ErrorAction SilentlyContinue
    Start-Sleep -Seconds 2
    Write-Host "   适配器已重置。" -ForegroundColor Green
}
else {
    Write-Host "   未找到无线网络适配器，请手动在“设备管理器”中禁用并重新启用。" -ForegroundColor Yellow
}

# 7. 重新注册一些网络相关 DLL（可选）
Write-Host "8. 重新注册网络相关 DLL 文件..."
$dlls = @(
    "netshell.dll",
    "netcfgx.dll",
    "netman.dll"
)
foreach ($dll in $dlls) {
    $fullPath = Join-Path $env:SystemRoot "System32\$dll"
    if (Test-Path $fullPath) {
        regsvr32.exe /s $fullPath
        Write-Host "   已重新注册 $dll"
    }
}

Write-Host "`n所有操作执行完毕。" -ForegroundColor Cyan
Write-Host "建议重启计算机以使所有更改完全生效。" -ForegroundColor Yellow

# 询问是否立即重启
$restart = Read-Host "是否现在重启计算机？(Y/N)"
if ($restart -eq 'Y' -or $restart -eq 'y') {
    Restart-Computer -Force
}
else {
    Write-Host "请稍后手动重启电脑。" -ForegroundColor Green
}