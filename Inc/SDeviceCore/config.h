/**
 * @file config.h
 * @brief Конфигурация ядра фреймворка SDevice.
 * @details Опции, позволяющие изменять поведение отдельных частей фреймворка.
 */

#pragma once

#include <stddef.h>

#if defined SDEVICE_CORE_USE_EXTERNAL_CONFIG
   #include "sdevice_core_config.h"
#endif

/**
 * @defgroup configuration Конфигурация
 * @brief @copybrief config.h
 * @details @copydetails config.h
 * @{
 */

/**
 * @brief Флаг использования внешнего файла конфигурации.
 * @details Определение данного флага требует наличия файла `sdevice_core_config.h` в *include path*.
 * Файл создается пользователем и содержит параметры фреймворка SDevice.
 */
#if defined(DOXYGEN)
   #define SDEVICE_CORE_USE_EXTERNAL_CONFIG
   #undef SDEVICE_CORE_USE_EXTERNAL_CONFIG
#endif

/**
 * @defgroup errors Ошибки
 * @brief Конфигурация обработки ошибок.
 * @details Параметры функционала фреймворка, связанного с обработкой ошибок:
 * - проверка утверждений
 * - логирование
 * @{
 */

/**
 * @brief Флаг, включающий проверку утверждений.
 * @details Управляет поведением #SDeviceAssert, #SDeviceEvalAssert, #SDeviceDebugAssert и #SDeviceDebugEvalAssert.
 * Состояние флага включает или отключает проверку утверждений средствами условной компиляции.
 * Отключение проверки утверждений позволяет уменьшить затраты памяти и повысить производительность.
 */
#if defined(DOXYGEN)
   #define SDEVICE_USE_ASSERT
   #undef SDEVICE_USE_ASSERT
#endif

/**
 * @brief Флаг, включающий проверку внутренних утверждений модулей.
 * @details Управляет поведением #SDeviceDebugAssert и #SDeviceDebugEvalAssert.
 * Состояние флага включает или отключает проверку внутренних утверждений модулей средствами условной компиляции.
 * Отключение проверки внутренних утверждений модулей позволяет уменьшить затраты памяти и повысить производительность.
 */
#if defined(DOXYGEN)
   #define SDEVICE_USE_DEBUG_ASSERT
   #undef SDEVICE_USE_DEBUG_ASSERT
#endif

/**
 * @brief Флаг, упрощающий прототип функции @ref SDeviceProcessAssertFail.
 * @details Изменяет прототип с SDeviceProcessAssertFail(char *, int) на SDeviceProcessAssertFail(void).
 * Флаг позволяет уменьшить затраты памяти на проверку утверждений, исключив строковые пути к файлам и номера строк.
 */
#if defined(DOXYGEN)
   #define SDEVICE_USE_SIMPLE_ASSERT
   #undef SDEVICE_USE_SIMPLE_ASSERT
#endif

/**
 * @brief Флаг, включающий логирование.
 * @details Управляет поведением #SDeviceLogStatus.
 * Состояние флага включает или отключает логирование средствами условной компиляции.
 */
#if defined(DOXYGEN)
   #define SDEVICE_USE_STATUS_LOG
   #undef SDEVICE_USE_STATUS_LOG
#endif

/** @} */

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
#if !defined(SDEVICE_CORE_GLOBAL_HANDLE_CONTEXT) || defined(DOXYGEN)
   #define SDEVICE_CORE_GLOBAL_HANDLE_CONTEXT NULL
#endif

/**
 * @brief Идентификатор дескриптора глобального модуля.
 * @details Значение этого макроса будет использовано в качестве идентификатора дескриптора глобального модуля.
 * @n @ref SDeviceHandleHeader::Identifier.
 */
#if !defined(SDEVICE_CORE_GLOBAL_HANDLE_IDENTIFIER) || defined(DOXYGEN)
   #define SDEVICE_CORE_GLOBAL_HANDLE_IDENTIFIER 0
#endif

/** @} */

/** @} */
