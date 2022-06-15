/***************************************************************************************************************
 * @detail          : Firmware wirite in free time and write for Soc nrf5xx
 * @auth            : duongdh                                                                                  
 * @day             : 8-jan-2022 
 * @file            : main.c                                                                            
 * @dissaption      : File to create FW-Core . Coding in free time                                              
***************************************************************************************************************/

/*  Indent using spaces
    Tab width: 4 spaces
    Line width: 100 characters
    Line ending: LF (0x0A) */

/* Public macros ---------------------------------------------------------------------------------*/
/* Include ---------------------------------------------------------------------------------------*/

#include "inc/app.h"
#include "inc/data_type.h"
#include "inc/loop.h"
#include "inc/functions.h"

/* Define ----------------------------------------------------------------------------------------*/
/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------------*/
/* Public function prototypes --------------------------------------------------------------------*/

int main(int argc, char * argv[])
{
		start();
		
		/* data type */
		size_data_type();

		/* loop */
		while_loop();
		for_loop();
		do_while_loop();
		nested_loop();

		/* Functions */
		call_a_function();

		/* Array */
		// mutil_dimensional();
 		// passing_array_to_function();
 		// return_array_form_a_function();
 		// poiter_return_array();
		func_check_array();

		/* pointers */
		pointer_arithmetic();
 		array_of_pointer();
 		pointer_to_pointer();
 		passing_pointer_to_function_in_c();
 		return_pointer_from_function_in_c();

		system("pause");
		return 0;
}

/* END OF FILE ************************************************************************************/