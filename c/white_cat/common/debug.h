/***************************************************************************************************************
 * @detail          : Softmware wirite in free time and write for white cat
 * @auth            : duonghd                                                        
 * @day             : 29-may-2023
 * @file            : debug.c                                              
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
#define DBG          0x00

#define DBG_ON       0x80
#define DBG_OFF      0x00

#if defined (DBG)
/* If "dbg", then print "msg". */
#define   DBG_LOG(dbg, msg)                             \
    do                                                  \
    {                                                   \
        if ((dbg) & DBG_ON)                             \
        {                                               \
            v_printf_log msg;                           \
        }                                               \
    } while (0);

#else   /* DBG */
#define   DBG(dbg, msg)
#endif  /* DEG */

#if defined (ERR) || defined (DBG)

    /* Enable or disable printing (error and debug) messages in each module. */
    /* Hardware */
    #define GD_MAIN_WCAT                    DBG_ON      /* DBG_ON or DBG_OFF */

#endif /* defined(ERR) || defined(DBG) */

/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/

typedef enum {
    WERR_OK,
    WERR_PATH_NOT_FOUND
} wcat_err_t;

/* Private function prototypes -------------------------------------------------------------------*/
/* Public function prototypes --------------------------------------------------------------------*/
void v_printf_log(const char* fmt, ...);
void printf_err(wcat_err_t err);

/* END OF FILE ************************************************************************************/