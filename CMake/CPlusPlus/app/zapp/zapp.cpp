/**
  **************************************************************************************************
  * @file   zapp.cpp
  * @brief  Starting point of this project.
  * @by     duonghd | 27-July-2024.
  **************************************************************************************************
  */

/*  Indent using spaces
    Tab width: 4 spaces
    Line width: 100 characters
    Line ending: LF (0x0A) */

/* Includes --------------------------------------------------------------------------------------*/

#include "zapp.hpp"
#include "logger.hpp"

#include <thread>
#include "delay.hpp"

/* Private macros --------------------------------------------------------------------------------*/

/* Private data types ----------------------------------------------------------------------------*/

/* Private variables ----------------------------------------------------------------------------*/

/* Private function prototypes -------------------------------------------------------------------*/
static void zapp_task(void);

/* Public function bodies ------------------------------------------------------------------------*/

void zapp_open(void)
{
    logger_open();
    DBG_INFO("%s: open ..", __FUNCTION__);
    std::thread(zapp_task).detach();
}

/* Private function prototypes -------------------------------------------------------------------*/
static void zapp_task(void)
{
    for (;;)
    {
        DBG_INFO("%s: zapp task running ..", __FUNCTION__);
        delay::ms(1000);
    }
}

/* END OF FILE ************************************************************************************/