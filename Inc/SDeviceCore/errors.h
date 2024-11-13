/**
 * @file SDeviceCore/errors.h
 * @brief Инструменты обработки ошибок.
 * @details Проверка утверждений, логирование и паники.
 */

#pragma once

#include "config.h"

/**
 * @defgroup sdevice_core_errors Обработка ошибок
 * @brief @copybrief SDeviceCore/errors.h
 * @details @copydetails SDeviceCore/errors.h
 * @{
 */

/**
 * @brief Проверяет утверждение.
 * @details Проверяет утверждение @p expression, в случае его ложности вызывает функцию @ref SDeviceProcessAssertFail.
 * @note Если флаг #SDEVICE_USE_ASSERT не объявлен, выражение @p expression не будет исполнено.
 * @param expression Утверждение, которое необходимо проверить.
 */
#if SDEVICE_USE_ASSERT || defined(DOXYGEN)
   #if SDEVICE_USE_SIMPLE_ASSERT
      #define SDeviceAssert(expression) ((expression) ? (void)0U : SDeviceProcessAssertFail())
   #else
      #define SDeviceAssert(expression) ((expression) ? (void)0U : SDeviceProcessAssertFail(__FILE__, __LINE__))
   #endif
#else
   #define SDeviceAssert(expression) ((void)0U)
#endif

/**
 * @brief Проверяет утверждение с его инвариантным исполнением.
 * @details Проверяет утверждение @p expression, в случае его ложности вызывает функцию @ref SDeviceProcessAssertFail.
 * @note Если флаг #SDEVICE_USE_ASSERT не объявлен, выражение @p expression будет исполнено, но не проверено.
 * @param expression Выражение, исполняемое инвариантно.
 * @param condition Условие, применяемое к выражение в ходе проверки утверждения.
 */
#if SDEVICE_USE_ASSERT || defined(DOXYGEN)
   #define SDeviceEvalAssert(expression, condition) SDeviceAssert((expression) condition)
#else
   #define SDeviceEvalAssert(expression, condition) expression
#endif

/**
 * @brief Логирует состояние дескриптора.
 * @details Записывает состояние @p status в дескриптор @p handle и вызывает @ref SDeviceProcessLogStatus.
 * Дополнительные параметры (@p extras и @p extrasSize) устанавливаются в `NULL` и `0` соответственно.
 * @param handle Дескриптор, с которым должно быть ассоциировано логируемое состояние.
 * @param status Идентификатор состояния (int32_t).
 */
#define SDeviceLogStatus(handle, status) SDeviceLogStatusWithExtras(handle, status, NULL, 0)

/**
 * @brief Логирует состояние дескриптора с дополнительными данными.
 * @details Записывает состояние @p status в дескриптор @p handle и вызывает @ref SDeviceProcessLogStatus.
 * Также передает дополнительные параметры @p extras и @p extrasSize в @ref SDeviceProcessLogStatus.
 * @param handle Дескриптор, с которым должно быть ассоциировано логируемое состояние.
 * @param status Идентификатор состояния типа @ref SDeviceHandleStatus.
 * @param extras Указатель на дополнительные данные.
 * @param extrasSize Размер (в байтах) дополнительных данных.
 */
#if SDEVICE_USE_STATUS_LOG || defined(DOXYGEN)
   #define SDeviceLogStatusWithExtras(handle, status, extras, extrasSize) (                                            \
      {                                                                                                                \
         SDeviceCommonHandle *_mHandle = (SDeviceCommonHandle *)(handle);                                              \
         _mHandle->Header.LatestStatus = (status);                                                                     \
         SDeviceProcessLogStatus(_mHandle, extras, extrasSize);                                                        \
      })
#else
   #define SDeviceLogStatusWithExtras(handle, status, extras, extrasSize)                                              \
      ((SDeviceCommonHandle *)(handle))->Header.LatestStatus = (status)
#endif

/**
 * @brief Выбрасывает панику.
 * @details Записывает состояние @p panic в дескриптор @p handle и выбрасывает последний в виде паники.
 * @param handle Дескриптор, с которым должно быть ассоциировано выбрасываемая паника.
 * @param panic Идентификатор паники типа @ref SDeviceHandleStatus.
 */
#define SDevicePanic(handle, panic) (                                                                                  \
   {                                                                                                                   \
      SDeviceCommonHandle *_mHandle = (SDeviceCommonHandle *)(handle);                                                 \
      _mHandle->Header.LatestStatus = (panic);                                                                         \
      SDeviceProcessPanic(_mHandle);                                                                                   \
   })

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
 * @param[in] line Строка файла, в которой расположена проваленная проверка утверждения.
 */
#if !SDEVICE_USE_SIMPLE_ASSERT || defined(DOXYGEN)
void SDeviceProcessAssertFail(char *file, int line);
#else
void SDeviceProcessAssertFail(void);
#endif

/**
 * @brief Функция обработки запроса на логирование события.
 * @details Вызывается при запросе логирования макросом #SDeviceLogStatus.
 * @note Определена в виде слабого символа, реализация по-умолчанию - пустая функция.
 * @param[in] handle Дескриптор, ассоциированный с логируемым событием.
 * @param[in] extras Дополнительные пользовательские данные.
 * @param[in] extrasSize Размер (в байтах) дополнительных пользовательских данных.
 */
void SDeviceProcessLogStatus(const void *handle, const void *extras, size_t extrasSize);

/**
 * @brief Функция обработки паники.
 * @details Вызывается при выбрасывании паники макросом #SDevicePanic.
 * @note Определена в виде слабого символа, реализация по-умолчанию - вечный цикл.
 * @param[in] handle Дескриптор, ассоциированный с возникшей паникой.
 */
void SDeviceProcessPanic(const void *handle);

/** @} */
