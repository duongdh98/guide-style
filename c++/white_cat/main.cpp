/***************************************************************************************************************
 * @detail          : Softmware wirite in free time and write for white cat
 * @auth            : duonghd                                                        
 * @day             : 11-may-2023
 * @file            : main.c                                              
 * @dissaption      : File to create white cat project . Coding in free time                                              
***************************************************************************************************************/

/*  Indent using spaces
    Tab width: 4 spaces
    Line width: 100 characters
    Line ending: LF (0x0A) */

/* Public macros ---------------------------------------------------------------------------------*/
/* Include ---------------------------------------------------------------------------------------*/
#include "stdio.h"
#include "stdint.h"
#include "libxl.h"
using namespace libxl;

/* Define ----------------------------------------------------------------------------------------*/
/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------------*/
/* Public function prototypes --------------------------------------------------------------------*/

int main(int argc, char * argv[])
{
    Book* book = xlCreateBook(); // xlCreateXMLBook() for xlsx
    if(book)
    {
        Sheet* sheet = book->addSheet(L"Sheet1");
        if(sheet)
        {
            sheet->writeStr(2, 1, L"Hello, World !");
            sheet->writeNum(3, 1, 1000);
        }
        book->save(L"example.xls");
        book->release();
    }
    
    return 0;
}

/* END OF FILE ************************************************************************************/