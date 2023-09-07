/**
 * @file CoreGlobalSDevice/log.h
 * @brief Определения лога глобального модуля.
 * @details Определения, испольуемые глобальным модулем (`CoreGlobalSDevice`) для логирования его состояния.
 */

#pragma once

/**
 * @addtogroup core_global
 * @{
 */

/**
 * @defgroup core_global_log Логирование
 * @brief @copybrief CoreGlobalSDevice/log.h
 * @details @copydetails CoreGlobalSDevice/log.h
 * @{
 */

/**
 * @brief Состояния глобального модуля.
 * @details Допустимые значения состояний глобального модуля, используемые для логирования.
 */
typedef enum
{
   CORE_GLOBAL_SDEVICE_STATUS_OK /**< Нормальная работа. */
} CoreGlobalSDeviceStatus;

/** @} */

/** @} */
