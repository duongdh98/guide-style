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
    g++ -o main.exe -I C:\libxl-4.1.2\include_cpp -L C:\libxl-4.1.2\bin main.cpp
    goto :RUN

:RUN
    main.exe
    goto :DONE

:DONE
    pause
