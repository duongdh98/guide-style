/***************************************************************************************************************
 * @detail          : Softmware wirite in free time and write for white cat
 * @auth            : duonghd                                                        
 * @day             : 12-may-2023
 * @file            : n_thread.c                                           
 * @dissaption      : File to create white cat project . Coding in free time                                              
***************************************************************************************************************/

/*  Indent using spaces
    Tab width: 4 spaces
    Line width: 100 characters
    Line ending: LF (0x0A) */

/* Public macros ---------------------------------------------------------------------------------*/
/* Include ---------------------------------------------------------------------------------------*/
#include "n_thread.h"
#include "../cmd/cmd.h"

/* Define ----------------------------------------------------------------------------------------*/
/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------------*/
/* Public function prototypes --------------------------------------------------------------------*/

/* === Common thread ==================== */
void *thread_common(common_t *g_common) {
    
    for(;;) {
        printf("Common thread running ...\n");
        delay_ms(500);
    }
}

void thread_common_create() {
    common_t g_cm;
    g_cm.val_common = 7;
    strcpy(g_cm.str_common, "Dai Duong");

    int ret = pthread_create(&t_common, NULL, &thread_common, (common_t *)&g_cm);
    if (ret != 0) {
        printf("Could not create common thread ... \n");
    }
}
/* END OF FILE ************************************************************************************/