#pragma once

#include <limits.h>
#include <assert.h>

#if !defined(MIN) || defined(DOXYGEN)
   #define MIN(valueS0, valueS1) (                                                                                     \
      {                                                                                                                \
         __auto_type _mValueS0 = (valueS0);                                                                            \
         __auto_type _mValueS1 = (valueS1);                                                                            \
                                                                                                                       \
         (_mValueS0 < _mValueS1) ? _mValueS0 : _mValueS1;                                                              \
      })
#endif

#if !defined(MAX) || defined(DOXYGEN)
   #define MAX(valueS0, valueS1) (                                                                                     \
      {                                                                                                                \
         __auto_type _mValueS0 = (valueS0);                                                                            \
         __auto_type _mValueS1 = (valueS1);                                                                            \
                                                                                                                       \
         (_mValueS0 > _mValueS1) ? _mValueS0 : _mValueS1;                                                              \
      })
#endif

#if !defined(INSTANCE_OF) || defined(DOXYGEN)
   #define INSTANCE_OF(type) ((type *)0)
#endif

#if !defined(MEMBER_OF) || defined(DOXYGEN)
   #define INSTANCE_MEMBER_OF(type, member) (INSTANCE_OF(type)->member)
#endif

#if !defined(SIZEOF_MEMBER) || defined(DOXYGEN)
   #define SIZEOF_MEMBER(type, member) (sizeof(INSTANCE_MEMBER_OF(type, member)))
#endif

#if !defined(BIT_SIZEOF) || defined(DOXYGEN)
   #define BIT_SIZEOF(type) (sizeof(type) * CHAR_BIT)
#endif

#if !defined(BIT_SIZEOF_MEMBER) || defined(DOXYGEN)
   #define BIT_SIZEOF_MEMBER(type, member) (SIZEOF_MEMBER(type, member) * CHAR_BIT)
#endif

#if !defined(LENGTHOF) || defined(DOXYGEN)
   #define LENGTHOF(array) (sizeof(array) / sizeof(*array))
#endif

#if !defined(FIRST) || defined(DOXYGEN)
   #define FIRST(array) ((array)[0])
#endif

#if !defined(LAST) || defined(DOXYGEN)
   #define LAST(array) ((array)[LENGTHOF(array) - 1])
#endif

#if !defined(UNUSED_PARAMETER) || defined(DOXYGEN)
   #define UNUSED_PARAMETER(parameter) (void)(parameter)
#endif

#if !defined(SET_BITS) || defined(DOXYGEN)
   #define SET_BITS(value, bits) ((value) |= (bits))
#endif

#if !defined(CLEAR_BITS) || defined(DOXYGEN)
   #define CLEAR_BITS(value, bits) ((value) &= ~(bits))
#endif

#if !defined(READ_BITS) || defined(DOXYGEN)
   #define READ_BITS(value, bits) ((value) & (bits))
#endif

#if !defined(WILL_ADD_INT_OVERFLOW) || defined(DOXYGEN)
   #define WILL_ADD_INT_OVERFLOW(valueS0, valueS1, type)                                                               \
      __builtin_add_overflow_p(valueS0, valueS1, (type)0)
#endif

#if !defined(WILL_SUB_INT_OVERFLOW) || defined(DOXYGEN)
   #define WILL_SUB_INT_OVERFLOW(valueS0, valueS1, type)                                                               \
      __builtin_sub_overflow_p(valueS0, valueS1, (type)0)
#endif

#if !defined(WILL_MUL_INT_OVERFLOW) || defined(DOXYGEN)
   #define WILL_MUL_INT_OVERFLOW(valueS0, valueS1, type)                                                               \
      __builtin_mul_overflow_p(valueS0, valueS1, (type)0)
#endif

#if !defined(ADD_INT_CHECKED) || defined(DOXYGEN)
   #define ADD_INT_CHECKED(valueS0, valueS1, result) (!__builtin_add_overflow(valueS0, valueS1, result))
#endif

#if !defined(SUB_INT_CHECKED) || defined(DOXYGEN)
   #define SUB_INT_CHECKED(valueS0, valueS1, result) (!__builtin_sub_overflow(valueS0, valueS1, result))
#endif

#if !defined(MUL_INT_CHECKED) || defined(DOXYGEN)
   #define MUL_INT_CHECKED(valueS0, valueS1, result) (!__builtin_mul_overflow(valueS0, valueS1, result))
#endif

#if !defined(HAS_VALUE_UNSIGNED_TYPE) || defined(DOXYGEN)
   #define HAS_VALUE_UNSIGNED_TYPE(value) (((typeof(value))-1) >= 0)
#endif

#if !defined(HAS_VALUE_SIGNED_TYPE) || defined(DOXYGEN)
   #define HAS_VALUE_SIGNED_TYPE(value) (((typeof(value))-1) < 0)
#endif

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

#if !defined(SET_AS_VOLATILE) || defined(DOXYGEN)
   #define SET_AS_VOLATILE(target, value) (*(volatile typeof(target) *)&(target) = (value))
#endif

#if !defined(GET_AS_VOLATILE) || defined(DOXYGEN)
   #define GET_AS_VOLATILE(target) (*(volatile typeof(target) *)&(target))
#endif
