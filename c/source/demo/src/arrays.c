/***************************************************************************************************************
 * @auth            : duongdh                                                                                  
 * @day             : 28-dec-2021 
 * @file            : arrays.c                                                                         
 * @dissaption      : File to create FW-Core . Coding in free time                                              
***************************************************************************************************************/

/* Public macros ---------------------------------------------------------------------------------*/
/* Include ---------------------------------------------------------------------------------------*/

#include "../inc/debug.h"

/* Define ----------------------------------------------------------------------------------------*/

#if (GD_ARRAY == DBG_ON)
		#define		OPEN		1
#endif
#if (GD_ARRAY == DBG_OFF)
		#define 	OPEN 		0
#endif
/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------------*/
/* Public function prototypes --------------------------------------------------------------------*/

double getAverage(int *arr) {

		int i;
		double avg;
		double sum = 0;
		int size = sizeof(arr);

		for (i = 0; i < size; ++i) {
				sum += arr[i];
		}

		avg = sum / size;

		return avg;
}

/* function to generate and return random numbers */
int * getRandom( ) {

		static int  r[10];
		int i;

		/* set the seed */
		srand( (unsigned)time( NULL ) );
		
		for ( i = 0; i < 10; ++i) {
				r[i] = rand();
				printf( "r[%d] = %d\n", i, r[i]);
		}

		return r;
}

void mutil_dimensional()
{
#if OPEN

		DGB_LOG(GD_ARRAY, __FUNCTION__, (": Multi dimensional .. \n"));

		/* an array with 5 rows and 2 columns*/
		int a[5][2] = { {0,0}, {1,2}, {2,4}, {3,6},{4,8}};
		int i, j;
	
		/* output each array element's value */
		for ( i = 0; i < 5; i++ ) {

				for ( j = 0; j < 2; j++ ) {
					printf("a[%d][%d] = %d\n", i,j, a[i][j] );
				}
		}

#endif
		return;
}

void passing_array_to_function()
{
#if OPEN

		DGB_LOG(GD_ARRAY, __FUNCTION__, (": passing array to function ... \n"));
		/* an int array with 5 elements */
		int balance[5] = {1000, 2, 3, 17, 50};
		double avg;

		/* pass pointer to the array as an argument */
		avg = getAverage( balance ) ;
	
		/* output the returned value */
		printf( "Average value is: %f \n ", avg );

#endif
		return;
}

void return_array_form_a_function()
{
#if OPEN

		DGB_LOG(GD_ARRAY, __FUNCTION__, (": return array form a function .. \n"));

		int *p;
		int i;

		p = getRandom();

		for ( i = 0; i < 10; i++ ) {
				printf( "*(p + %d) : %d\n", i, *(p + i));
		}

#endif

		return;
}

void poiter_return_array()
{
#if OPEN
		
		DGB_LOG(GD_ARRAY, __FUNCTION__, (": poiter return array .. \n"));

		/* an array with 5 elements */
		double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
		double *p;
		int i;

		p = balance;
	
		/* output each array element's value */
		printf( "Array values using pointer\n");
		
		for ( i = 0; i < 5; i++ ) {
				printf("*(p + %d) : %f\n",  i, *(p + i) );
		}

		printf( "Array values using balance as address\n");
		
		for ( i = 0; i < 5; i++ ) {
				printf("*(balance + %d) : %f\n",  i, *(balance + i) );
		}
		
#endif
		return;
}

/* END OF FILE ************************************************************************************/
