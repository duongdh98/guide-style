/***************************************************************************************************************
 * @detail          : Softmware wirite in free time and write for white cat
 * @auth            : duonghd                                                        
 * @day             : 25-may-2023
 * @file            : files.c                                           
 * @dissaption      : File to create white cat project . Coding in free time                                              
***************************************************************************************************************/

/*  Indent using spaces
    Tab width: 4 spaces
    Line width: 100 characters
    Line ending: LF (0x0A) */

/* Public macros ---------------------------------------------------------------------------------*/
/* Include ---------------------------------------------------------------------------------------*/
#include "files.h"

/* Define ----------------------------------------------------------------------------------------*/
/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------------*/
/* Public function prototypes --------------------------------------------------------------------*/
wcat_err_t path_dir_exit(char *path) {
    
    wcat_err_t ret = WERR_OK;
    DIR* dir = opendir(path);
    if (dir) {
        ret = WERR_OK;
        closedir(dir);
    } else {
        ret = WERR_PATH_NOT_FOUND;
    }
    return ret;
}

wcat_err_t path_file_exit(char *path) {
    
    wcat_err_t ret = WERR_OK;
    FILE *fptr = fopen(path, "r");
    if (fptr == NULL) {
        ret = WERR_PATH_NOT_FOUND;
    } else {
        ret = WERR_OK;
        fclose(fptr);
    }
    return ret;
}

/* END OF FILE ************************************************************************************/