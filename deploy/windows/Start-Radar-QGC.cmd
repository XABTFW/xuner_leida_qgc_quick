@echo off
setlocal
rem Optional first argument: a deployed QGroundControl.exe.
set "RADAR_QGC_EXE=%~1"
if not defined RADAR_QGC_EXE set "RADAR_QGC_EXE=%~dp0..\..\build\Desktop_Qt_6_8_3_MSVC_2022_64_bit_Release\Release\QGroundControl.exe"
if not exist "%RADAR_QGC_EXE%" (
    echo QGroundControl.exe was not found. Build Release or pass the deployed executable path.
    pause
    exit /b 1
)
rem Development runtime fallback; a deployed package uses its own bundled DLLs.
if exist "C:\Qt\6.8.3\msvc2022_64\bin" set "PATH=C:\Qt\6.8.3\msvc2022_64\bin;%PATH%"
if exist "C:\gstreamer\1.0\msvc_x86_64\bin" set "PATH=C:\gstreamer\1.0\msvc_x86_64\bin;%PATH%"
set "QGC_RADAR_PORT=14009"
set "QGC_RADAR_CRC=none"
set "QGC_RADAR_FORCE_ID="
set "QGC_RADAR_DIAG=0"
set "QGC_RADAR_LOG=%TEMP%\qgc_radar_debug.txt"
echo Radar UDP: 14009. Log: %QGC_RADAR_LOG%
start "" "%RADAR_QGC_EXE%"
endlocal
