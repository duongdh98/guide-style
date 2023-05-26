/***************************************************************************************************************
 * @detail          : Softmware wirite in free time and write for white cat
 * @auth            : duonghd                                                        
 * @day             : 11-may-2023
 * @file            : main.c                                              
 * @dissaption      : File to create white cat project . Coding in free time                                              
***************************************************************************************************************/

/*  Indent using spaces
    Tab width: 4 spaces
    Line width: 100 characters
    Line ending: LF (0x0A) */

/* Public macros ---------------------------------------------------------------------------------*/
/* Include ---------------------------------------------------------------------------------------*/
#include "cmd/cmd.h"
#include "common/defines.h"
#include "common/vn_en.h"
#include "files/files.h"

/* Define ----------------------------------------------------------------------------------------*/
/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------------*/
/* Public function prototypes --------------------------------------------------------------------*/

int main(int argc, char *argv[])
{
    prj_t ret;
    ret = PRJ_WHITE_CAT;

    switch (ret)
    {
    case PRJ_NONE:
    {

    }
        break;
    case PRJ_WHITE_CAT:
    {
        printf("%s\n\n", DISPLAY_START);
        printf("\n%s", DISPLAY_END);
    }
        break;

    default:
        break;
    }
    while(true) {}
    return 0;
}

/* END OF FILE ************************************************************************************/