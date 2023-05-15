/***************************************************************************************************************
 * @detail          : Softmware wirite in free time and write for white cat
 * @auth            : duonghd                                                        
 * @day             : 15-may-2023
 * @file            : common.h                                      
 * @dissaption      : File to create white cat project . Coding in free time                                              
***************************************************************************************************************/

/*  Indent using spaces
    Tab width: 4 spaces
    Line width: 100 characters
    Line ending: LF (0x0A) */

/* Public macros ---------------------------------------------------------------------------------*/
/* Include ---------------------------------------------------------------------------------------*/
#include "cfg.h"

/* Define ----------------------------------------------------------------------------------------*/
#define MAX_COMMON_CHAR     100

/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/
typedef struct {
    int val_common;
    char str_common[MAX_COMMON_CHAR];
} common_t;

/* Private function prototypes -------------------------------------------------------------------*/
/* Public function prototypes --------------------------------------------------------------------*/
void thread_common_func(common_t *g_common);

/* END OF FILE ************************************************************************************/