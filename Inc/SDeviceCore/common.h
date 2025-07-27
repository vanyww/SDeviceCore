#pragma once

#include <limits.h>
#include <assert.h>

#if !defined(MIN)
   #define MIN(valueS0, valueS1) (                                                                                     \
      {                                                                                                                \
         __auto_type _mValueS0 = (valueS0);                                                                            \
         __auto_type _mValueS1 = (valueS1);                                                                            \
                                                                                                                       \
         (_mValueS0 < _mValueS1) ? _mValueS0 : _mValueS1;                                                              \
      })
#endif

#if !defined(MAX)
   #define MAX(valueS0, valueS1) (                                                                                     \
      {                                                                                                                \
         __auto_type _mValueS0 = (valueS0);                                                                            \
         __auto_type _mValueS1 = (valueS1);                                                                            \
                                                                                                                       \
         (_mValueS0 > _mValueS1) ? _mValueS0 : _mValueS1;                                                              \
      })
#endif

#if !defined(INSTANCE_OF)
   #define INSTANCE_OF(type) ((type *)0)
#endif

#if !defined(MEMBER_OF)
   #define INSTANCE_MEMBER_OF(type, member) (INSTANCE_OF(type)->member)
#endif

#if !defined(SIZEOF_MEMBER)
   #define SIZEOF_MEMBER(type, member) (sizeof(INSTANCE_MEMBER_OF(type, member)))
#endif

#if !defined(BIT_SIZEOF)
   #define BIT_SIZEOF(type) (sizeof(type) * CHAR_BIT)
#endif

#if !defined(BIT_SIZEOF_MEMBER)
   #define BIT_SIZEOF_MEMBER(type, member) (SIZEOF_MEMBER(type, member) * CHAR_BIT)
#endif

#if !defined(LENGTHOF)
   #define LENGTHOF(array) (sizeof(array) / sizeof(*array))
#endif

#if !defined(FIRST)
   #define FIRST(array) ((array)[0])
#endif

#if !defined(LAST)
   #define LAST(array) ((array)[LENGTHOF(array) - 1])
#endif

#if !defined(UNUSED_PARAMETER)
   #define UNUSED_PARAMETER(parameter) (void)(parameter)
#endif

#if !defined(SET_BITS)
   #define SET_BITS(value, bits) ((value) |= (bits))
#endif

#if !defined(CLEAR_BITS)
   #define CLEAR_BITS(value, bits) ((value) &= ~(bits))
#endif

#if !defined(READ_BITS)
   #define READ_BITS(value, bits) ((value) & (bits))
#endif

#if !defined(WILL_ADD_INT_OVERFLOW)
   #define WILL_ADD_INT_OVERFLOW(valueS0, valueS1, type) __builtin_add_overflow_p(valueS0, valueS1, (type)0)
#endif

#if !defined(WILL_SUB_INT_OVERFLOW)
   #define WILL_SUB_INT_OVERFLOW(valueS0, valueS1, type) __builtin_sub_overflow_p(valueS0, valueS1, (type)0)
#endif

#if !defined(WILL_MUL_INT_OVERFLOW)
   #define WILL_MUL_INT_OVERFLOW(valueS0, valueS1, type) __builtin_mul_overflow_p(valueS0, valueS1, (type)0)
#endif

#if !defined(ADD_INT_CHECKED)
   #define ADD_INT_CHECKED(valueS0, valueS1, result) (!__builtin_add_overflow(valueS0, valueS1, result))
#endif

#if !defined(SUB_INT_CHECKED)
   #define SUB_INT_CHECKED(valueS0, valueS1, result) (!__builtin_sub_overflow(valueS0, valueS1, result))
#endif

#if !defined(MUL_INT_CHECKED)
   #define MUL_INT_CHECKED(valueS0, valueS1, result) (!__builtin_mul_overflow(valueS0, valueS1, result))
#endif

#if !defined(HAS_VALUE_UNSIGNED_TYPE)
   #define HAS_VALUE_UNSIGNED_TYPE(value) (((typeof(value))-1) >= 0)
#endif

#if !defined(HAS_VALUE_SIGNED_TYPE)
   #define HAS_VALUE_SIGNED_TYPE(value) (((typeof(value))-1) < 0)
#endif

#if !defined(CEIL_UINT_DIV)
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

#if !defined(SET_AS_VOLATILE)
   #define SET_AS_VOLATILE(target, value) (*(volatile typeof(target) *)&(target) = (value))
#endif

#if !defined(GET_AS_VOLATILE)
   #define GET_AS_VOLATILE(target) (*(volatile typeof(target) *)&(target))
#endif
