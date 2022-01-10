/***************************************************************************************************************
 * @auth            : duongdh                                                                                  
 * @day             : 28-dec-2021 
 * @file            : data_type.c                                                                            
 * @dissaption      : File to create FW-Core . Coding in free time                                              
***************************************************************************************************************/

/* Public macros ---------------------------------------------------------------------------------*/
/* Include ---------------------------------------------------------------------------------------*/

#include "../inc/debug.h"

/* Define ----------------------------------------------------------------------------------------*/

#if (GD_DATA_TYPE == DBG_ON)
		#define OPEN 		1
#endif
#if (GD_DATA_TYPE == DBG_OFF)
		#define OPEN 		0
#endif 

/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------------*/
/* Public function prototypes --------------------------------------------------------------------*/

void size_data_type()
{
#if OPEN

		DGB_LOG(GD_DATA_TYPE, __FUNCTION__, (": Interger type ... \n"));
		printf("CHAR_BIT    :   %d\n", CHAR_BIT);
		printf("CHAR_MAX    :   %d\n", CHAR_MAX);
		printf("CHAR_MIN    :   %d\n", CHAR_MIN);
		printf("INT_MAX     :   %d\n", INT_MAX);
		printf("INT_MIN     :   %d\n", INT_MIN);
		printf("LONG_MAX    :   %ld\n", (long) LONG_MAX);
		printf("LONG_MIN    :   %ld\n", (long) LONG_MIN);
		printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
		printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
		printf("SHRT_MAX    :   %d\n", SHRT_MAX);
		printf("SHRT_MIN    :   %d\n", SHRT_MIN);
		printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
		printf("UINT_MAX    :   %u\n", (unsigned int) UINT_MAX);
		printf("ULONG_MAX   :   %lu\n", (unsigned long) ULONG_MAX);
		printf("USHRT_MAX   :   %d\n", (unsigned short) USHRT_MAX);	

		DGB_LOG(GD_DATA_TYPE, __FUNCTION__, (": Float type ... \n"));

		printf("Storage size for float : %d \n", sizeof(float));
		printf("FLT_MAX     :   %g\n", (float) FLT_MAX);
		printf("FLT_MIN     :   %g\n", (float) FLT_MIN);
		printf("-FLT_MAX    :   %g\n", (float) -FLT_MAX);
		printf("-FLT_MIN    :   %g\n", (float) -FLT_MIN);
		printf("DBL_MAX     :   %g\n", (double) DBL_MAX);
		printf("DBL_MIN     :   %g\n", (double) DBL_MIN);
		printf("-DBL_MAX     :  %g\n", (double) -DBL_MAX);
		printf("Precision value: %d\n", FLT_DIG );
		
		return;
#endif
}

/* END OF FILE ************************************************************************************/