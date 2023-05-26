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
#include "cfg.h"

/* Define ----------------------------------------------------------------------------------------*/
/* Define path python for excels */
#define PY_EXCEL            "python/excels"
#define PY_EXCEL_FORMART    PY_EXCEL "/formart.py"
#define PY_EXCEL_PARSE      PY_EXCEL "/parse.py"

/* Define path python for jsons */
#define PY_JSON             "python/jsons"

/* Define path python for texts */
#define PY_TEXT             "python/texts"

/* Define path python for xmls */
#define PY_xmls             "python/xmls"

/* Public data types -----------------------------------------------------------------------------*/
typedef enum {

    PRJ_NONE,
    PRJ_WHITE_CAT,

} prj_t;

/* END OF FILE ************************************************************************************/