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

#ifndef LOGGER_H
#define LOGGER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/* Public macros ---------------------------------------------------------------------------------*/

#define LOG_LEVEL_ERROR    (1U << 0)
#define LOG_LEVEL_WARN     (1U << 1)
#define LOG_LEVEL_INFO     (1U << 2)
#define LOG_LEVEL_DEBUG    (1U << 3)

#define LOG_LEVEL_ALL \
    (LOG_LEVEL_ERROR | \
     LOG_LEVEL_WARN  | \
     LOG_LEVEL_INFO  | \
     LOG_LEVEL_DEBUG)

/* Public data types -----------------------------------------------------------------------------*/

/* Public function prototypes --------------------------------------------------------------------*/

void logger_open(void);

void logger_enable(void);
void logger_disable(void);

void logger_setlevel(uint32_t level);

uint32_t logger_getlevel(void);

void logger_error(const char *format, ...);
void logger_warn(const char *format, ...);
void logger_info(const char *format, ...);
void logger_debug(const char *format, ...);

#define DBG_ERROR(...)  logger_error(__VA_ARGS__)
#define DBG_WARN(...)   logger_warn(__VA_ARGS__)
#define DBG_INFO(...)   logger_info(__VA_ARGS__)
#define DBG_DEBUG(...)  logger_debug(__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif /* LOGGER_H */

/* END OF FILE ************************************************************************************/