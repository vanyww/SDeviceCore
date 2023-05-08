#pragma once

#include <stddef.h>

#if defined SDEVICE_CORE_USE_EXTERNAL_CONFIG
#include "sdevice_core_config.h"
#endif

/**
 * @brief **[Опция]** Флаг использования дополнительного файла параметров библиотеки CException.
 * @details Определение данного флага требует наличия файла `sdevice_error_config.h` в *include path*.
 * Файл создается пользователем и содержит параметры библиотеки CException, используемой в механизме исключений.
 * Допускается изменение любых параметров, кроме уже определенных:
 * - #CEXCEPTION_NONE
 * - #CEXCEPTION_T
 * - #CEXCEPTION_NO_CATCH_HANDLER
 *
 * @note Может быть объявлен пользователем.
 */
#if defined DOXYGEN
#define SDEVICE_CORE_USE_EXTERNAL_CONFIG
#undef SDEVICE_CORE_USE_EXTERNAL_CONFIG
#endif

/**
 * @brief **[Опция]** Флаг, включающий проверку утверждений.
 * @details Управляет поведением #SDeviceAssert и #SDeviceEvalAssert.
 * Состояние флага удаляет или добавляет проверку утверждений при помощи условной компиляции.
 * Отключение проверки утверждений позволяет уменьшить затраты памяти и повысить производительность.
 * @note Может быть объявлен пользователем.
 */
#if defined DOXYGEN
#define SDEVICE_USE_ASSERT
#undef SDEVICE_USE_ASSERT
#endif

/**
 * @brief **[Опция]** Флаг, включающий проверку внутренних утверждений модулей.
 * @details Управляет поведением #SDeviceDebugAssert и #SDeviceDebugEvalAssert.
 * Состояние флага удаляет или добавляет проверку внутренних утверждений модулей при помощи условной компиляции.
 * Отключение проверки внутренних утверждений модулей позволяет уменьшить затраты памяти и повысить производительность.
 * @note Может быть объявлен пользователем.
 */
#if defined DOXYGEN
#define SDEVICE_USE_DEBUG_ASSERT
#undef SDEVICE_USE_DEBUG_ASSERT
#endif

/**
 * @brief **[Опция]** Флаг, упрощающий прототип функции @ref SDeviceProcessAssertFail.
 * @details Изменяет прототип с SDeviceProcessAssertFail(char *, int) на SDeviceProcessAssertFail(void).
 * Флаг позволяет уменьшить затраты памяти на проверку утверждений, исключив строковые пути к файлам и номера строк.
 * @note Может быть объявлен пользователем.
 */
#if defined DOXYGEN
#define SDEVICE_USE_SIMPLE_ASSERT
#undef SDEVICE_USE_SIMPLE_ASSERT
#endif

/**
 * @brief **[Опция]** Флаг, включающий логирование.
 * @details Управляет поведением #SDeviceLogStatus.
 * Состояние флага удаляет или добавляет логирование при помощи условной компиляции.
 * @note Может быть объявлен пользователем.
 */
#if defined DOXYGEN
#define SDEVICE_USE_STATUS_LOG
#undef SDEVICE_USE_STATUS_LOG
#endif

/**
 * @brief **[Опция]** Контекст дескриптора глобального модуля.
 * @ref SDeviceHandleHeader::Context.
 * @details Значение этого макроса будет использовано в качестве контекста дескриптора глобального модуля.
 * Используется в комбинации с #SDEVICE_USE_EXTERNAL_GLOBAL_CONFIG.
 * @note Может быть объявлен пользователем.
 */
#if !defined SDEVICE_CORE_GLOBAL_HANDLE_CONTEXT || defined DOXYGEN
#define SDEVICE_CORE_GLOBAL_HANDLE_CONTEXT NULL
#endif

/**
 * @brief **[Опция]** Идентификатор дескриптора глобального модуля.
 * @details Значение этого макроса будет использовано в качестве идентификатора дескриптора глобального модуля.
 * @ref SDeviceHandleHeader::Identifier.
 * Используется в комбинации с #SDEVICE_USE_EXTERNAL_GLOBAL_CONFIG.
 * @note Может быть объявлен пользователем.
 */
#if !defined SDEVICE_CORE_GLOBAL_HANDLE_IDENTIFIER || defined DOXYGEN
#define SDEVICE_CORE_GLOBAL_HANDLE_IDENTIFIER 0
#endif

