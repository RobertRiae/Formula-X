@echo off
REM ===========================
REM Restore & Build Script
REM ===========================

REM Ensure .vscode folder exists
if not exist ".vscode" mkdir ".vscode"

REM ---------------------------
REM launch.json
REM ---------------------------
(
echo {
echo "version": "0.2.0",
echo "configurations": [
echo {
echo "name": "Debug Project",
echo "type": "cppdbg",
echo "request": "launch",
echo "program": "${workspaceFolder}/project.exe",
echo "args": [],
echo "stopAtEntry": false,
echo "cwd": "${workspaceFolder}",
echo "environment": [],
echo "externalConsole": false,
echo "console": "integratedTerminal",
echo "MIMode": "gdb",
echo "miDebuggerPath": "C:/msys64/ucrt64/bin/gdb.exe",
echo "preLaunchTask": "Build Project"
echo }
echo ]
echo }
) > ".vscode\launch.json"

REM ---------------------------
REM tasks.json
REM ---------------------------
(
echo {
echo "version": "2.0.0",
echo "tasks": [
echo {
echo "label": "Build Project",
echo "type": "shell",
echo "command": "g++",
echo "args": [
echo "pro_xxx.cpp",
echo "transpose.cpp",
echo "caeser.cpp",
echo "-o",
echo "project.exe",
echo "-std=c++17"
echo ],
echo "group": {
echo "kind": "build",
echo "isDefault": true
echo },
echo "problemMatcher": ["$gcc"]
echo }
echo ]
echo }
) > ".vscode\tasks.json"

echo .vscode configurations successfully created and restored! Meow Meow.

REM ---------------------------
REM Build the project now
REM ---------------------------
set SOURCES=pro_xxx.cpp transpose.cpp caeser.cpp
for %%f in (%SOURCES%) do (
    if not exist "%%f" (
        echo Error: %%f not found!
        pause
        exit /b 1
    )
)

echo Building project...
g++ pro_xxx.cpp transpose.cpp caeser.cpp -o project.exe -std=c++17  
if %errorlevel% neq 0 (
    echo Oops Build failed.Try Again TT.
    pause
    exit /b %errorlevel%
) else (
    echo YAY Build succeeded!
    echo -------------------------
    echo Running project.exe ...
    echo -------------------------
    project.exe
    echo.
    pause
)
