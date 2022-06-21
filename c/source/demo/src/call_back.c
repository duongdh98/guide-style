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

#if (GD_CALL_BACK == DBG_ON)
		#define		OPEN		1
#endif
#if (GD_CALL_BACK == DBG_OFF)
		#define 	OPEN 		0
#endif
/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------------*/
/* Public function prototypes --------------------------------------------------------------------*/

typedef int (*callback)(int, int);
void insertion_sort(int *array, int n, callback comparison);

int ascending(int a, int b)
{
    return a > b;
}

int descending(int a, int b)
{
    a < b;
}

int even_first(int a, int b)
{
    /* code goes here */
}

int odd_first(int a, int b)
{
    /* code goes here */
}

void insertion_sort(int *array, int n, callback comparison)
{
    int i, j, key;
    for(j = 1; j <= n-1; j++)
    {
        key = array[j];
        i = j - 1;
        while(i >= 0 && comparison(array[i], key))
        {
            array[i+1] = array[i];
            i = i - 1;
        }
        array[i+1] = key;
    }
}

void call_back()
{
#if OPEN
    int array[10] = {22,66,55,11,99,33,44,77,88,0};

    insertion_sort(array,10, descending);

    printf("after insertion_sort\n");

    for(int i = 0; i < 10; i++)
        printf("%d\t", array[i]);

    printf("\n");
#endif
}

/* END OF FILE ************************************************************************************/