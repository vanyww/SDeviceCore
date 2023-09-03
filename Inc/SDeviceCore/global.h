/**
 * @file global.h
 * @brief Публичный интерфейс глобального модуля (`CoreGlobal`) и внешний символ его дескриптора.
 * @details Модуль не имеет интерфейсных функций и предназначен для использования при
 * @link error_processing обработке ошибок @endlink функций фреймворка.
 * Функции создания и удаления дескриптора модуля отсутствуют, единственный дескриптор создается статически.
 */

#pragma once

#include "SDeviceCore/core.h"

/**
 * @defgroup global_module Глобальный модуль
 * @brief @copybrief global.h
 * @details @copydetails global.h
 * @{
 */

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

/**
 * @brief Дескриптор глобального модуля.
 */
extern SDEVICE_HANDLE(CoreGlobal) *const CoreGlobalSDeviceHandle;

/** @} */
