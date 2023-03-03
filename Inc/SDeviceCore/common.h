#pragma once

#include <limits.h>

#ifndef likely
#define likely(expression) __builtin_expect(!!(expression), 1)
#endif

#ifndef unlikely
#define unlikely(expression) __builtin_expect(!!(expression), 0)
#endif

#ifndef MIN
#define MIN(value_0, value_1) (                                                                                        \
{                                                                                                                      \
   __auto_type $value_0 = (value_0);                                                                                   \
   __auto_type $value_1 = (value_1);                                                                                   \
   $value_0 < $value_1 ? $value_0 : $value_1;                                                                          \
})
#endif

#ifndef MAX
#define MAX(value_0, value_1) (                                                                                        \
{                                                                                                                      \
   __auto_type $value_0 = (value_0);                                                                                   \
   __auto_type $value_1 = (value_1);                                                                                   \
   $value_0 > $value_1 ? $value_0 : $value_1;                                                                          \
})
#endif

#ifndef SIZEOF_MEMBER
#define SIZEOF_MEMBER(type, member) (sizeof(((type *)0)->member))
#endif

#ifndef BIT_SIZEOF
#define BIT_SIZEOF(type) (sizeof(type) * CHAR_BIT)
#endif

#ifndef BIT_SIZEOF_MEMBER
#define BIT_SIZEOF_MEMBER(type, member) (SIZEOF_MEMBER(type, member) * CHAR_BIT)
#endif

#ifndef LENGTHOF
#define LENGTHOF(array) (sizeof(array) / sizeof(*array))
#endif

#ifndef UNUSED_PARAMETER
#define UNUSED_PARAMETER(parameter) (void)(parameter)
#endif

#ifndef SET_BITS
#define SET_BITS(value, bits) ((value) |= (bits))
#endif

#ifndef CLEAR_BITS
#define CLEAR_BITS(value, bits) ((value) &= ~(bits))
#endif

#ifndef READ_BITS
#define READ_BITS(value, bits) ((value) & (bits))
#endif
