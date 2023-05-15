/***************************************************************************************************************
 * @detail          : Softmware wirite in free time and write for white cat
 * @auth            : duonghd                                                        
 * @day             : 12-may-2023
 * @file            : n_thread.h                                             
 * @dissaption      : File to create white cat project . Coding in free time                                              
***************************************************************************************************************/

/*  Indent using spaces
    Tab width: 4 spaces
    Line width: 100 characters
    Line ending: LF (0x0A) */

/* Public macros ---------------------------------------------------------------------------------*/
/* Include ---------------------------------------------------------------------------------------*/
#include <unistd.h>
#include <pthread.h>
#include <sched.h>

#include "../common/common.h"

/* Define ----------------------------------------------------------------------------------------*/
volatile bool should_terminate;
pthread_t t_common;

/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------------*/
/* Public function prototypes --------------------------------------------------------------------*/
void *thread_common(common_t *g_common);
void thread_common_create();

/* END OF FILE ************************************************************************************/