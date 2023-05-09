#pragma once

#include <limits.h>

/**
 * @file common.h
 * @brief Различные распространенные общие операции.
 * @details Реализация часто применяемых при разработке модулей и не имеющих к ним прямого отношения операций.
 */

/**
 * @defgroup common_operations Общие операции
 * @brief @copybrief common.h
 * @brief @copydetails common.h
 * @{
 */

#if !defined likely || defined DOXYGEN
/**
 * @brief Указывает на вероятную истинность выражения.
 * @details Позволяет компилятору лучше оптимизировать код, использующий условные выражения.
 * @n Пример использования:
 * @include common/likely.c
 * @param expression Выражение, истинность которого утверждается.
 * @return Результат выполнения выражения @p expression.
 */
#define likely(expression) __builtin_expect(!!(expression), 1)
#endif

#if !defined unlikely || defined DOXYGEN
/**
 * @brief Указывает на вероятную ложность выражения.
 * @details Позволяет компилятору лучше оптимизировать код, использующий условные выражения.
 * @n Пример использования:
 * @include common/unlikely.c
 * @param expression Выражение, ложность которого утверждается.
 * @return Результат выполнения выражения @p expression.
 */
#define unlikely(expression) __builtin_expect(!!(expression), 0)
#endif

#if !defined MIN || defined DOXYGEN
/**
 * @brief Вычисляет минимум из двух значений.
 * @details
 * @note Использует braced-groups для предотвращения повторного исполнения передаваемых параметров.
 * @param value_0 Первое значение.
 * @param value_1 Второе значение.
 * @return Минимум из @p value_0 и @p value_1.
 */
#define MIN(value_0, value_1) (                                                                                        \
{                                                                                                                      \
   __auto_type _value_0 = (value_0);                                                                                   \
   __auto_type _value_1 = (value_1);                                                                                   \
   _value_0 < _value_1 ? _value_0 : _value_1;                                                                          \
})
#endif

#if !defined MAX || defined DOXYGEN
/**
 * @brief Вычисляет максимум из двух значений.
 * @details
 * @note Использует braced-groups для предотвращения повторного исполнения передаваемых параметров.
 * @param value_0 Первое значение.
 * @param value_1 Второе значение.
 * @return Максимум из @p value_0 и @p value_1.
 */
#define MAX(value_0, value_1) (                                                                                        \
{                                                                                                                      \
   __auto_type _value_0 = (value_0);                                                                                   \
   __auto_type _value_1 = (value_1);                                                                                   \
   _value_0 > _value_1 ? _value_0 : _value_1;                                                                          \
})
#endif

#if !defined SIZEOF_MEMBER || defined DOXYGEN
/**
 * @brief Вычисляет размер (в байтах) члена типа данных.
 * @details Пример использования:
 * @include common/sizeof_member.c
 * @param type Тип данных.
 * @param member Имя члена типа данных @p type.
 * @return Размер (в байтах) члена @p member типа данных @p type.
 */
#define SIZEOF_MEMBER(type, member) (sizeof(((type *)0)->member))
#endif

#if !defined BIT_SIZEOF || defined DOXYGEN
/**
 * @brief Вычисляет размер (в битах) типа данных.
 * @param type Тип данных или переменная (будет использован ее тип).
 * @return Размер (в битах) типа данных @p value.
 */
#define BIT_SIZEOF(type) (sizeof(type) * CHAR_BIT)
#endif

#if !defined BIT_SIZEOF_MEMBER || defined DOXYGEN
/**
 * @brief Вычисляет размер (в битах) члена типа данных.
 * @param type Тип данных.
 * @param member Имя члена типа данных @p type.
 * @return Размер (в битах) члена @p member типа данных @p type.
 */
#define BIT_SIZEOF_MEMBER(type, member) (SIZEOF_MEMBER(type, member) * CHAR_BIT)
#endif

#if !defined LENGTHOF || defined DOXYGEN
/**
 * @brief Вычисляет длину (количество элементов) статического массива.
 * @param array Статический массив.
 * @return Длина (количество элементов) массива @p array.
 */
#define LENGTHOF(array) (sizeof(array) / sizeof(*array))
#endif

#if !defined UNUSED_PARAMETER || defined DOXYGEN
/**
 * @brief Указывает на возможно неиспользуемый параметр функции.
 * @details Предотвращает возникновение предупреждения о том, что параметр @p parameter не используется в коде функции.
 * @n Пример использования:
 * @include common/unused_parameter.c
 * @param parameter Параметр функции.
 */
#define UNUSED_PARAMETER(parameter) (void)(parameter)
#endif

#if !defined SET_BITS || defined DOXYGEN
/**
 * @brief Устанавливает указанные биты в значении.
 * @param value Значение.
 * @param bits Биты, которые необходимо установить в @p value.
 */
#define SET_BITS(value, bits) ((value) |= (bits))
#endif

#if !defined CLEAR_BITS || defined DOXYGEN
/**
 * @brief Сбрасывает указанные биты в значении.
 * @param value Значение.
 * @param bits Биты, которые необходимо сбросить в @p value.
 */
#define CLEAR_BITS(value, bits) ((value) &= ~(bits))
#endif

#if !defined READ_BITS || defined DOXYGEN
/**
 * @brief Читает указанные биты из значения.
 * @param value Значение.
 * @param bits Биты, которые необходимо прочитать из @p value.
 * @return Биты @p bits значения @p value.
 */
#define READ_BITS(value, bits) ((value) & (bits))
#endif

/** @} */
