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
    if exist "main.exe" (
        del main.exe > nul
    )
    goto :BUILD

:BUILD
    gcc -o main.exe cmd/*.h cmd/*.c common/*.h common/*.c thread/*.h thread/*.c -lpthread main.c
    if %ERRORLEVEL% NEQ 0 (
        goto :DONE
    )
    goto :RUN

:RUN
    cls
    main.exe
    goto :DONE

:DONE
    pause
