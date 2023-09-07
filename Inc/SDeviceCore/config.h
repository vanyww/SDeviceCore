/**
 * @file SDeviceCore/config.h
 * @brief Конфигурация ядра фреймворка SDevice.
 * @details Опции, позволяющие изменять поведение отдельных частей фреймворка.
 */

#pragma once

#include <stddef.h>
#include <stdbool.h>

/**
 * @defgroup sdevice_core_config Конфигурация
 * @brief @copybrief SDeviceCore/config.h
 * @details @copydetails SDeviceCore/config.h
 * @{
 */

/**
 * @brief Флаг использования внешней конфигурации фреймворка.
 * @details Значение `true` данного флага включает использование внешней конфигурации фреймворка SDevice.
 * Она может переопределять значения по умолчанию в файле `sdevice_core_config.h`.
 * Этот файл должен быть создан и доступнен из `include paths` проекта.
 */
#if !defined(SDEVICE_CORE_USE_EXTERNAL_CONFIG) || defined(DOXYGEN)
   #define SDEVICE_CORE_USE_EXTERNAL_CONFIG false
#endif

#if SDEVICE_CORE_USE_EXTERNAL_CONFIG
   #include "sdevice_core_config.h"
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

/** @} */
