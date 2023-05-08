#pragma once

/**
 * @file global.h
 * @brief Публичный интерфейс глобального модуля (`CoreGlobal`) и внешний символ его дескриптора.
 * @details Модуль не имеет интерфейсных функций и предназначен для использования при
 * @link error_processing обработке ошибок @endlink функций фреймворка.
 * Функции создания и удаления дескриптора модуля отсутствуют, единственный дескриптор создается статически.
 */

/**
 * @defgroup global_module Глобальный модуль
 * @brief @copybrief global.h
 * @details @copydetails global.h
 * @{
 */

#include "SDeviceCore/core.h"

/**
 * @brief Предварительное объявление типа данных дескриптора глобального модуля.
 */
SDEVICE_HANDLE_FORWARD_DECLARATION(CoreGlobal);

/**
 * @brief Состояния глобального модуля.
 * @details Значения используются для логирования состояний фреймворка средствами #SDeviceLogStatus.
 */
typedef enum
{
   CORE_GLOBAL_SDEVICE_STATUS_OK /**< Нормальная работа. */
} CoreGlobalSDeviceStatus;

/**
 * @brief Исключения глобального модуля.
 * @details Значения используются для выбрасывания исключений фреймворка средствами #SDeviceThrow.
 */
typedef enum
{
   CORE_GLOBAL_SDEVICE_EXCEPTION_OUT_OF_MEMORY /**< Недостаток выделяемой памяти. */
} CoreGlobalSDeviceException;

SDEVICE_STRING_NAME_DECLARATION(CoreGlobal);

/**
 * @brief Дескриптор глобального модуля.
 */
extern SDEVICE_HANDLE(CoreGlobal) *const CoreGlobalSDeviceHandle;

/** @} */
