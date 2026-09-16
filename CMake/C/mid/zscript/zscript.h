/**
  **************************************************************************************************
  * @file   zscript.h
  * @brief  Starting point of this project.
  * @by     duonghd | 27-July-2024.
  **************************************************************************************************
  */

/*  Indent using spaces
    Tab width: 4 spaces
    Line width: 100 characters
    Line ending: LF (0x0A) */

#ifndef ZSCRIPT_H
#define ZSCRIPT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/* Public macros ---------------------------------------------------------------------------------*/

/* Public data types -----------------------------------------------------------------------------*/

/**
    zjtype_t	    Token này thuộc loại JSON gì
    zvar_type_t 	Biến script thuộc loại gì
    zvar_t	        Một biến runtime
    zvar_list_t	    Danh sách các biến
    zcb_t	        Mô tả callback
    zjtok_t	        Một node/token trong cây script
    zscript_cb_param_t	Tham số truyền cho callback
    zscript_cb_map_t	Mapping tên key → callback
  */

typedef enum {
	ZJ_VAR = 0,
	ZJ_STRING,
	ZJ_INTEGER,
	ZJ_FLOAT,
	ZJ_NULL,
	ZJ_BOOL,
	ZJ_ARRAY,
	ZJ_OBJECT,
	ZJ_CB = '@'
} zjtype_t;



typedef enum {
	ZVAR_STRING = '$',	
	ZVAR_INT = '#',
	ZVAR_FLOAT = '%',
	ZVAR_SET = '&', 
	ZVAR_BYTE = '^'
} zvar_type_t;



typedef struct zvar_t zvar_t;

typedef float (*zcb_float_t)(void); // poiter to function and run funtion
typedef int32_t (*zcb_int_t)(void);
typedef void (*zcb_string_t)(char* p_data, uint32_t len);

typedef struct
{
	const char* p_name;
	zcb_float_t fp_float;
	zcb_int_t fp_int;
	zcb_string_t fp_string;
	uint32_t slen;
} zcb_t;

struct  zvar_t
{
	zvar_type_t type;
	char* p_name;
	union {
		float f;
		int32_t i;
		uint32_t size; // num of element in case of ZVAR_SET
	} value;
	struct {
		char* p_data;
		uint32_t len;
	} string;
	struct {
		uint8_t* p_data;
		uint32_t len;
	} byte;
	zvar_t* p_next;
};


typedef struct
{
	zvar_t* p_head;
	zvar_t* p_tail;
} zvar_list_t;

typedef struct zjtok_t zjtok_t;

struct  zjtok_t
{
	zjtype_t type;
	uint32_t num_child;
	uint32_t len;
	union{
		char* p_cstr;
		uint32_t tree_size;
		zvar_t* p_var;
		const zcb_t* p_cb;
	} value;
};

typedef struct
{
    zjtok_t* p_key;
    zjtok_t* p_value;
    void* p_cb_data;
	uint32_t b_stop;
} zscript_cb_param_t;


typedef void (*pf_zscript_cb_t)(zscript_cb_param_t* p_param);

typedef struct
{
    const char* p_key_match;
    pf_zscript_cb_t pf_cb;
} zscript_cb_map_t;

/* Public function prototypes --------------------------------------------------------------------*/

void zscript_open(zjtok_t** pp_zscript, const char* p_json);

#ifdef __cplusplus
}
#endif

#endif /* ZSCRIPT_H */

/* END OF FILE ************************************************************************************/