/**
 * @file common.h
 * @brief Различные распространенные общие операции.
 * @details Реализация часто применяемых при разработке модулей и не имеющих к ним прямого отношения операций.
 */

#pragma once

#include <limits.h>

/**
 * @defgroup common_operations Общие операции
 * @brief @copybrief common.h
 * @details @copydetails common.h
 * @{
 */

/**
 * @brief Указывает на вероятную истинность выражения.
 * @details Позволяет компилятору лучше оптимизировать код, использующий условные выражения.
 * @n Пример использования:
 * @include common/likely.c
 * @param expression Выражение, на истинность которого указывается.
 * @return Результат выполнения выражения @p expression.
 */
#if !defined likely || defined DOXYGEN
#define likely(expression) __builtin_expect(!!(expression), 1)
#endif

/**
 * @brief Указывает на вероятную ложность выражения.
 * @details Позволяет компилятору лучше оптимизировать код, использующий условные выражения.
 * @n Пример использования:
 * @include common/unlikely.c
 * @param expression Выражение, на ложность которого указывается.
 * @return Результат выполнения выражения @p expression.
 */
#if !defined unlikely || defined DOXYGEN
#define unlikely(expression) __builtin_expect(!!(expression), 0)
#endif

/**
 * @brief Вычисляет минимум из двух значений.
 * @details
 * @note Использует braced-groups для предотвращения повторного исполнения передаваемых выражений.
 * @param value_0 Первое значение.
 * @param value_1 Второе значение.
 * @return Минимум из @p value_0 и @p value_1.
 */
#if !defined MIN || defined DOXYGEN
#define MIN(value_0, value_1) (                                                                                        \
{                                                                                                                      \
   __auto_type _value_0 = (value_0);                                                                                   \
   __auto_type _value_1 = (value_1);                                                                                   \
   _value_0 < _value_1 ? _value_0 : _value_1;                                                                          \
})
#endif

/**
 * @brief Вычисляет максимум из двух значений.
 * @details
 * @note Использует braced-groups для предотвращения повторного исполнения передаваемых выражений.
 * @param value_0 Первое значение.
 * @param value_1 Второе значение.
 * @return Максимум из @p value_0 и @p value_1.
 */
#if !defined MAX || defined DOXYGEN
#define MAX(value_0, value_1) (                                                                                        \
{                                                                                                                      \
   __auto_type _value_0 = (value_0);                                                                                   \
   __auto_type _value_1 = (value_1);                                                                                   \
   _value_0 > _value_1 ? _value_0 : _value_1;                                                                          \
})
#endif

/**
 * @brief Вычисляет размер (в байтах) члена типа данных.
 * @details Пример использования:
 * @include common/sizeof_member.c
 * @param type Тип данных.
 * @param member Имя члена типа данных @p type.
 * @return Размер (в байтах) члена @p member типа данных @p type.
 */
#if !defined SIZEOF_MEMBER || defined DOXYGEN
#define SIZEOF_MEMBER(type, member) (sizeof(((type *)0)->member))
#endif

/**
 * @brief Вычисляет размер (в битах) типа данных.
 * @param type Тип данных или переменная (тогда будет использован ее тип данных).
 * @return Размер (в битах) типа данных @p value.
 */
#if !defined BIT_SIZEOF || defined DOXYGEN
#define BIT_SIZEOF(type) (sizeof(type) * CHAR_BIT)
#endif

/**
 * @brief Вычисляет размер (в битах) члена типа данных.
 * @param type Тип данных.
 * @param member Имя члена типа данных @p type.
 * @return Размер (в битах) члена @p member типа данных @p type.
 */
#if !defined BIT_SIZEOF_MEMBER || defined DOXYGEN
#define BIT_SIZEOF_MEMBER(type, member) (SIZEOF_MEMBER(type, member) * CHAR_BIT)
#endif

/**
 * @brief Вычисляет длину (количество элементов) статического массива или VLA.
 * @param array Статический массив или VLA.
 * @return Длина (количество элементов) массива @p array.
 */
#if !defined LENGTHOF || defined DOXYGEN
#define LENGTHOF(array) (sizeof(array) / sizeof(*array))
#endif

/**
 * @brief Указывает на возможно неиспользуемый параметр функции.
 * @details Предотвращает возникновение предупреждения о том, что параметр @p parameter не используется кодом функции.
 * @n Пример использования:
 * @include common/unused_parameter.c
 * @param parameter Параметр функции.
 */
#if !defined UNUSED_PARAMETER || defined DOXYGEN
#define UNUSED_PARAMETER(parameter) (void)(parameter)
#endif

/**
 * @brief Устанавливает указанные биты в значении.
 * @param value Значение.
 * @param bits Биты, которые необходимо установить в @p value.
 * @return Копия значения @p value, в котором установлены биты @p bits.
 */
#if !defined SET_BITS || defined DOXYGEN
#define SET_BITS(value, bits) ((value) |= (bits))
#endif

/**
 * @brief Сбрасывает указанные биты в значении.
 * @param value Значение.
 * @param bits Биты, которые необходимо сбросить в @p value.
 * @return Копия значения @p value, в котором сброшены биты @p bits.
 */
#if !defined CLEAR_BITS || defined DOXYGEN
#define CLEAR_BITS(value, bits) ((value) &= ~(bits))
#endif

/**
 * @brief Читает указанные биты из значения.
 * @param value Значение.
 * @param bits Биты, которые необходимо прочитать из @p value.
 * @return Биты @p bits значения @p value.
 */
#if !defined READ_BITS || defined DOXYGEN
#define READ_BITS(value, bits) ((value) & (bits))
#endif

#define WILL_INT_ADD_OVERFLOW(value_0, value_1)                                                                        \
   __builtin_add_overflow_p(value_0, value_1, (typeof((value_0) + (value_1)))0)

#define WILL_INT_SUB_OVERFLOW(value_0, value_1)                                                                        \
   __builtin_sub_overflow_p(value_0, value_1, (typeof((value_0) - (value_1)))0)

#define WILL_INT_MUL_OVERFLOW(value_0, value_1)                                                                        \
   __builtin_mul_overflow_p(value_0, value_1, (typeof((value_0) * (value_1)))0)

#define TRY_ADD_INT_CHECKED(value_0, value_1, result) (!__builtin_add_overflow(value_0, value_1, result))

#define TRY_SUB_INT_CHECKED(value_0, value_1, result) (!__builtin_sub_overflow(value_0, value_1, result))

#define TRY_MUL_INT_CHECKED(value_0, value_1, result) (!__builtin_mul_overflow(value_0, value_1, result))

/** @} */
