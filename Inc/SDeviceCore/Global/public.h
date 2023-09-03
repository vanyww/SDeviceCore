/**
 * @file global.h
 * @brief Публичный интерфейс глобального модуля (`CoreGlobal`) и внешний символ его дескриптора.
 * @details Модуль не имеет интерфейсных функций и предназначен для использования при
 * @link error_processing обработке ошибок @endlink функций фреймворка.
 * Функции создания и удаления дескриптора модуля отсутствуют, единственный дескриптор создается статически.
 */

#pragma once

#include "log.h"
#include "config.h"
#include "dependencies.h"

/**
 * @defgroup global_module Глобальный модуль
 * @brief @copybrief global.h
 * @details @copydetails global.h
 * @{
 */

#define CORE_GLOBAL_SDEVICE_VERSION_MAJOR 2
#define CORE_GLOBAL_SDEVICE_VERSION_MINOR 0
#define CORE_GLOBAL_SDEVICE_VERSION_PATCH 0
#define CORE_GLOBAL_SDEVICE_CORE_VERSION (                                                                             \
   (SDeviceVersion)                                                                                                    \
   {                                                                                                                   \
      .Major = CORE_GLOBAL_SDEVICE_VERSION_MAJOR,                                                                      \
      .Minor = CORE_GLOBAL_SDEVICE_VERSION_MINOR,                                                                      \
      .Patch = CORE_GLOBAL_SDEVICE_VERSION_PATCH                                                                       \
   })

/**
 * @brief Предварительное объявление типа данных дескриптора глобального модуля.
 */
SDEVICE_HANDLE_FORWARD_DECLARATION(CoreGlobal);

/**
 * @brief Паники глобального модуля.
 * @details Значения используются для выбрасывания паник фреймворка средствами #SDevicePanic.
 */
typedef enum
{
   CORE_GLOBAL_SDEVICE_PANIC_OUT_OF_MEMORY /**< Недостаток выделяемой памяти. */
} CoreGlobalSDevicePanic;

/**
 * @brief Объявление переменной строкового имени глобального модуля.
 */
SDEVICE_UUID_DECLARATION(CoreGlobal);

void CoreGlobalSDeviceThrowPanic(CoreGlobalSDevicePanic panic);
void CoreGlobalSDeviceLogStatus(CoreGlobalSDeviceStatus status);

/** @} */
