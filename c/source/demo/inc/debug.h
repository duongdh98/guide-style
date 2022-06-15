/***************************************************************************************************************
 * @auth            : duongdh                                                                                  
 * @day             : 28-dec-2021 
 * @file            : debug.h                                                                           
 * @dissaption      : File to create FW-Core . Coding in free time                                              
***************************************************************************************************************/

#ifndef _DEBUG_H
#define _DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif

/* Public macros ---------------------------------------------------------------------------------*/
/* Include ---------------------------------------------------------------------------------------*/

/* C standard library. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdarg.h>
#include <limits.h>
#include <float.h>
#include <math.h>

/* Define ----------------------------------------------------------------------------------------*/

#define DBG_ON       0x80
#define DBG_OFF      0x00

#if defined (DEBUG)
		#define		DBG						0u
#else
		#define 	DBG						1u
#endif
#if !DBG
		#undef		DBG
#endif

#define		DGB_LOG(dbg, func, msg)						\
		do																			\
		{																				\
				if ((dbg) && DBG_ON)								\
				{																		\
						printf(func);										\
						printf(msg);										\
				}																		\
		} while (0);

#if defined (DBG)
		/* Enable or disable printing debug) messages in each module */
		#define GD_APP					DBG_ON
		#define GD_DATA_TYPE		DBG_OFF
		#define GD_LOOP					DBG_OFF
		#define GD_FUNCTIONS		DBG_OFF
		#define GD_SCOPE				DBG_OFF
		#define GD_ARRAY				DBG_ON
		#define GD_POINTER		  DBG_OFF

#endif

/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------------*/
/* Public function prototypes --------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* _DEBUG_H */

/* END OF FILE ************************************************************************************/