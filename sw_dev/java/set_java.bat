@echo off
rem setlocal

if "%1%" == "--set" goto SET
if "%1%" == "--clean" goto CLEAN

echo.
echo Usage :
echo   "%0% [--set | --clean]"
echo.

goto EXIT

rem -----------------------------------------------------------
:SET

set JAVA_HOME=D:\util_portable\jdk-12.0.2_windows-x64_bin\jdk-12.0.2

set SAVED_PATH_FOR_JAVA=%PATH%
set PATH=%JAVA_HOME%\bin;%PATH%

goto EXIT

rem -----------------------------------------------------------
:CLEAN

set JAVA_HOME=

set PATH=%SAVED_PATH_FOR_JAVA%
set SAVED_PATH_FOR_JAVA=

rem -----------------------------------------------------------
:EXIT

rem endlocal
echo on
