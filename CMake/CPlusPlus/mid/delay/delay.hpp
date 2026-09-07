/**
  **************************************************************************************************
  * @file   delay.hpp
  * @brief  Delay utility functions.
  * @by     duonghd | 07-September-2026.
  **************************************************************************************************
  */

/*  Indent using spaces
    Tab width: 4 spaces
    Line width: 100 characters
    Line ending: LF (0x0A) */

/* Includes --------------------------------------------------------------------------------------*/

#pragma once

#include <cstdint>

/* Public data types -----------------------------------------------------------------------------*/

/* Public function prototypes --------------------------------------------------------------------*/

namespace delay
{
    void ms(std::uint32_t milliseconds);
    void sec(std::uint32_t seconds);
}

/* END OF FILE ************************************************************************************/
