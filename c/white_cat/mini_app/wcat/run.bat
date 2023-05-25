@rem /***************************************************************************************************************
@rem  * @detail          : Softmware wirite in free time and write for white cat
@rem  * @auth            : duonghd                                                        
@rem  * @day             : 11-may-2023
@rem  * @file            : main.bat                                              
@rem  * @dissaption      : File to create white cat project . Coding in free time                                       
@rem ***************************************************************************************************************/

@echo off

:CLEAR
    cls
    if exist "mini_wcat.exe" (
        del mini_wcat.exe > nul
    )
    goto :BUILD

:BUILD
    gcc -o mini_wcat.exe common/*.h common/*.c cmd/*.h cmd/*.c files/*.h files/*.c -lpthread main.c
    if %ERRORLEVEL% NEQ 0 (
        goto :DONE
    )
    goto :RUN

:RUN
    cls
    mini_wcat.exe
    goto :DONE

:DONE
    pause
