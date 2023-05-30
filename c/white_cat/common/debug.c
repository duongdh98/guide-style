/***************************************************************************************************************
 * @detail          : Softmware wirite in free time and write for white cat
 * @auth            : duonghd                                                        
 * @day             : 29-may-2023
 * @file            : debug.h                                              
 * @dissaption      : File to create white cat project . Coding in free time                                              
***************************************************************************************************************/

/*  Indent using spaces
    Tab width: 4 spaces
    Line width: 100 characters
    Line ending: LF (0x0A) */

/* Public macros ---------------------------------------------------------------------------------*/
/* Include ---------------------------------------------------------------------------------------*/
#include "debug.h"
#include "vn_en.h"
#include "defines.h"
/* Define ----------------------------------------------------------------------------------------*/
#define MAX_BUFFER 254

/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------------*/
/* Public function prototypes --------------------------------------------------------------------*/
void v_printf_log(const char* fmt, ...) {
    
    va_list args;
    char buffer[MAX_BUFFER];
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    printf("%s", buffer);
}

void printf_err(wcat_err_t err) {
    switch (err)
    {
    case WERR_PATH_NOT_FOUND:
        printf("%s", ERR_1);
        break;
    
    default:
        break;
    }
}
/* END OF FILE ************************************************************************************/