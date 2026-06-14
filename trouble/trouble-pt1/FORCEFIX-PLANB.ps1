<#
.SYNOPSIS
    彻底修复被恶意脚本（如 FORCEBANWLAN.bat）破坏的无线网络功能。
.DESCRIPTION
    该脚本会恢复 WLAN 驱动、重置网络堆栈、修复服务与注册表，并强制重新安装无线网卡。
.NOTES
    需要管理员权限。执行完毕后请重启电脑。
#>

# 要求管理员权限
if (-NOT ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole] "Administrator")) {
    Write-Host "错误：请以管理员身份运行此脚本。" -ForegroundColor Red
    pause
    exit 1
}

Write-Host "========================================" -ForegroundColor Cyan
Write-Host "    强制爆破禁用WLAN脚本 计划B" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan

# ---------- 1. 重置网络核心组件 ----------
Write-Host "[1/7] 重置 Winsock 和 TCP/IP 堆栈..." -ForegroundColor Yellow
netsh winsock reset
netsh int ip reset
netsh int ipv6 reset
netsh winhttp reset proxy
Write-Host "    完成。" -ForegroundColor Green

# ---------- 2. 释放并刷新 IP ----------
Write-Host "[2/7] 释放并刷新 IP 地址..." -ForegroundColor Yellow
ipconfig /release
ipconfig /renew
ipconfig /flushdns
Write-Host "    完成。" -ForegroundColor Green

# ---------- 3. 修复 WLAN 服务 ----------
Write-Host "[3/7] 修复 WLAN 自动配置服务..." -ForegroundColor Yellow
# 确保服务启动类型为自动
Set-Service -Name WlanSvc -StartupType Automatic -ErrorAction SilentlyContinue
Stop-Service -Name WlanSvc -Force -ErrorAction SilentlyContinue
Start-Sleep -Seconds 2
Start-Service -Name WlanSvc -ErrorAction SilentlyContinue
Write-Host "    WlanSvc 状态: $( (Get-Service -Name WlanSvc).Status )" -ForegroundColor Green

# 清理可能被脚本篡改的注册表项（禁用无线的常见位置）
$regPaths = @(
    "HKLM:\SYSTEM\CurrentControlSet\Services\WlanSvc",
    "HKLM:\SYSTEM\CurrentControlSet\Services\WwanSvc"
)
foreach ($path in $regPaths) {
    if (Test-Path $path) {
        Set-ItemProperty -Path $path -Name "Start" -Value 2 -ErrorAction SilentlyContinue
        Write-Host "    已修复 $path 的启动类型" -ForegroundColor Green
    }
}

# ---------- 4. 强制重新安装无线网卡驱动 ----------
Write-Host "[4/7] 强制重装无线网卡驱动 (PnP 扫描)..." -ForegroundColor Yellow
# 触发 PnP 设备重新扫描
pnputil /scan-devices
Start-Sleep -Seconds 3

# 查找无线网卡（通过多种方式）
$wlanAdapter = Get-NetAdapter | Where-Object { 
    $_.InterfaceDescription -match "wireless|wlan|wi-fi|802.11|无线" -or 
    $_.Name -match "wlan|wi-fi|无线" 
}
if ($wlanAdapter) {
    $adapterName = $wlanAdapter.Name
    Write-Host "    找到无线适配器: $adapterName" -ForegroundColor Green
    Write-Host "    正在禁用并重新启用适配器..."
    Disable-NetAdapter -Name $adapterName -Confirm:$false -ErrorAction SilentlyContinue
    Start-Sleep -Seconds 3
    Enable-NetAdapter -Name $adapterName -Confirm:$false -ErrorAction SilentlyContinue
    # 强制重新安装驱动
    pnputil /restart-device $wlanAdapter.PnpDeviceID 2>$null
} else {
    Write-Host "    未通过 NetAdapter 找到无线网卡，尝试使用 PnP 设备方式..." -ForegroundColor Yellow
    # 通过设备管理器查找可能被禁用的无线设备
    $wlanDevices = Get-PnpDevice | Where-Object { 
        $_.FriendlyName -match "wireless|wlan|wi-fi|802.11|无线|蓝牙" -and 
        $_.Class -eq "Net" 
    }
    if ($wlanDevices) {
        foreach ($dev in $wlanDevices) {
            Write-Host "    找到设备: $($dev.FriendlyName)" -ForegroundColor Green
            if ($dev.Status -ne "OK") {
                Enable-PnpDevice -InstanceId $dev.InstanceId -Confirm:$false -ErrorAction SilentlyContinue
                Write-Host "    已尝试启用设备" -ForegroundColor Green
            }
            # 重启设备
            Restart-PnpDevice -InstanceId $dev.InstanceId -Confirm:$false -ErrorAction SilentlyContinue
        }
    } else {
        Write-Host "    警告：未找到任何无线网络设备。请确保无线网卡未被物理禁用或损坏。" -ForegroundColor Red
    }
}

# ---------- 5. 清理可能导致驱动无法加载的注册表标志 ----------
Write-Host "[5/7] 清理驱动禁用标志..." -ForegroundColor Yellow
# 某些脚本会在设备实例上添加 "Disabled" 键值
$netDevicePaths = Get-ChildItem "HKLM:\SYSTEM\CurrentControlSet\Enum\PCI" -ErrorAction SilentlyContinue | Where-Object { $_.Name -match "network|无线" }
foreach ($path in $netDevicePaths) {
    $disableKey = Join-Path $path.PSPath "Device Parameters"
    if (Test-Path $disableKey) {
        Remove-ItemProperty -Path $disableKey -Name "Disabled" -ErrorAction SilentlyContinue -Force
        Write-Host "    已清理 $($path.PSChildName) 中的 Disabled 标记"
    }
}


Write-Host "[6/7] 修复网络关联 DLL 注册..." -ForegroundColor Yellow
$dlls = @("netshell.dll", "netcfgx.dll", "netman.dll", "ole32.dll")
foreach ($dll in $dlls) {
    $full = "$env:SystemRoot\System32\$dll"
    if (Test-Path $full) {
        regsvr32.exe /s $full
        Write-Host "    已重新注册 $dll"
    }
}

# ---------- 6. 系统文件完整性检查 ----------
Write-Host "[7/7] 运行系统文件检查 (SFC)..." -ForegroundColor Yellow
sfc /scannow
Write-Host "    完成。" -ForegroundColor Green

Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "所有修复步骤已完成！" -ForegroundColor Green
Write-Host "强烈建议立即重启电脑以使更改生效。" -ForegroundColor Yellow
Write-Host "========================================" -ForegroundColor Cyan

$restart = Read-Host "是否现在重启？(Y/N)"
if ($restart -eq 'Y' -or $restart -eq 'y') {
    Restart-Computer -Force
} else {
    Write-Host "请稍后手动重启电脑。" -ForegroundColor Cyan
    pause
}