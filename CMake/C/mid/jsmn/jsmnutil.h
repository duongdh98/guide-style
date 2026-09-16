/**
  **************************************************************************************************
  * @file   
  * @author 
  * @date   
  * @brief  
  *         
  **************************************************************************************************
  */

/*  Indent using spaces
    Tab width: 4 spaces
    Line width: 100 characters
    Line ending: LF (0x0A) */

#ifndef _JSMN_UTIL_H
#define _JSMN_UTIL_H

#ifdef __cplusplus
extern "C" {
#endif

/* Public macros ---------------------------------------------------------------------------------*/
	

/* Public data types -----------------------------------------------------------------------------*/
/**
  *
  */
typedef struct 
{
    const char* p_content;
    const jsmntok_t* p_key;
    const jsmntok_t* p_value;
    char* p_json;
    void* p_data;
 
} jsmn_value_proc_param_t;


typedef void (*pf_value_proc_t)(jsmn_value_proc_param_t* p_param);

typedef struct 
{
    const char* p_key_match;
    pf_value_proc_t pf_proc;
} jsmn_value_proc_t;

/**
  *
  */

/* Public function prototypes --------------------------------------------------------------------*/

void jsmn_process_value(jsmn_value_proc_param_t* p_param, const jsmn_value_proc_t* p_proc, uint32_t num_proc);

uint32_t jsmn_tree_num(const jsmntok_t* p_tok_arr);

uint32_t jsmn_tok_match_wild(const jsmntok_t* token, const char* p_wild_str, const uint8_t* p_json);


#ifdef __cplusplus
}
#endif

#endif /* _JSMN_UTIL_H */

/* END OF FILE ************************************************************************************/
