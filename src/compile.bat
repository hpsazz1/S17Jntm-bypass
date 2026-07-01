@echo off
REM =====================================================
REM 编译 FBrowserVIP.dll 代理 DLL
REM 需要: Visual Studio 2022 Developer Command Prompt (x86)
REM =====================================================
REM
REM 使用方法:
REM   1. 打开 "Developer Command Prompt for VS 2022"
REM   2. 确保环境为 x86（32位）
REM   3. cd 到此目录
REM   4. 运行 compile.bat
REM
REM 部署:
REM   1. 备份原始 FBrowserVIP.dll → FBrowserVIP_original.dll
REM   2. 将 dll_proxy.dll 重命名为 FBrowserVIP.dll
REM   3. 放入 CEFlib/ 目录
REM   4. 启动 mYjJYFSJwydN.exe
REM =====================================================

REM 清理旧文件
if exist dll_proxy.obj del dll_proxy.obj
if exist dll_proxy.dll del dll_proxy.dll
if exist dll_proxy.lib del dll_proxy.lib
if exist dll_proxy.exp del dll_proxy.exp

REM 编译 x86 DLL
cl /nologo /O2 /GS- /MD /LD dll_proxy.c /link /DEF:dll_proxy.def

echo.
if exist dll_proxy.dll (
    echo [OK] 编译成功: dll_proxy.dll
    echo.
    echo 下一步:
    echo   1. copy /Y FBrowserVIP.dll FBrowserVIP_original.dll
    echo   2. copy /Y dll_proxy.dll FBrowserVIP.dll
    echo   3. 启动 mYjJYFSJwydN.exe
) else (
    echo [FAIL] 编译失败，请检查错误信息
)
pause
