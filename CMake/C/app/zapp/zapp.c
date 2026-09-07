/**
  **************************************************************************************************
  * @file   logger.c
  * @brief  Starting point of this project.
  * @by     duonghd | 27-July-2024.
  **************************************************************************************************
  */

/*  Indent using spaces
    Tab width: 4 spaces
    Line width: 100 characters
    Line ending: LF (0x0A) */

/* Includes --------------------------------------------------------------------------------------*/

#include <pthread.h>
#include "logger.h"
#include <unistd.h>

/* Private macros --------------------------------------------------------------------------------*/

/* Private data types ----------------------------------------------------------------------------*/

/* Private variables ----------------------------------------------------------------------------*/

/* Private function prototypes -------------------------------------------------------------------*/
static void *zapp_task(void *arg);

/* Public function bodies ------------------------------------------------------------------------*/

void zapp_open(void)
{
    pthread_t thread;
    pthread_create(&thread, NULL, zapp_task, NULL);
    pthread_join(thread, NULL);
}

/* Private function bodies -----------------------------------------------------------------------*/

static void *zapp_task(void *arg)
{
    logger_open();
    while (1)
    {
        DBG_INFO("%s: Task is running...", __FUNCTION__);
        sleep(1);
    }

    return NULL;
}

/* END OF FILE ************************************************************************************/