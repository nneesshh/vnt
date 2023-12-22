@echo off&color 17 
if exist "%SystemRoot%\SysWOW64" path %path%;%windir%\SysNative;%SystemRoot%\SysWOW64;%~dp0 
bcdedit >nul 
if '%errorlevel%' NEQ '0' (goto UACPrompt) else (goto UACAdmin) 
:UACPrompt 
%1 start "" mshta vbscript:createobject("shell.application").shellexecute("""%~0""","::",,"runas",1)
(window.close)&exit 
exit /B 
:UACAdmin 
cd /d "%~dp0" 
echo 当前运行路径是：%CD% 
echo 已获取管理员权限

cd ..\bin
start "vnt-cli" vnt-cli.exe -k abcdefg41 -s 18.163.12.34:29619 --tcp
cd ..\script