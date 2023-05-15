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
#include "thread/n_thread.h"

/* Define ----------------------------------------------------------------------------------------*/
/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------------*/
/* Public function prototypes --------------------------------------------------------------------*/

int main(int argc, char *argv[])
{
    thread_common_create();

    int i;
    while(true) {
        i++;
        printf("loop : %d \n", i);
        delay_ms(1000);
        if (i == 7) {
            should_terminate = true;
        }
    }
    while(true) {}
    return 0;
}

/* END OF FILE ************************************************************************************/