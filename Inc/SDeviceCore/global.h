#pragma once

/**
 * @file global.h
 * @brief Публичный интерфейс глобального модуля и внешний символ его дескриптора.
 * @details Используется в качестве заглушки при возникновении ошибок в функциях фреймворка.
 */

/**
 * @defgroup Global Глобальный модуль
 * @copydoc global.h
 * @{
 */

#include "SDeviceCore/core.h"

#ifdef DOXYGEN

/**
 * @brief Флаг использования дополнительного файла для определения контекста дескриптора глобального модуля.
 * @details В случае объявления данного макроса пользователем, в файл global.c будет включена директива препроцессора:
 * @code
 * #include "global_sdevice_context.h"
 * @endcode
 * Пользователь обязан создать соответствующий заголовочный файл.
 * Он может быть использован для определения контекста дескриптора глобального модуля (#SDEVICE_CORE_GLOBAL_CONTEXT).
 * @note *Может* быть объявлен пользователем.
 */
#define SDEVICE_USE_EXTERNAL_GLOBAL_CONTEXT

/**
 * @brief Значение контекста дескриптора глобального модуля.
 * @details Указатель на значение этого макроса будет использован в качестве контекста дескриптора глобального модуля.
 * Используется в комбинации с флагом #SDEVICE_USE_EXTERNAL_GLOBAL_CONTEXT.
 * @note *Может* быть объявлен пользователем.
 */
#define SDEVICE_CORE_GLOBAL_CONTEXT

#endif

/**
 * @brief Предварительное объявление типа данных дескриптора глобального модуля.
 */
SDEVICE_HANDLE_FORWARD_DECLARATION(CoreGlobal);

/**
 * @brief Состояния глобального модуля.
 */
typedef enum
{
   CORE_GLOBAL_SDEVICE_STATUS_OK /**< Нормальная работа. */
} CoreGlobalSDeviceStatus;

/**
 * @brief Исключения глобального модуля.
 */
typedef enum
{
   CORE_GLOBAL_SDEVICE_EXCEPTION_OUT_OF_MEMORY /**< Недостаток выделяемой динамически памяти. */
} CoreGlobalSDeviceException;

/**
 * @brief Дескриптор глобального модуля.
 */
extern SDEVICE_HANDLE(CoreGlobal) *const CoreGlobalSDeviceHandle;

/** @} */
