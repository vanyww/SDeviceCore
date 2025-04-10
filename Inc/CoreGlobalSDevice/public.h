/**
 * @file CoreGlobalSDevice/public.h
 * @brief Публичный интерфейс глобального модуля.
 * @details Глобальный модуль (`CoreGlobalSDevice`) создается статически в одном экземпляре.
 * Он используется для логирования состояний и выбрасывания паник фреймворка SDevice.
 */

#pragma once

#include "config.h"
#include "dependencies.h"

/**
 * @defgroup core_global Глобальный модуль
 * @{
 */

/**
 * @defgroup core_global_public Публичный интерфейс
 * @brief @copybrief CoreGlobalSDevice/public.h
 * @details @copydetails CoreGlobalSDevice/public.h
 * @{
 */

/**
 * @brief Старшая компонента версии глобального модуля.
 */
#define CORE_GLOBAL_SDEVICE_VERSION_MAJOR SDEVICE_CORE_VERSION_MAJOR

/**
 * @brief Средняя компонента версии глобального модуля.
 */
#define CORE_GLOBAL_SDEVICE_VERSION_MINOR SDEVICE_CORE_VERSION_MINOR

/**
 * @brief Младшая компонента версии глобального модуля.
 */
#define CORE_GLOBAL_SDEVICE_VERSION_PATCH SDEVICE_CORE_VERSION_PATCH

/**
 * @brief Предварительное объявление типа данных дескриптора глобального модуля.
 */
SDEVICE_HANDLE_FORWARD_DECLARATION(CoreGlobal);

/**
 * @brief Паники глобального модуля.
 */
typedef enum
{
   CORE_GLOBAL_SDEVICE_PANIC_OUT_OF_MEMORY /**< Недостаток динамически выделяемой памяти. */
} CoreGlobalSDevicePanic;

/**
 * @brief Выбрасывает панику глобального модуля.
 * @details Использует #SDevicePanic.
 * @param panic Паника для выбрасывания.
 */
void CoreGlobalSDeviceThrowPanic(CoreGlobalSDevicePanic panic);

/** @} */

/** @} */
