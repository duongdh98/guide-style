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
            DBG_LOG(GD_MAIN_WCAT, ("%s\n", DISPLAY_START));
            /* Coding here ============================== */
            char path_wcat_user[50];
            char path_wcat_in[100];
            char path_wcat_formart[100];
            char path_wcat_out[100];
            sprintf(path_wcat_user,"C:/Users/%s/Desktop/ConMeoTrang", getlogin());
            sprintf(path_wcat_in, "%s%s", path_wcat_user, WCAT_INPUT);
            sprintf(path_wcat_formart, "%s%s", path_wcat_user, WCAT_FORMART);
            sprintf(path_wcat_out, "%s%s", path_wcat_user, WCAT_OUTPUT);
            printf("%s\n%s\n%s\n", path_wcat_user, path_wcat_in, path_wcat_out);

            wcat_err_t w_ret = path_dir_exit(path_wcat_user);
            if(w_ret == WERR_OK) {
                
                w_ret = path_dir_exit(path_wcat_formart);
                if (w_ret == WERR_OK) {
                    cmd_delete_path(path_wcat_formart);
                } else {
                    cmd_create_folder(path_wcat_formart);
                }

                w_ret = path_dir_exit(path_wcat_out);
                if (w_ret == WERR_OK) {
                    cmd_delete_path(path_wcat_out);
                } else {
                    cmd_create_folder(path_wcat_out);
                }

                // command parse excel ==
                char formart_excel_cmd[240];
                char parse_excel_cmd[240];
                sprintf(formart_excel_cmd, "%s %s/ex_sheets_data %s", PY_EXCEL_FORMART, path_wcat_in, path_wcat_formart);
                sprintf(parse_excel_cmd, "%s %s %s", PY_EXCEL_PARSE, path_wcat_formart, path_wcat_out);
                printf("%s\n%s\n", formart_excel_cmd, parse_excel_cmd);
                run_python(formart_excel_cmd);
                run_python(parse_excel_cmd);

            } else {
                DBG_LOG(GD_MAIN_WCAT, ("%s", ERR_5))
            }

            /* ============================== end ======= */
            DBG_LOG(GD_MAIN_WCAT, ("%s\n", DISPLAY_END));
        }
            break;

        default:
            break;
    }
    system("pause");
    return 0;
}

/* END OF FILE ************************************************************************************/