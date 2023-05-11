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
    del main.exe > nul
    goto :BUILD

:BUILD
    gcc -o main.exe xlsx_io/include/*.h xlsx_io/lib/*.h xlsx_io/lib/*.c main.c
    goto :RUN

:RUN
    main.exe
    goto :DONE

:DONE
    pause
