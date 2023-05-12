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
#include "inc/cmd.h"
#include "inc/n_thread.h"

/* Define ----------------------------------------------------------------------------------------*/
/* Private data types ----------------------------------------------------------------------------*/
/* Public data types -----------------------------------------------------------------------------*/
/* Private function prototypes -------------------------------------------------------------------*/
/* Public function prototypes --------------------------------------------------------------------*/

typedef struct {
    int id;
    char name[50];
    float salary;
} employee_t;

void *thread_func(typedef struct employee_t *g_em)
{   
    for(;;) {
        printf("ID : %d\n", g_em->id);
        printf("Name : %s\n", g_em->name);
        printf("Salary : %f\n", g_em->salary);
        delay_ms(100);
    }
}

int main(int argc, char *argv[])
{
    pthread_t t1;
    employee_t e1;
    e1.id = 17;
    strcpy(e1.name, "Dai Duong");
    e1.salary = 5;

    pthread_create(&t1, NULL, &thread_func, &e1);
    pthread_join(t1, NULL);
    return 0;
}

/* END OF FILE ************************************************************************************/