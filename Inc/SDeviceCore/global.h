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

#ifdef DOXYGEN

/**
 * @brief **[Опция]** Флаг использования дополнительного файла для определения контекста дескриптора глобального модуля.
 * @details Определение данного флага требует наличия файла `global_sdevice_context.h` в *include path*.
 * Файл создается пользователем и содержит определение контекста дескриптора глобального модуля.
 * Используется в комбинации с #SDEVICE_CORE_GLOBAL_CONTEXT.
 * @note Может быть объявлен пользователем.
 */
#define SDEVICE_USE_EXTERNAL_GLOBAL_CONTEXT

/**
 * @brief **[Опция]** Контекст дескриптора глобального модуля.
 * @ref SDeviceHandleHeader::Context.
 * @details Значение этого макроса будет использовано в качестве контекста дескриптора глобального модуля.
 * Используется в комбинации с #SDEVICE_USE_EXTERNAL_GLOBAL_CONFIG.
 * @note Может быть объявлен пользователем.
 */
#define SDEVICE_CORE_GLOBAL_CONTEXT

/**
 * @brief **[Опция]** Идентификатор дескриптора глобального модуля.
 * @details Значение этого макроса будет использовано в качестве идентификатора дескриптора глобального модуля.
 * @ref SDeviceHandleHeader::Identifier.
 * Используется в комбинации с #SDEVICE_USE_EXTERNAL_GLOBAL_CONFIG.
 * @note Может быть объявлен пользователем.
 */
#define SDEVICE_CORE_GLOBAL_HANDLE_IDENTIFIER

#endif

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

/**
 * @brief Дескриптор глобального модуля.
 */
extern SDEVICE_HANDLE(CoreGlobal) *const CoreGlobalSDeviceHandle;

/** @} */
