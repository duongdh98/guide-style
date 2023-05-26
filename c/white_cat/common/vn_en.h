/***************************************************************************************************************
 * @detail          : Softmware wirite in free time and write for white cat
 * @auth            : duonghd                                                        
 * @day             : 12-may-2023
 * @file            : vn_en.h                                           
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
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#if 1
    #define EN    1
#endif

#ifdef EN
#define DISPLAY_START   "/=== @ConMeoTrang ===========================================================================/"
#define DISPLAY_END     "/=========================================================================== @ConMeoTrang ===/"
// Define error message =================================
#define ERR_1       "Path is not exit           ..."
#define ERR_2       "Path is exit               ..."
#define ERR_3       "Folder could not create    ..."
#define ERR_4       "Variable not exists / define  ..."
#define ERR_5       "Please create ConMeoTrang folder, put files to input folder and try again !!!!!!!!!"
#define ERR_JSON_1  "Json wrong formart    ..."
#define STATUS_0    "Done !                     ..."
#define STATUS_1    "Finding data               ..."
#define STATUS_2    "Reading data               ..."
#define STATUS_3    "Writing data               ..."
#define STATUS_4    "Deleting date              ..."
#define STATUS_5    "Moving data                ..."
#define STATUS_6    "Renaming data              ..."
#define STATUS_7    "Building source            ..."
#define STATUS_8    "Creating object            ..."
#define STATUS_9    "Clearing old data fomart folder ..."
#define STATUS_10   "Clearing old data oupt folder   ..."
#define STATUS_JSON_1   "Checking json format      ..."
#define STATUS_JSON_2   "Reading json format       ..."
#define STATUS_EXCEL_1  "Formating data             ..."
#define STATUS_EXCEL_2  "Parsing data              ..."
#define STATUS_n        "Excute next step           ..."

#else
#endif


/* END OF FILE ************************************************************************************/