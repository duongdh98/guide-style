/**
  **************************************************************************************************
  * @file   logger.cpp
  * @brief  Starting point of this project.
  * @by     duonghd | 27-July-2024.
  **************************************************************************************************
  */

/*  Indent using spaces
    Tab width: 4 spaces
    Line width: 100 characters
    Line ending: LF (0x0A) */

/* Includes --------------------------------------------------------------------------------------*/

#include "logger.hpp"

#include <cstdio>
#include <cstdarg>

/* Private macros --------------------------------------------------------------------------------*/

/* Private data types ----------------------------------------------------------------------------*/

/* Private variables ----------------------------------------------------------------------------*/

static bool logger_enabled = true;
static std::uint32_t logger_level = LOG_LEVEL_ALL;

/* Private function prototypes -------------------------------------------------------------------*/
static void logger_print(std::uint32_t level, const char* prefix, const char* format, va_list args);

/* Public function bodies ------------------------------------------------------------------------*/

void logger_open(void)
{
    logger_enabled = true;
    logger_level = LOG_LEVEL_ALL;
}

void logger_enable(void)
{
    logger_enabled = true;
}

void logger_disable()
{
    logger_enabled = false;
}

void logger_setlevel(std::uint32_t level)
{
    logger_level = level;
}

std::uint32_t logger_setlevel()
{
    return logger_level;
}

void logger_error(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    logger_print(
        LOG_LEVEL_ERROR,
        "ERROR",
        format,
        args);

    va_end(args);
}

void logger_warn(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    logger_print(
        LOG_LEVEL_WARN,
        "WARN",
        format,
        args);

    va_end(args);
}

void logger_info(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    logger_print(
        LOG_LEVEL_INFO,
        "INFO",
        format,
        args);

    va_end(args);
}

void logger_debug(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    logger_print(
        LOG_LEVEL_DEBUG,
        "DEBUG",
        format,
        args);

    va_end(args);
}

/* Private function prototypes -------------------------------------------------------------------*/
static void logger_print(
    std::uint32_t level,
    const char* prefix,
    const char* format,
    va_list args)
{
    if (!logger_enabled)
    {
        return;
    }

    if ((logger_level & level) == 0U)
    {
        return;
    }

    std::printf("[%s] ", prefix);
    std::vprintf(format, args);
    std::printf("\n");
}

/* END OF FILE ************************************************************************************/