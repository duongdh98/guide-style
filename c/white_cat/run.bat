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
    gcc -o main.exe inc/*.h src/*.c -lpthread main.c
    goto :RUN

:RUN
    main.exe
    goto :DONE

:DONE
    pause
