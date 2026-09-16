/**
  **************************************************************************************************
  * @file   
  * @author 
  * @date   
  * @brief  
  **************************************************************************************************
  */

/*  Indent using spaces
    Tab width: 4 spaces
    Line width: 100 characters
    Line ending: LF (0x0A) */

/* Includes --------------------------------------------------------------------------------------*/

#include <stdint.h>
#include "jsmn.h"
#include "jsmnutil.h"

/* Private macros --------------------------------------------------------------------------------*/
/**
  * @cond
  */

/**
  * @endcond
  */

/* Private data types ----------------------------------------------------------------------------*/
/**
  * @cond
  */

/**
  * @endcond
  */

/* Private variables -----------------------------------------------------------------------------*/
/**
  * @cond
  */

/**
  * @endcond
  */

/* Private function prototypes -------------------------------------------------------------------*/

/* Public function bodies ------------------------------------------------------------------------*/

/**
  * @brief      get bumbet
  * @param [in] p_tok_arr : pointer to the array of jsmn tokens     
  * @param [in, out] num_tokens : 
           [in] : length of the array; 
           [out]: numbers of tree nodes, including root
  * @retval     err code 
  */

uint32_t jsmn_tree_num(const jsmntok_t* p_tok_arr)
{
  
    uint32_t remain_tok;
    uint32_t num_tokens;

    const jsmntok_t* p_tok;


    p_tok = p_tok_arr;
    num_tokens = 1;
    remain_tok = 1;

    do 
    {
        remain_tok--;
        num_tokens += p_tok->size;
        remain_tok += p_tok->size;
        p_tok++;
        
    } while (remain_tok>0);

    return num_tokens; 
}

uint32_t jsmn_tok_match_wild(const jsmntok_t* p_token, const char* p_wild_str, const uint8_t* p_json)
{
    uint32_t b_match;
    const char *p_tame;
    const char *p_wild;
    const char *p_tame_end;
	
    char tame, wild;
	b_match = 0;

    if (p_token->type==JSMN_STRING)
    {
        p_tame = (char*)p_json + p_token->start;
        p_tame_end = (char*)p_json + p_token->end;
        p_wild = p_wild_str;
        b_match = 1;
                
        for(;;)
        {
            tame = *p_tame;
            wild = *p_wild;

            if ( (*p_wild=='*') && (*(p_wild+1)==0) ) // ky tu * o cuoi, match
                break;
            
            if (*p_wild==0) // ket thuc wild text
            {
                if (p_tame<=p_tame_end)
                {
                    b_match = 0; // not match
                }
            }

            switch(wild)
            {
                case '*':
                {
                    if (*(p_wild+1)==tame) // so sanh voi ky tu sau dau *
                    {
                        p_wild+=2;
                    }
                    p_tame++;
                }
                break;
                
                case '?':
                {
                    p_wild++;
                    p_tame++;
                }
                break;

                default:
                {
                    if (tame!=wild)
                    {
                        b_match = 0;
                    }
                        
                    p_tame++;
                    p_wild++;        
                }
                break;
            }

            if (!b_match) //not match
                break;

            if (p_tame>p_tame_end) // ket thuc text
            {
                if (*p_wild!=0)
                {
                    b_match = 0; // not match
                }
                break;
            }                 
       }
    }
    return b_match;
}

void jsmn_process_value(jsmn_value_proc_param_t* p_param, const jsmn_value_proc_t* p_proc, uint32_t num_proc)
{
    const jsmntok_t* p_tok;
    const jsmntok_t* p_value = p_param->p_value;
    const char* p_json;

    uint32_t i_proc;
    uint32_t b_key_match;
    uint32_t num_tok_skip;
    uint32_t num_remain_tok;

    if (p_value->type==JSMN_OBJECT)
    {
        p_tok = p_value + 1;
        num_remain_tok = p_value->size; // remain tokens should be always even

        while (num_remain_tok>0)
        {

            i_proc = 0;
            num_tok_skip = 0;
            for (i_proc=0; i_proc<num_proc; i_proc++)
            {
                b_key_match = jsmn_tok_match_wild(p_tok, p_proc[i_proc].p_key_match, p_json);
                if (b_key_match)
                    break;
            }

            if (b_key_match)
            {
                p_param->p_key = p_tok;
                p_param->p_value = p_tok+1;
                p_proc[i_proc].pf_proc(p_param);
                num_tok_skip = jsmn_tree_num(p_tok+1);
                p_tok+=num_tok_skip;
            }

            p_tok++;

            num_remain_tok-=2; // e

        }
    }

}





/* Private function bodies -----------------------------------------------------------------------*/



/* END OF FILE ************************************************************************************/
