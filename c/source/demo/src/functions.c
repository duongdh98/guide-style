/***************************************************************************************************************
 * @auth            : duongdh                                                                                  
 * @day             : 28-dec-2021 
 * @file            : functions.c                                                                         
 * @dissaption      : File to create FW-Core . Coding in free time                                              
***************************************************************************************************************/

/* Public macros ---------------------------------------------------------------------------------*/
/* Include ---------------------------------------------------------------------------------------*/

#include "../inc/debug.h"

/* Define ----------------------------------------------------------------------------------------*/

#if (GD_FUNCTIONS == DBG_ON)
		#define		OPEN		1
#endif
#if (GD_FUNCTIONS == DBG_OFF)
		#define		OPEN		0
#endif

/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------------*/

int max(int num1, int num2)
{
		/* local variable declaration */
		int result;
	
		if (num1 > num2)
				result = num1;
		else
				result = num2;
	
		return result; 
}

void swap_call_by_value(int x, int y)
{
		int temp;

		temp = x;
		x = y;
		y = temp;

		return;
}


void swap_by_refer(int *x, int *y)
{
		int temp;
		temp = *x;
		*x = *y;
		*y = temp;

		return;
}

/* Public function prototypes --------------------------------------------------------------------*/

void call_a_function()
{
#if OPEN

		DGB_LOG(GD_FUNCTIONS, __FUNCTION__, (": Call a function .. \n"));
		/* local variable definition */
		int a = 100;
		int b = 200;
		int ret;
	
		/* calling a function to get max value */
		ret = max(a, b);
	
		printf( "Max value is : %d\n", ret );
#endif

		return;
}

void call_by_value()
{
#if OPEN

		DGB_LOG(GD_FUNCTIONS, __FUNCTION__, (": Call by value .. \n"));
		/* local variable definition */
		int a = 100;
		int b = 200;
	
		printf("Before swap, value of a : %d\n", a );
		printf("Before swap, value of b : %d\n", b );
	
		/* calling a function to swap the values */
		swap_call_by_value(a, b);
	
		printf("After swap, value of a : %d\n", a );
		printf("After swap, value of b : %d\n", b );

#endif
}

void call_by_refer()
{
		DGB_LOG(GD_FUNCTIONS, __FUNCTION__, (": Call a refer .. \n"));

		/* local variable definition */
		int a = 100;
		int b = 200;
	
		printf("Before swap, value of a : %d\n", a );
		printf("Before swap, value of b : %d\n", b );
	
		/* calling a function to swap the values */
		swap_by_refer(&a, &b);
	
		printf("After swap, value of a : %d\n", a );
		printf("After swap, value of b : %d\n", b );
	
		return;

}

/* END OF FILE ************************************************************************************/