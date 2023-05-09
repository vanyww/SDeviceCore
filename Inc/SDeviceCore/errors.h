#pragma once

/**
 * @file errors.h
 * @brief Инструменты обработки ошибок.
 * @details Проверка утверждений, логирование и механизм исключений на основе библиотеки CException.
 */

/**
 * @defgroup error_processing Обработка ошибок
 * @brief @copybrief errors.h
 * @details @copydetails errors.h
 * @n Пример использования:
 * @snippet core/core.c error_processing_example
 * @{
 */

#include "config.h"

/**
 * @brief Тип данных исключения.
 * @details Определение типа данных, представляющего собой исключение (дескриптор модуля).
 */
typedef const void * CExceptionType;

/**
 * @brief Параметр CException: "пустое" значение исключения (NULL).
 */
#define CEXCEPTION_NONE (NULL)

/**
 * @brief Параметр CException: тип данных исключения (#CExceptionType).
 */
#define CEXCEPTION_T CExceptionType

/**
 * @brief Параметр CException: функция обработки необработанного исключения (#SDeviceProcessUnhandledThrow).
 */
#define CEXCEPTION_NO_CATCH_HANDLER(id) SDeviceProcessUnhandledThrow(id)

#include "../../Submodules/cexception/lib/CException.h"

#if defined SDEVICE_USE_ASSERT
#if defined SDEVICE_USE_SIMPLE_ASSERT
#define SDeviceAssert(expression) ((expression) ? (void)0U : SDeviceProcessAssertFail())
#else
/**
 * @brief Проверяет утверждение.
 * @details Проверяет утверждение @p expression, в случае его ложности вызывает функцию @ref SDeviceProcessAssertFail.
 * @note Если флаг #SDEVICE_USE_ASSERT не объявлен, выражение @p expression не будет исполнено.
 * @param expression Утверждение, которое необходимо проверить.
 */
#define SDeviceAssert(expression) ((expression) ? (void)0U : SDeviceProcessAssertFail(__FILE__, __LINE__))
#endif
/**
 * @brief Проверяет утверждение с его инвариантным исполнением.
 * @details Проверяет утверждение @p expression, в случае его ложности вызывает функцию @ref SDeviceProcessAssertFail.
 * @note Если флаг #SDEVICE_USE_ASSERT не объявлен, выражение @p expression будет исполнено, но не проверено.
 * @param expression Утверждение, которое необходимо проверить.
 */
#define SDeviceEvalAssert(expression) SDeviceAssert(expression)
#else
#define SDeviceAssert(expression) ((void)0U)
#define SDeviceEvalAssert(expression) expression
#endif

#if defined SDEVICE_USE_ASSERT && defined SDEVICE_USE_DEBUG_ASSERT
#if defined SDEVICE_USE_SIMPLE_ASSERT
#define SDeviceDebugAssert(expression) ((expression) ? (void)0U : SDeviceProcessAssertFail())
void SDeviceProcessAssertFail(void);
#else
/**
 * @brief Проверяет внутреннее утверждение модуля.
 * @details Принцип работы не отличается от #SDeviceAssert.
 * Предназначен для использования внутри универсальных модулей, проверяемых отдельно (вне конечного ПО).
 * @note Если флаг #SDEVICE_USE_DEBUG_ASSERT не объявлен, выражение @p expression не будет исполнено.
 * @param expression Утверждение, которое необходимо проверить.
 */
#define SDeviceDebugAssert(expression) ((expression) ? (void)0U : SDeviceProcessAssertFail(__FILE__, __LINE__))
#endif
/**
 * @brief Проверяет внутреннее утверждение модуля с его инвариантным исполнением.
 * @details Принцип работы не отличается от #SDeviceEvalAssert.
 * Предназначен для использования внутри универсальных модулей, проверяемых отдельно (вне конечного ПО).
 * @note Если флаг #SDEVICE_USE_DEBUG_ASSERT не объявлен, выражение @p expression будет исполнено, но не проверено.
 * @param expression Утверждение, которое необходимо проверить.
 */
#define SDeviceDebugEvalAssert(expression) SDeviceAssert(expression)
#else
#define SDeviceDebugAssert(expression) ((void)0U)
#define SDeviceDebugEvalAssert(expression) eSDeviceProcessLogStatusxpression
#endif

#if defined SDEVICE_USE_ASSERT
/**
 * @brief Логирует состояние дескриптора.
 * @details Записывает состояние @p status в дескриптор @p handle и вызывает @ref SDeviceProcessLogStatus.
 * @param handle Дескриптор, с которым должно быть ассоциировано логируемое состояние.
 * @param status Идентификатор состояния (int32_t).
 */
#define SDeviceLogStatus(handle, status) (                                                                             \
{                                                                                                                      \
   SDeviceHandleHeader *_header = (SDeviceHandleHeader *)(handle);                                                     \
   _header->LatestStatus = (status);                                                                                   \
   SDeviceProcessLogStatus(handle);                                                                                    \
})

#else
#define SDeviceLogStatus(handle, status) ((SDeviceHandleHeader *)(handle))->LatestStatus = (status)
#endif

/**
 * @brief Выбрасывает исключение.
 * @details Записывает состояние @p exception в дескриптор @p handle и выбрасывает последний в виде исключения.
 * @param handle Дескриптор, с которым должно быть ассоциировано выбрасываемое исключение.
 * @param exception Идентификатор исключения (int32_t).
 */
#define SDeviceThrow(handle, exception) (                                                                              \
{                                                                                                                      \
   SDeviceHandleHeader *_header = (SDeviceHandleHeader *)(handle);                                                     \
   _header->LatestStatus = (exception);                                                                                \
   Throw(handle);                                                                                                      \
})

#if defined SDEVICE_USE_SIMPLE_ASSERT
void SDeviceProcessAssertFail(void);
#else
/**
 * @brief Функция обработки проваленной проверки утверждения.
 * @details Вызывается при провале проверки утверждения макросами:
 * - #SDeviceAssert
 * - #SDeviceEvalAssert
 * - #SDeviceDebugAssert
 * - #SDeviceDebugEvalAssert
 *
 * @note Может иметь разные прототипы в зависимости от состояния флага #SDEVICE_USE_SIMPLE_ASSERT.
 * @note Определена в виде слабого символа, реализация по-умолчанию - вечный цикл.
 * @param[in] file Путь к файлу, в котором расположена проваленная проверка утверждения.
 * @param[in] line Строка файла, в которой расположено проваленная проверка утверждения.
 */
void SDeviceProcessAssertFail(char *file, int line);
#endif

/**
 * @brief Функция обработки запроса на логирование события.
 * @details Вызывается при запросе логирования макросом #SDeviceLogStatus.
 * @note Определена в виде слабого символа, реализация по-умолчанию - пустая функция.
 * @param[in] handle Дескриптор, ассоциированный с логируемым событием.
 */
void SDeviceProcessLogStatus(const void *handle);

/**
 * @brief Функция обработки необработанного явно исключения.
 * @details Вызывается в случае, если выброшенное (#SDeviceThrow) исключение не было обработано.
 * @note Определена в виде слабого символа, реализация по-умолчанию - вечный цикл.
 * @param[in] handle Дескриптор, ассоциированный с возникшим исключением.
 */
void SDeviceProcessUnhandledThrow(CEXCEPTION_T handle);

/** @} */
