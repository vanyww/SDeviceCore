/**
 * @file SDeviceCore/assert.h
 * @brief Инструменты проверки утверждений.
 */

#pragma once

#include "config.h"
#include "core.h"

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
 * @brief Функция обработки проваленной проверки утверждения.
 * @details Вызывается при провале проверки утверждения макросами:
 * - #SDeviceAssert
 * - #SDeviceEvalAssert
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

/** @} */
