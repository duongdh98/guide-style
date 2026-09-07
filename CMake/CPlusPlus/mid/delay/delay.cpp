/**
  **************************************************************************************************
  * @file   delay.cpp
  * @brief  Delay utility functions.
  * @by     duonghd | 07-September-2026.
  **************************************************************************************************
  */

/*  Indent using spaces
    Tab width: 4 spaces
    Line width: 100 characters
    Line ending: LF (0x0A) */

/* Includes --------------------------------------------------------------------------------------*/

#include "delay.hpp"

#include <thread>
#include <chrono>

/* Private macros --------------------------------------------------------------------------------*/

/* Private data types ----------------------------------------------------------------------------*/

/* Private variables -----------------------------------------------------------------------------*/

/* Private function prototypes -------------------------------------------------------------------*/

/* Public function bodies ------------------------------------------------------------------------*/

namespace delay
{
    void ms(std::uint32_t milliseconds)
    {
        std::this_thread::sleep_for(
            std::chrono::milliseconds(milliseconds)
        );
    }

    void sec(std::uint32_t seconds)
    {
        std::this_thread::sleep_for(
            std::chrono::seconds(seconds)
        );
    }
}

/* END OF FILE ************************************************************************************/
