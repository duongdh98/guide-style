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

#include "logger.h"

#include <stdio.h>
#include <stdarg.h>

/* Private macros --------------------------------------------------------------------------------*/

/* Private data types ----------------------------------------------------------------------------*/

/* Private variables ----------------------------------------------------------------------------*/

static uint8_t logger_enabled = 1U;
static uint32_t logger_level = LOG_LEVEL_ALL;

/* Private function prototypes -------------------------------------------------------------------*/

static void logger_print(const char *level, const char *format, va_list args);

/* Public function bodies ------------------------------------------------------------------------*/

void logger_open(void)
{
    logger_enabled = 1U;
    logger_level = LOG_LEVEL_ALL;    
}

void logger_enable(void)
{
    logger_enabled = 1U;
}

void logger_disable(void)
{
    logger_enabled = 0U;
}

void logger_setlevel(uint32_t level)
{
    logger_level = level;
}

uint32_t logger_getlevel(void)
{
    return logger_level;
}

void logger_error(const char *format, ...)
{
    if ((logger_level & LOG_LEVEL_ERROR) == 0U)
    {
        return;
    }
    va_list args;
    va_start(args, format);
    logger_print("ERROR", format, args);
    va_end(args);
}

void logger_warn(const char *format, ...)
{
    if ((logger_level & LOG_LEVEL_WARN) == 0U)
    {
        return;
    }
    va_list args;
    va_start(args, format);
    logger_print("WARN", format, args);
    va_end(args);
}
void logger_info(const char *format, ...)
{
    if ((logger_level & LOG_LEVEL_INFO) == 0U)
    {
        return;
    }

    va_list args;
    va_start(args, format);
    logger_print("INFO", format, args);
    va_end(args);
}
void logger_debug(const char *format, ...)
{
    if ((logger_level & LOG_LEVEL_DEBUG) == 0U)
    {
        return;
    }

    va_list args;
    va_start(args, format);
    logger_print("DEBUG", format, args);
    va_end(args);
}

/* Private function bodies -----------------------------------------------------------------------*/

static void logger_print(const char *level, const char *format, va_list args)
{
    if (!logger_enabled){ return;}

    printf("[%s] ", level);
    vprintf(format, args);
    printf("\n");
}

/* END OF FILE ************************************************************************************/