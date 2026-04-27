#pragma once

#include <iso646.h>
#include <limits.h>
#include <assert.h>

#ifndef MIN
   #define MIN(value_a, value_b) (                                                                                     \
      {                                                                                                                \
         __auto_type _m_value_a = (value_a);                                                                           \
         __auto_type _m_value_b = (value_b);                                                                           \
                                                                                                                       \
         (_m_value_a < _m_value_b) ? _m_value_a : _m_value_b;                                                          \
      })
#endif /* MIN */

#ifndef MAX
   #define MAX(value_a, value_b) (                                                                                     \
      {                                                                                                                \
         __auto_type _m_value_a = (value_a);                                                                           \
         __auto_type _m_value_b = (value_b);                                                                           \
                                                                                                                       \
         (_m_value_a > _m_value_b) ? _m_value_a : _m_value_b;                                                          \
      })
#endif /* MAX */

#ifndef INSTANCE_OF
   #define INSTANCE_OF(type) ((type *)0)
#endif /* INSTANCE_OF */

#ifndef MEMBER_OF
   #define INSTANCE_MEMBER_OF(type, member) (INSTANCE_OF(type)->member)
#endif /* MEMBER_OF */

#ifndef SIZEOF_MEMBER
   #define SIZEOF_MEMBER(type, member) sizeof(INSTANCE_MEMBER_OF(type, member))
#endif /* SIZEOF_MEMBER */

#ifndef BIT_SIZEOF
   #define BIT_SIZEOF(type) (sizeof(type) * CHAR_BIT)
#endif /* BIT_SIZEOF */

#ifndef BIT_SIZEOF_MEMBER
   #define BIT_SIZEOF_MEMBER(type, member) BIT_SIZEOF(INSTANCE_MEMBER_OF(type, member))
#endif /* BIT_SIZEOF_MEMBER */

#ifndef LENGTHOF
   #define LENGTHOF(array) (sizeof(array) / sizeof(*array))
#endif /* LENGTHOF */

#ifndef FIRST
   #define FIRST(array) ((array)[0])
#endif /* FIRST */

#ifndef LAST
   #define LAST(array) ((array)[LENGTHOF(array) - 1])
#endif /* LAST */

#ifndef UNUSED_PARAMETER
   #define UNUSED_PARAMETER(parameter) (void)(parameter)
#endif /* UNUSED_PARAMETER */

#ifndef SET_BITS
   #define SET_BITS(value, bits) ((value) |= (bits))
#endif /* SET_BITS */

#ifndef CLEAR_BITS
   #define CLEAR_BITS(value, bits) ((value) &= ~(bits))
#endif /* CLEAR_BITS */

#ifndef READ_BITS
   #define READ_BITS(value, bits) ((value) & (bits))
#endif /* READ_BITS */

#ifndef WILL_ADD_INT_OVERFLOW
   #define WILL_ADD_INT_OVERFLOW(value_a, value_b, type)                                                               \
      __builtin_add_overflow_p(value_a, value_b, (type)0)
#endif /* WILL_ADD_INT_OVERFLOW */

#ifndef WILL_SUB_INT_OVERFLOW
   #define WILL_SUB_INT_OVERFLOW(value_a, value_b, type)                                                               \
      __builtin_sub_overflow_p(value_a, value_b, (type)0)
#endif /* WILL_SUB_INT_OVERFLOW */

#ifndef WILL_MUL_INT_OVERFLOW
   #define WILL_MUL_INT_OVERFLOW(value_a, value_b, type)                                                               \
      __builtin_mul_overflow_p(value_a, value_b, (type)0)
#endif /* WILL_MUL_INT_OVERFLOW */

#ifndef ADD_INT_CHECKED
   #define ADD_INT_CHECKED(value_a, value_b, result)                                                                   \
      (not __builtin_add_overflow(value_a, value_b, result))
#endif /* ADD_INT_CHECKED */

#ifndef SUB_INT_CHECKED
   #define SUB_INT_CHECKED(value_a, value_b, result)                                                                   \
      (not __builtin_sub_overflow(value_a, value_b, result))
#endif /* SUB_INT_CHECKED */

#ifndef MUL_INT_CHECKED
   #define MUL_INT_CHECKED(value_a, value_b, result)                                                                   \
      (not __builtin_mul_overflow(value_a, value_b, result))
#endif /* MUL_INT_CHECKED */

#ifndef HAS_VALUE_UNSIGNED_TYPE
   #define HAS_VALUE_UNSIGNED_TYPE(value) (((typeof(value))-1) >= 0)
#endif /* HAS_VALUE_UNSIGNED_TYPE */

#ifndef HAS_VALUE_SIGNED_TYPE
   #define HAS_VALUE_SIGNED_TYPE(value) (((typeof(value))-1) < 0)
#endif /* HAS_VALUE_SIGNED_TYPE */

#ifndef CEIL_UINT_DIV
   #define CEIL_UINT_DIV(dividend, divisor) (                                                                          \
      {                                                                                                                \
         __auto_type _m_dividend = (dividend);                                                                         \
         __auto_type _m_divisor  = (divisor);                                                                          \
                                                                                                                       \
         static_assert(HAS_VALUE_UNSIGNED_TYPE(_m_dividend));                                                          \
         static_assert(HAS_VALUE_UNSIGNED_TYPE(_m_divisor));                                                           \
                                                                                                                       \
        _m_dividend / _m_divisor + (_m_dividend % _m_divisor > 0);                                                     \
      })
#endif /* CEIL_UINT_DIV */

#ifndef SET_AS_VOLATILE
   #define SET_AS_VOLATILE(target, value) (*(volatile typeof(target) *)&(target) = (value))
#endif /* SET_AS_VOLATILE */

#ifndef GET_AS_VOLATILE
   #define GET_AS_VOLATILE(target) (*(volatile typeof(target) *)&(target))
#endif /* GET_AS_VOLATILE */
