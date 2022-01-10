/***************************************************************************************************************
 * @auth            : duongdh                                                                                  
 * @day             : 28-dec-2021 
 * @file            : loop.c                                                                           
 * @dissaption      : File to create FW-Core . Coding in free time                                              
***************************************************************************************************************/

/* Public macros ---------------------------------------------------------------------------------*/
/* Include ---------------------------------------------------------------------------------------*/

#include "../inc/debug.h"

/* Define ----------------------------------------------------------------------------------------*/

#if (GD_LOOP == DBG_ON)
		#define 	OPEN		1
#endif
#if (GD_LOOP == DBG_OFF)
		#define 	OPEN		0 
#endif

/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------------*/
/* Public function prototypes --------------------------------------------------------------------*/

void while_loop()
{
#if OPEN
		DGB_LOG(GD_LOOP, __FUNCTION__, (": while loop instance ... \n"));
		/* local variable definition */
    int a = 10;

    /* while loop execution */
    while(a < 100) {
      	printf("value of a: %d\n", a);
      	a++;
    }

#endif
		return;
}

void for_loop()
{
#if OPEN

		DGB_LOG(GD_LOOP, __FUNCTION__, (": for loop instance ... \n"));

		int a = 0;

		/* for loop execution */
		for(; a < 100;){
				printf("value of a: %d\n", a);
				a++;

				if(a == 27) {
						/* terminate the loop using break statement */
						break;
      	}
		}

#endif
		return;
}

void do_while_loop()
{
#if OPEN

		DGB_LOG(GD_LOOP, __FUNCTION__, (": do while loop instance ... \n"));

		/* local variable definition */
		int a = 10;

		/* do loop execution */
		do {
				printf("value of a: %d\n", a);
				a = a + 1;
		}while(0);

#endif
		return;
}

void nested_loop()
{
#if OPEN

		DGB_LOG(GD_LOOP, __FUNCTION__, (": nest loop instance ... \n"));

		/* local variable definition */
		int i, j;
		
		for(i = 2; i < 10; i++) {

				for(j = 2; j <= (i/j); j++) 
				if(!(i%j)) break; // if factor found, not prime
				if(j > (i/j)) printf("%d is prime\n", i);
		}

#endif
		return;
}

/* END OF FILE ************************************************************************************/