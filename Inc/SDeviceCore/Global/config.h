#pragma once

#include "SDeviceCore/config.h"

#if defined(CORE_GLOBAL_SDEVICE_USE_EXTERNAL_CONFIG)
   #include "core_global_sdevice_config.h"
#endif

/**
 * @defgroup global_handle Глобальный модуль
 * @brief Конфигурация глобального модуля.
 * @details Параметры функционала фреймворка, связанного с глобальным модулем.
 * @{
 */

/**
 * @brief Контекст дескриптора глобального модуля.
 * @details Указатель на значение этого макроса будет использован в качестве контекста дескриптора глобального модуля.
 * @n @ref SDeviceHandleHeader::Context.
 */
#if !defined(CORE_GLOBAL_SDEVICE_HANDLE_CONTEXT) || defined(DOXYGEN)
   #define CORE_GLOBAL_SDEVICE_HANDLE_CONTEXT NULL
#endif

/**
 * @brief Идентификатор дескриптора глобального модуля.
 * @details Значение этого макроса будет использовано в качестве идентификатора дескриптора глобального модуля.
 * @n @ref SDeviceHandleHeader::Identifier.
 */
#if !defined(CORE_GLOBAL_SDEVICE_HANDLE_IDENTIFIER) || defined(DOXYGEN)
   #define CORE_GLOBAL_SDEVICE_HANDLE_IDENTIFIER 0
#endif

/** @} */
