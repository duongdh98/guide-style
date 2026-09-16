/**
  **************************************************************************************************
  * @file   zscript.c
  * @brief  Starting point of this project.
  * @by     duonghd | 27-July-2024.
  **************************************************************************************************
  */

/*  Indent using spaces
    Tab width: 4 spaces
    Line width: 100 characters
    Line ending: LF (0x0A) */

/* Includes --------------------------------------------------------------------------------------*/

#include "logger.h"

#include "jsmn.h"
#include "jsmnutil.h"
#include "zscript.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

/* Private macros --------------------------------------------------------------------------------*/

#define ZSCRIPT_MAX_TOKEN 1400

/* Private data types ----------------------------------------------------------------------------*/

/* Private variables ----------------------------------------------------------------------------*/

/* Private function prototypes -------------------------------------------------------------------*/

/* Public function bodies ------------------------------------------------------------------------*/

void zscript_open(zjtok_t** pp_zscript, const char* p_json)
{
    jsmn_parser parser;
    jsmntok_t tokens[ZSCRIPT_MAX_TOKEN];

    zjtok_t* p_zscript = NULL;
    int num_tokens;
    uint32_t i;
    
    /*
     * Step 1:
     * Initialize JSMN parser.
     */
    jsmn_init(&parser);
    DBG_INFO("%s: jsmn_parser pos: %d,  tokennext: %d, tokenSuper: %d \n", __FUNCTION__, parser.pos, parser.toknext, parser.toksuper);

    /*
     * Step 2:
     * Parse JSON.
     *
     * Example:
     * {"name":"duonghd","count":100}
     */
    num_tokens = jsmn_parse(&parser, p_json, strlen(p_json), tokens, ZSCRIPT_MAX_TOKEN);
    DBG_INFO("%s: Number of tokens : %d ", __FUNCTION__, num_tokens);

    for(i = 0; i < num_tokens; i++)
    {
        DBG_INFO("%s: tokens [ %d ] type :%d \n", __FUNCTION__, i, tokens[i].type);
        DBG_INFO("%s: tokens [ %d ] start :%d \n", __FUNCTION__, i, tokens[i].start);
        DBG_INFO("%s: tokens [ %d ] size :%d \n", __FUNCTION__, i, tokens[i].size);
        DBG_INFO("%s: tokens [ %d ] end :%d \n", __FUNCTION__, i, tokens[i].end);
        DBG_INFO("======================================================\n");
    }
    /*
     * Step 3:
     * Allocate zjtok_t array.
     *
     * For our JSON:
     *
     * tokens[0] = OBJECT
     * tokens[1] = "name"
     * tokens[2] = "duonghd"
     * tokens[3] = "count"
     * tokens[4] = 100
     *
     * => 5 zjtok_t
     */

    p_zscript = malloc((size_t)num_tokens * sizeof(zjtok_t));

    /*
     * Step 4:
     * Initialize zjtok_t array.
     */
    for (i = 0U; i < (uint32_t)num_tokens; i++)
    {
        p_zscript[i].type = ZJ_NULL;
        p_zscript[i].num_child = 0U;
        p_zscript[i].len = 0U;
        p_zscript[i].value.p_cstr = NULL;
    }

    /*
     * Step 5:
     * Convert JSMN tokens -> ZScript tokens.
     */
    for (i = 0U; i < (uint32_t)num_tokens; i++)
    {
        const jsmntok_t* p_tok = &tokens[i];

        switch (p_tok->type)
        {
            case JSMN_OBJECT:
            {
                p_zscript[i].type = ZJ_OBJECT;
                p_zscript[i].num_child = (uint32_t)p_tok->size;
                p_zscript[i].len = (uint32_t)(p_tok->end - p_tok->start);

                DBG_INFO("%s: tokens type      : ZJ_OBJECT\n", __FUNCTION__);
                DBG_INFO("%s: tokens [ %d ] num_child : %d \n", __FUNCTION__, i, p_zscript[i].num_child);
                DBG_INFO("%s: tokens [ %d ] size      : %d \n", __FUNCTION__, i, p_zscript[i].len);
                DBG_INFO("======================================================\n");

                break;
            }

            case JSMN_ARRAY:
            {
                p_zscript[i].type = ZJ_ARRAY;
                p_zscript[i].num_child = (uint32_t)p_tok->size;
                p_zscript[i].len = (uint32_t)(p_tok->end - p_tok->start);

                DBG_INFO("%s: tokens type      : ZJ_ARRAY\n", __FUNCTION__);
                DBG_INFO("%s: tokens [ %d ] num_child : %d \n", __FUNCTION__, i, p_zscript[i].num_child);
                DBG_INFO("%s: tokens [ %d ] size      : %d \n", __FUNCTION__, i, p_zscript[i].len);
                DBG_INFO("======================================================\n");

                break;
            }

            case JSMN_STRING:
            {
                p_zscript[i].type = ZJ_STRING;
                p_zscript[i].len = (uint32_t)(p_tok->end - p_tok->start);
                p_zscript[i].value.p_cstr = (char*)(p_json + p_tok->start);

                DBG_INFO("%s: token type       : ZJ_STRING\n", __FUNCTION__);
                DBG_INFO("%s: token [ %d ] len  : %lu\n", __FUNCTION__, i, (unsigned long)p_zscript[i].len);
                DBG_INFO("%s: token [ %d ] value: %.*s\n", __FUNCTION__, i, (int)p_zscript[i].len, p_zscript[i].value.p_cstr);

                break;
            }

            case JSMN_PRIMITIVE:
            {
                /*
                 * For this simple example,
                 * primitive "100" is treated as integer.
                 */
                p_zscript[i].type = ZJ_INTEGER;
                p_zscript[i].len = (uint32_t)(p_tok->end - p_tok->start);

                /*
                 * p_cstr points to "100" inside p_json.
                 */
                p_zscript[i].value.p_cstr = (char*)(p_json + p_tok->start);

                DBG_INFO("%s: tokens type      : ZJ_INTEGER\n", __FUNCTION__);
                DBG_INFO("%s: tokens [ %d ] len : %d \n", __FUNCTION__, i, p_zscript[i].len);
                DBG_INFO("%s: tokens [ %d ] value      : %.*s \n", __FUNCTION__, p_zscript[i].len, p_zscript[i].value.p_cstr);
                DBG_INFO("======================================================\n");

                break;
            }

            default:
            {
                p_zscript[i].type = ZJ_NULL;
                break;
            }
        }
    }

    /*
     * Step 6:
     * Return allocated zjtok_t array to caller.
     */
    *pp_zscript = p_zscript;
}

/* Private function bodies -----------------------------------------------------------------------*/

/* END OF FILE ************************************************************************************/