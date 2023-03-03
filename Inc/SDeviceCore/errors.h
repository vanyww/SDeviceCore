#pragma once

/**
 * @file errors.h
 * @brief Операции обработки ошибок.
 * @details Операции проверки утверждений, логирования, а также механизм исключений на основе библиотеки CException.
 */

/**
 * @defgroup Errors Обработка ошибок
 * @copydoc errors.h
 * @n Пример использования:
 * @snippet core/core.c Errors processing examples
 * @{
 */

#include <stddef.h>

#ifdef DOXYGEN

/**
 * @brief Флаг, включающий проверку утверждений.
 * @details Отключение проверки утверждений позволяет уменьшить затраты памяти и повысить производительность.
 * Относится к #SDeviceAssert и #SDeviceEvalAssert.
 * @note *Может* быть объявлен пользователем.
 */
#define SDEVICE_USE_ASSERT

/**
 * @brief Флаг, включающий проверку внутренних утверждений модулей.
 * @details Отключение проверки утверждений позволяет уменьшить затраты памяти и повысить производительность.
 * Относится к #SDeviceDebugAssert и #SDeviceDebugEvalAssert.
 * @note *Может* быть объявлен пользователем.
 */
#define SDEVICE_USE_DEBUG_ASSERT

/**
 * @brief Флаг, изменяющий прототип функции SDeviceProcessAssertFail(char *, int) на  SDeviceProcessAssertFail(void).
 * @details Уменьшает затраты памяти, ассоциированные с проверкой утверждений.
 * @note *Может* быть объявлен пользователем.
 */
#define SDEVICE_USE_SIMPLE_ASSERT
#undef SDEVICE_USE_SIMPLE_ASSERT

/**
 * @brief Флаг, включающий логирование.
 * @details Относится к #SDeviceLogStatus.
 * @note *Может* быть объявлен пользователем.
 */
#define SDEVICE_USE_STATUS_LOG

/**
 * @brief Флаг использования дополнительного файла для определения параметров библиотеки CException.
 * @details В случае объявления данного макроса пользователем, в файл errors.h.c будет включена директива препроцессора:
 * @code
 * #include "sdevice_error_config"
 * @endcode
 * Пользователь обязан создать соответствующий заголовочный файл.
 * Позволяет изменить параметры механизма исключений на основе библиотеки CException.
 *
 * @note *Может* быть объявлен пользователем.
 */
#define SDEVICE_USE_EXTERNAL_ERROR_CONFIG
#undef SDEVICE_USE_EXTERNAL_ERROR_CONFIG

#endif

/**
 * Тип данных исключения.
 */
typedef const void * CExceptionType;

#ifdef SDEVICE_USE_EXTERNAL_ERROR_CONFIG
#include "sdevice_error_config.h"
#endif

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

#ifdef SDEVICE_USE_ASSERT
#ifdef SDEVICE_USE_SIMPLE_ASSERT
#define SDeviceAssert(expression) ((expression) ? (void)0U : SDeviceProcessAssertFail())
#else
/**
 * @brief Проверяет утверждение и, в случае его ложности, вызывает функцию SDeviceProcessAssertFail.
 * @note В случае, если флаг #SDEVICE_USE_ASSERT не объявлен, выражение не будет исполнено.
 * @param expression Утверждение, которое необходимо проверить.
 */
#define SDeviceAssert(expression) ((expression) ? (void)0U : SDeviceProcessAssertFail(__FILE__, __LINE__))
#endif
/**
 * @brief Проверяет утверждение и, в случае его ложности, вызывает функцию SDeviceProcessAssertFail.
 * @note В случае, если флаг #SDEVICE_USE_ASSERT не объявлен, выражение все равно будет исполнено, но не проверено.
 * @param expression Утверждение, которое необходимо проверить.
 */
#define SDeviceEvalAssert(expression) SDeviceAssert(expression)
#else
#define SDeviceAssert(expression) ((void)0U)
#define SDeviceEvalAssert(expression) expression
#endif

#ifdef SDEVICE_USE_DEBUG_ASSERT
#ifdef SDEVICE_USE_SIMPLE_ASSERT
#define SDeviceDebugAssert(expression) ((expression) ? (void)0U : SDeviceProcessAssertFail())
void SDeviceProcessAssertFail(void);
#else
/**
 * @brief Проверяет утверждение и, в случае его ложности, вызывает функцию SDeviceProcessAssertFail.
 * @details Предназначен для проверки утверждений во внутренних функциях универсальных модулей.
 * @note В случае, если флаг #SDEVICE_USE_ASSERT не объявлен, утверждение не будет исполнено.
 * @param expression Утверждение, которое необходимо проверить.
 */
#define SDeviceDebugAssert(expression) ((expression) ? (void)0U : SDeviceProcessAssertFail(__FILE__, __LINE__))
#endif
/**
 * @brief Проверяет утверждение и, в случае его ложности, вызывает функцию SDeviceProcessAssertFail.
 * @details Предназначен для проверки утверждений во внутренних функциях универсальных модулей.
 * @note В случае, если флаг #SDEVICE_USE_ASSERT не объявлен, выражение все равно будет исполнено, но не проверено.
 * @param expression Утверждение, которое необходимо проверить.
 */
#define SDeviceDebugEvalAssert(expression) SDeviceAssert(expression)
#else
#define SDeviceDebugAssert(expression) ((void)0U)
#define SDeviceDebugEvalAssert(expression) eSDeviceProcessLogStatusxpression
#endif

#ifdef SDEVICE_USE_STATUS_LOG
/**
 * @brief Производит логирование состояния дескриптора.
 * @param handle Дескриптор, с которым должно быть ассоциировано логируемое состояние.
 * @param status Идентификатор состояния  (int32_t).
 */
#define SDeviceLogStatus(handle, status) (                                                                             \
{                                                                                                                      \
   SDeviceCommonHandle *$handle = (SDeviceCommonHandle *)(handle);                                                     \
   $handle->Header.LatestStatus = (status);                                                                            \
   SDeviceProcessLogStatus($handle);                                                                                   \
})

#else
#define SDeviceLogStatus(handle, status) ((SDeviceCommonHandle *)(handle))->Header.LatestStatus = (status)
#endif

/**
 * @brief Выбрасывает исключение.
 * @param handle Дескриптор, с которым должно быть ассоциировано выбрасываемое исключение.
 * @param exception Идентификатор исключения (int32_t).
 */
#define SDeviceThrow(handle, exception) (                                                                              \
{                                                                                                                      \
   SDeviceCommonHandle *$handle = (SDeviceCommonHandle *)(handle);                                                     \
   $handle->Header.LatestStatus = (exception);                                                                         \
   Throw($handle);                                                                                                     \
})

#ifdef SDEVICE_USE_SIMPLE_ASSERT
void SDeviceProcessAssertFail(void);
#else
/**
 * @brief Функция обработки проваленной проверки утверждения.
 * @note Определена в виде слабого символа, реализация по-умолчанию - вечный цикл.
 * @param file Путь к файлу, в котором расположена проваленная проверка утверждения.
 * @param line Строка файла, в которой расположено проваленная проверка утверждения.
 */
void SDeviceProcessAssertFail(char *file, int line);
#endif

/**
 * @brief Функция обработки запроса на логирование события.
 * @note Определена в виде слабого символа, реализация по-умолчанию - пустая функция.
 * @param _handle Дескриптор, ассоциированный с логируемым событием.
 */
void SDeviceProcessLogStatus(const void *_handle);

/**
 * @brief Функция обработки необработанного явно исключения.
 * @details Вызывается в случае, если возникшее исключение не обрабатывается в цепочке вызовов.
 * @note Определена в виде слабого символа, реализация по-умолчанию - вечный цикл.
 * @param _handle Дескриптор, ассоциированный с возникшим исключением.
 */
void SDeviceProcessUnhandledThrow(CEXCEPTION_T _handle);

/** @} */
