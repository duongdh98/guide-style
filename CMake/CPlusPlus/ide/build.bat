```bat
@echo off
setlocal

REM ============================================================
REM PATH
REM ============================================================

REM Folder containing this build.bat
set "IDE_DIR=%~dp0"

REM Project root
for %%I in ("%IDE_DIR%..") do set "ROOT_DIR=%%~fI"

REM Build directory
set "BUILD_DIR=%IDE_DIR%build"

REM Executable
set "EXE=%BUILD_DIR%\zapp.exe"


REM ============================================================
REM MENU
REM ============================================================

:MENU

cls

echo ========================================
echo              ZAPP - C++
echo ========================================
echo.
echo   [1] BUILD
echo   [2] RUN
echo   [3] BUILD + RUN
echo   [4] CLEAN
echo   [5] EXIT
echo.
echo ========================================
echo.

choice /c 12345 /n /m "Select: "

if errorlevel 5 goto EXIT
if errorlevel 4 goto CLEAN
if errorlevel 3 goto BUILD_RUN
if errorlevel 2 goto RUN
if errorlevel 1 goto BUILD


REM ============================================================
REM BUILD
REM ============================================================

:BUILD

cd /d "%IDE_DIR%"

echo.
echo ========================================
echo                 BUILD
echo ========================================
echo.

if not exist "build\CMakeCache.txt" (

    echo [1/2] Configuring CMake...
    echo.

    cmake -S . -B build -G "MinGW Makefiles"

    if errorlevel 1 (
        echo.
        echo ========================================
        echo      CMAKE CONFIGURATION FAILED
        echo ========================================
        echo.
        pause
        goto MENU
    )
)

echo.
echo [2/2] Building C++ project...
echo.

cmake --build build

if errorlevel 1 (
    echo.
    echo ========================================
    echo             BUILD FAILED
    echo ========================================
    echo.
    pause
    goto MENU
)

echo.
echo ========================================
echo            BUILD SUCCESS
echo ========================================
echo.

pause
goto MENU


REM ============================================================
REM RUN
REM ============================================================

:RUN

cd /d "%IDE_DIR%"

echo.
echo ========================================
echo                  RUN
echo ========================================
echo.

if not exist "%EXE%" (
    echo [ERROR] Executable not found:
    echo.
    echo %EXE%
    echo.
    echo Please BUILD the project first.
    echo.
    pause
    goto MENU
)

echo [INFO] Starting ZAPP...
echo.
echo ----------------------------------------
echo.

"%EXE%"

echo.
echo ----------------------------------------
echo.
echo ============ PROGRAM EXITED ============

pause
goto MENU


REM ============================================================
REM BUILD + RUN
REM ============================================================

:BUILD_RUN

cd /d "%IDE_DIR%"

echo.
echo ========================================
echo              BUILD + RUN
echo ========================================
echo.

if not exist "build\CMakeCache.txt" (

    echo [1/3] Configuring CMake...
    echo.

    cmake -S . -B build -G "MinGW Makefiles"

    if errorlevel 1 (
        echo.
        echo ========================================
        echo      CMAKE CONFIGURATION FAILED
        echo ========================================
        echo.
        pause
        goto MENU
    )
)

echo.
echo [2/3] Building C++ project...
echo.

cmake --build build

if errorlevel 1 (
    echo.
    echo ========================================
    echo             BUILD FAILED
    echo ========================================
    echo.
    pause
    goto MENU
)

echo.
echo [3/3] Running ZAPP...
echo.
echo ----------------------------------------
echo.

"%EXE%"

echo.
echo ----------------------------------------
echo.
echo ============ PROGRAM EXITED ============

pause
goto MENU


REM ============================================================
REM CLEAN
REM ============================================================

:CLEAN

cd /d "%IDE_DIR%"

echo.
echo ========================================
echo                 CLEAN
echo ========================================
echo.

if exist build (
    rmdir /s /q build
    echo [OK] Build directory removed.
) else (
    echo [INFO] Build directory does not exist.
)

echo.
pause
goto MENU


REM ============================================================
REM EXIT
REM ============================================================

:EXIT

echo.
echo Exiting...
echo.

exit /b 0
```
