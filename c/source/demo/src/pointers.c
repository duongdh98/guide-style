/***************************************************************************************************************
 * @auth            : duongdh                                                                                  
 * @day             : 28-dec-2021 
 * @file            : pointers.c                                                                           
 * @dissaption      : File to create FW-Core . Coding in free time                                              
***************************************************************************************************************/

/* Public macros ---------------------------------------------------------------------------------*/
/* Include ---------------------------------------------------------------------------------------*/

#include "../inc/debug.h"

/* Define ----------------------------------------------------------------------------------------*/

#if (GD_POINTER == DBG_ON)
		#define 	OPEN		1
#endif
#if (GD_POINTER == DBG_OFF)
		#define 	OPEN 		0
#endif

/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------------*/
/* Public function prototypes --------------------------------------------------------------------*/

void pointer_arithmetic()
{
#if OPEN

		DGB_LOG(GD_POINTER, __FUNCTION__, (": pointer arithmetic ... \n"));

		const int MAX = 3;
		int  var[] = {10, 100, 200};
		int  i, *ptr;
		int *pc, c;
    
    c = 5;
    printf("Address of c (&c) %p: \n", &c);
    printf("Value of c (c): %d \n", c);

    pc = &c;    // con trỏ pc chứa địa chỉ ô nhớ của biến c
    printf("Address that pointer pc holds (pc): %p \n", pc);
    printf("Content of the address pointer pc holds (*pc): %d \n", *pc);
    
    c = 11;    // Giá trị chứa trong địa chỉ vùng nhớ &c được chuyển từ 5 thành 11.
    printf("Address pointer pc holds (pc): %p \n", pc);
    printf("Content of the address pointer pc holds (*pc): %d \n", *pc);

    *pc = 2; 
    printf("Address of c (&c): %p \n ", &c);
    printf("Value of c (c): %d \n ", c );

		/* let us have array address in pointer */
		ptr = &var;
		
		for ( i = 0; i < MAX; i++) {

				printf("Address of var[%d] = %x\n", i, ptr );
				printf("Value of var[%d] = %d\n", i, *ptr );

				/* move to the next location */
				ptr++;
		}

#endif

		return;
}

void array_of_pointer()
{
#if OPEN
#endif

		return;
}

void pointer_to_pointer()
{
#if OPEN
#endif

		return;
}

void passing_pointer_to_function_in_c()
{
#if OPEN
#endif

		return;
}

void return_pointer_from_function_in_c()
{
#if OPEN
#endif

		return;
}

/* END OF FILE ************************************************************************************/
