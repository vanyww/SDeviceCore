/**
 * @file CoreGlobalSDevice/config.h
 * @brief Изменяемые параметры глобального модуля.
 * @details Макросы, определяющие параметры глобального модуля (`CoreGlobalSDevice`), доступные для переопределения.
 */

#pragma once

#include "SDeviceCore/config.h"

/**
 * @addtogroup core_global
 * @{
 */

/**
 * @defgroup core_global_config Конфигурация
 * @brief @copybrief CoreGlobalSDevice/config.h
 * @details @copydetails CoreGlobalSDevice/config.h
 * @{
 */

/**
 * @brief Флаг использования внешней конфигурации глобального модуля.
 * @details Значение `true` данного флага включает использование внешней конфигурации глобального модуля.
 * Она может переопределять значения по умолчанию в файле `core_global_sdevice_config.h`.
 * Этот файл должен быть создан и доступнен из `include paths` проекта.
 */
#if !defined(CORE_GLOBAL_SDEVICE_USE_EXTERNAL_CONFIG) || defined(DOXYGEN)
   #define CORE_GLOBAL_SDEVICE_USE_EXTERNAL_CONFIG false
#endif

#if CORE_GLOBAL_SDEVICE_USE_EXTERNAL_CONFIG
   #include "core_global_sdevice_config.h"
#endif

/**
 * @brief Контекст дескриптора глобального модуля.
 * @details Значение этого макроса будет использовано в качестве контекста дескриптора глобального модуля.
 * @n @ref SDeviceCommonHandle::Context.
 */
#if !defined(CORE_GLOBAL_SDEVICE_HANDLE_CONTEXT) || defined(DOXYGEN)
   #define CORE_GLOBAL_SDEVICE_HANDLE_CONTEXT NULL
#endif

/** @} */

/** @} */
