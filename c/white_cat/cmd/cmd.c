/***************************************************************************************************************
 * @detail          : Softmware wirite in free time and write for white cat
 * @auth            : duonghd                                                        
 * @day             : 12-may-2023
 * @file            : cmd.c                                      
 * @dissaption      : File to create white cat project . Coding in free time                                              
***************************************************************************************************************/

/*  Indent using spaces
    Tab width: 4 spaces
    Line width: 100 characters
    Line ending: LF (0x0A) */

/* Public macros ---------------------------------------------------------------------------------*/
/* Include ---------------------------------------------------------------------------------------*/
#include <time.h>
#include "cmd.h"

/* Define ----------------------------------------------------------------------------------------*/
/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------------*/
/* Public function prototypes --------------------------------------------------------------------*/

/* === deflay function ===*/
void delay_ms(int time)
{
    long pause;
    clock_t now,then;

    pause = time * (CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

/* === create folder === */
void cmd_create_folder(char *path) {
    char cmd[200];
    sprintf(cmd, "powershell new-item -path %s -itemType directory >nul", path);
    system(cmd);
}

/* === create file === */
void cmd_create_file(char *path) {

}

/* === delete folder/file === */
void cmd_delete_path(char *path) {
    char cmd[200];
    sprintf(cmd, "powershell remove-item %s/* -recurse >nul", path);
    system(cmd);
}

/* === delete folder/file === */
void cmd_delete_file(char *path) {
    remove(path);
}

void run_python(char *path) {
    char cmd[254];
    sprintf(cmd, "py %s", path);
    system(cmd);
}

/* END OF FILE ************************************************************************************/