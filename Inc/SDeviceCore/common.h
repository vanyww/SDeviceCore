/**
 * @file SDeviceCore/common.h
 * @brief Различные распространенные общие операции.
 * @details Реализация часто применяемых при разработке модулей и не имеющих к ним прямого отношения операций.
 */

#pragma once

#include <limits.h>
#include <assert.h>

/**
 * @defgroup sdevice_core_common Общие операции
 * @brief @copybrief SDeviceCore/common.h
 * @details @copydetails SDeviceCore/common.h
 * @{
 */

/**
 * @brief Вычисляет минимум из двух значений.
 * @details
 * @note Использует braced-groups для предотвращения повторного исполнения передаваемых выражений.
 * @param valueI0 Первое значение.
 * @param valueI1 Второе значение.
 * @return Минимум из @p valueI0 и @p valueI1.
 */
#if !defined(MIN) || defined(DOXYGEN)
   #define MIN(valueI0, valueI1) (                                                                                     \
      {                                                                                                                \
         __auto_type _mValueI0 = (valueI0);                                                                            \
         __auto_type _mValueI1 = (valueI1);                                                                            \
                                                                                                                       \
         (_mValueI0 < _mValueI1) ? _mValueI0 : _mValueI1;                                                              \
      })
#endif

/**
 * @brief Вычисляет максимум из двух значений.
 * @details
 * @note Использует braced-groups для предотвращения повторного исполнения передаваемых выражений.
 * @param valueI0 Первое значение.
 * @param valueI1 Второе значение.
 * @return Максимум из @p valueI0 и @p valueI1.
 */
#if !defined(MAX) || defined(DOXYGEN)
   #define MAX(valueI0, valueI1) (                                                                                     \
      {                                                                                                                \
         __auto_type _mValue_0 = (valueI0);                                                                            \
         __auto_type _mValue_1 = (valueI1);                                                                            \
                                                                                                                       \
         (_mValue_0 > _mValue_1) ? _mValue_0 : _mValue_1;                                                              \
      })
#endif

/**
 * @brief Создает rvalue-значение указателя на тип.
 * @details
 * @note Для использования с sizeof-выражениями.
 * @param type Тип.
 * @return rvalue-значение указателя на тип @p type.
 */
#if !defined(INSTANCE_OF) || defined(DOXYGEN)
   #define INSTANCE_OF(type) ((type *)0)
#endif

/**
 * @brief Создает rvalue-значение члена типа.
 * @details
 * @note Для использования с sizeof-выражениями.
 * @param type Тип.
 * @param member Член.
 * @return rvalue-значение члена @p member указателя на тип @p type.
 */
#if !defined(MEMBER_OF) || defined(DOXYGEN)
   #define INSTANCE_MEMBER_OF(type, member) (INSTANCE_OF(type)->member)
#endif

/**
 * @brief Вычисляет размер (в байтах) члена типа данных.
 * @details Пример использования:
 * @include common/sizeof_member.c
 * @param type Тип данных.
 * @param member Имя члена типа данных @p type.
 * @return Размер (в байтах) члена @p member типа данных @p type.
 */
#if !defined(SIZEOF_MEMBER) || defined(DOXYGEN)
   #define SIZEOF_MEMBER(type, member) (sizeof(INSTANCE_MEMBER_OF(type, member)))
#endif

/**
 * @brief Вычисляет размер (в битах) типа данных.
 * @param type Тип данных или переменная (тогда будет использован ее тип данных).
 * @return Размер (в битах) типа данных @p value.
 */
#if !defined(BIT_SIZEOF) || defined(DOXYGEN)
   #define BIT_SIZEOF(type) (sizeof(type) * CHAR_BIT)
#endif

/**
 * @brief Вычисляет размер (в битах) члена типа данных.
 * @param type Тип данных.
 * @param member Имя члена типа данных @p type.
 * @return Размер (в битах) члена @p member типа данных @p type.
 */
#if !defined(BIT_SIZEOF_MEMBER) || defined(DOXYGEN)
   #define BIT_SIZEOF_MEMBER(type, member) (SIZEOF_MEMBER(type, member) * CHAR_BIT)
#endif

/**
 * @brief Вычисляет длину (количество элементов) статического массива или VLA.
 * @param array Статический массив или VLA.
 * @return Длина (количество элементов) массива @p array.
 */
#if !defined(LENGTHOF) || defined(DOXYGEN)
   #define LENGTHOF(array) (sizeof(array) / sizeof(*array))
#endif

/**
 * @brief Получает первый элемент статического массива или VLA.
 * @param array Статический массив или VLA.
 * @return Первый элемент массива @p array.
 */
#if !defined(FIRST) || defined(DOXYGEN)
   #define FIRST(array) ((array)[0])
#endif

/**
 * @brief Получает последний элемент статического массива или VLA.
 * @param array Статический массив или VLA.
 * @return Последний элемент массива @p array.
 */
#if !defined(LAST) || defined(DOXYGEN)
   #define LAST(array) ((array)[LENGTHOF(array) - 1])
#endif

/**
 * @brief Указывает на возможно неиспользуемый параметр функции.
 * @details Предотвращает возникновение предупреждения о том, что параметр @p parameter не используется кодом функции.
 * @n Пример использования:
 * @include common/unused_parameter.c
 * @param parameter Параметр функции.
 */
#if !defined(UNUSED_PARAMETER) || defined(DOXYGEN)
   #define UNUSED_PARAMETER(parameter) (void)(parameter)
#endif

/**
 * @brief Устанавливает указанные биты в значении.
 * @param value Значение.
 * @param bits Биты, которые необходимо установить в @p value.
 * @return Копия значения @p value, в котором установлены биты @p bits.
 */
#if !defined(SET_BITS) || defined(DOXYGEN)
   #define SET_BITS(value, bits) ((value) |= (bits))
#endif

/**
 * @brief Сбрасывает указанные биты в значении.
 * @param value Значение.
 * @param bits Биты, которые необходимо сбросить в @p value.
 * @return Копия значения @p value, в котором сброшены биты @p bits.
 */
#if !defined(CLEAR_BITS) || defined(DOXYGEN)
   #define CLEAR_BITS(value, bits) ((value) &= ~(bits))
#endif

/**
 * @brief Читает указанные биты из значения.
 * @param value Значение.
 * @param bits Биты, которые необходимо прочитать из @p value.
 * @return Биты @p bits значения @p value.
 */
#if !defined(READ_BITS) || defined(DOXYGEN)
   #define READ_BITS(value, bits) ((value) & (bits))
#endif

/**
 * @brief Проверяет, вызовет ли целочисленное сложение переполнение.
 * @param valueI0 Первое значение.
 * @param valueI1 Второе значение.
 * @return `true`, если операция @p valueI0 + @p valueI1 вызовет переполнение, иначе - `false`.
 */
#if !defined(WILL_INT_ADD_OVERFLOW) || defined(DOXYGEN)
   #define WILL_INT_ADD_OVERFLOW(valueI0, valueI1)                                                                     \
      __builtin_add_overflow_p(valueI0, valueI1, (typeof((valueI0) + (valueI1)))0)
#endif

/**
 * @brief Проверяет, вызовет ли целочисленное вычитание переполнение.
 * @param valueI0 Уменьшаемое.
 * @param valueI1 Вычитаемое.
 * @return `true`, если операция @p valueI0 - @p valueI1 вызовет переполнение, иначе - `false`.
 */
#if !defined(WILL_INT_SUB_OVERFLOW) || defined(DOXYGEN)
   #define WILL_INT_SUB_OVERFLOW(valueI0, valueI1)                                                                     \
      __builtin_sub_overflow_p(valueI0, valueI1, (typeof((valueI0) - (valueI1)))0)
#endif

/**
 * @brief Проверяет, вызовет ли целочисленное умножение переполнение.
 * @param valueI0 Первое значение.
 * @param valueI1 Второе значение.
 * @return `true`, если операция @p valueI0 * @p valueI1 вызовет переполнение, иначе - `false`.
 */
#if !defined(WILL_INT_MUL_OVERFLOW) || defined(DOXYGEN)
   #define WILL_INT_MUL_OVERFLOW(valueI0, valueI1)                                                                     \
      __builtin_mul_overflow_p(valueI0, valueI1, (typeof((valueI0) * (valueI1)))0)
#endif

/**
 * @brief Производит целочисленное сложение с проверкой на переполнение.
 * @param valueI0 Первое значение.
 * @param valueI1 Второе значение.
 * @param result Результат исполнения операции @p valueI0 + @p valueI1.
 * @return `true`, если операция @p valueI0 + @p valueI1 не вызвала переполнения, иначе - `false`.
 */
#if !defined(TRY_ADD_INT_CHECKED) || defined(DOXYGEN)
   #define TRY_ADD_INT_CHECKED(valueI0, valueI1, result) (!__builtin_add_overflow(valueI0, valueI1, result))
#endif

/**
 * @brief Производит целочисленное вычитание с проверкой на переполнение.
 * @param valueI0 Уменьшаемое.
 * @param valueI1 Вычитаемое.
 * @param result Результат исполнения операции @p valueI0 - @p valueI1.
 * @return `true`, если операция @p valueI0 - @p valueI1 не вызвала переполнения, иначе - `false`.
 */
#if !defined(TRY_SUB_INT_CHECKED) || defined(DOXYGEN)
   #define TRY_SUB_INT_CHECKED(valueI0, valueI1, result) (!__builtin_sub_overflow(valueI0, valueI1, result))
#endif

/**
 * @brief Производит целочисленное умножение с проверкой на переполнение.
 * @param valueI0 Первое значение.
 * @param valueI1 Второе значение.
 * @param result Результат исполнения операции @p valueI0 * @p valueI1.
 * @return `true`, если операция @p valueI0 * @p valueI1 не вызвала переполнения, иначе - `false`.
 */
#if !defined(TRY_MUL_INT_CHECKED) || defined(DOXYGEN)
   #define TRY_MUL_INT_CHECKED(valueI0, valueI1, result) (!__builtin_mul_overflow(valueI0, valueI1, result))
#endif

/**
 * @brief Проверяет, является ли тип переданного значения беззнаковым.
 * @param value Значение.
 * @return `true`, если тип значения @p value - беззнаковый, иначе - `false`.
 */
#if !defined(HAS_VALUE_UNSIGNED_TYPE) || defined(DOXYGEN)
   #define HAS_VALUE_UNSIGNED_TYPE(value) (((typeof(value))-1) >= 0)
#endif

/**
 * @brief Проверяет, является ли тип переданного значения знаковым.
 * @param value Значение.
 * @return `true`, если тип значения @p value - знаковый, иначе - `false`.
 */
#if !defined(HAS_VALUE_SIGNED_TYPE) || defined(DOXYGEN)
   #define HAS_VALUE_SIGNED_TYPE(value) (((typeof(value))-1) < 0)
#endif

/**
 * @brief Производит беззнаковое целочисленное деление с округлением вверх.
 * @details
 * @note Использует braced-groups для предотвращения повторного исполнения передаваемых выражений.
 * @param dividend Делимое.
 * @param divisor Делитель.
 * @return Результат исполнения операции ⌈ @p dividend / @p divisor ⌉.
 */
#if !defined(CEIL_UINT_DIV) || defined(DOXYGEN)
   #define CEIL_UINT_DIV(dividend, divisor) (                                                                          \
      {                                                                                                                \
         __auto_type _mDividend = (dividend);                                                                          \
         __auto_type _mDivisor  = (divisor);                                                                           \
                                                                                                                       \
         static_assert(HAS_VALUE_UNSIGNED_TYPE(_mDividend));                                                           \
         static_assert(HAS_VALUE_UNSIGNED_TYPE(_mDivisor));                                                            \
                                                                                                                       \
         _mDividend / _mDivisor + !!(_mDividend % _mDivisor);                                                          \
      })
#endif

/**
 * @brief Производит запись переменной так, как если бы она имела квалификатор "volatile".
 * @details
 * @param dividend Переменная.
 * @param divisor Значение.
 * @return Записанное значение.
 */
#if !defined(SET_AS_VOLATILE) || defined(DOXYGEN)
   #define SET_AS_VOLATILE(target, value) (*(volatile typeof(target) *)&(target) = (value))
#endif

/**
 * @brief Производит чтение переменной так, как если бы она имела квалификатор "volatile".
 * @details
 * @param dividend Переменная.
 * @return Прочитанное значение.
 */
#if !defined(GET_AS_VOLATILE) || defined(DOXYGEN)
   #define GET_AS_VOLATILE(target) (*(volatile typeof(target) *)&(target))
#endif

/** @} */
