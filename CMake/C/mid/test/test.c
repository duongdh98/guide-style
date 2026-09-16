/**
  **************************************************************************************************
  * @file   test.c
  * @brief  Starting point of this project.
  * @by     duonghd | 27-July-2024.
  **************************************************************************************************
  */

/*  Indent using spaces
    Tab width: 4 spaces
    Line width: 100 characters
    Line ending: LF (0x0A) */

/* Includes --------------------------------------------------------------------------------------*/

#include "logger.h"

#include <stdio.h>
#include <stdarg.h>

/* Private macros --------------------------------------------------------------------------------*/

/* Private data types ----------------------------------------------------------------------------*/

/* Private variables ----------------------------------------------------------------------------*/

/* Private function prototypes -------------------------------------------------------------------*/
static void dumplist(int, ...);
static void display(int num, ...);
 
/* Public function bodies ------------------------------------------------------------------------*/

void test_open(void)
{
    dumplist(2, 4, 8); // 1-4, 0-8
    dumplist(3, 6, 9, 7); // 2-6, 1-9, 0-7

    display(4, 'A', 'B', 'C', 'D');
    
    return;
}

/* Private function bodies -----------------------------------------------------------------------*/
static void dumplist(int n, ...)
{
    va_list p; int i;
    va_start(p, n);

    while(n-->0)
    {
        i = va_arg(p, int);
        printf("N: %d, ARG: %d", n, i); 
    }
    va_end(p);
    printf("\n");
}

static void display(int num, ...)
{
    char c, c1; int j;
    va_list ptr, ptr1;
    va_start(ptr, num);
    va_start(ptr1, num);
    for(j=1; j<=num; j++)
    {
        c = va_arg(ptr, int);
        printf("%c", c);
        c1 = va_arg(ptr1, int);
        printf("%d\n", c1);
    }
}
/* END OF FILE ************************************************************************************/