/***************************************************************************************************************
 * @detail          : Softmware wirite in free time and write for white cat
 * @auth            : duonghd                                                        
 * @day             : 12-may-2023
 * @file            : cmd.h                                           
 * @dissaption      : File to create white cat project . Coding in free time                                              
***************************************************************************************************************/

/*  Indent using spaces
    Tab width: 4 spaces
    Line width: 100 characters
    Line ending: LF (0x0A) */

/* Public macros ---------------------------------------------------------------------------------*/
/* Include ---------------------------------------------------------------------------------------*/
#include "../common/cfg.h"

/* Define ----------------------------------------------------------------------------------------*/
/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------------*/
/* Public function prototypes --------------------------------------------------------------------*/

/* === deflay function ===*/
void delay_ms(int time);

/* === create folder === */
void cmd_create_folder(char *path);

/* === create file === */
void cmd_create_file(char *path);

/* === delete folder/file === */
void cmd_delete_folder(char *path);

/* === delete folder/file === */
void cmd_delete_file(char *path);

void run_python(char *path);

/* END OF FILE ************************************************************************************/