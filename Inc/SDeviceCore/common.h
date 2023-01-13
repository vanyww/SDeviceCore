#pragma once

#include <limits.h>

#ifndef likely
#define likely(x) __builtin_expect(!!(x), 1)
#endif

#ifndef unlikely
#define unlikely(x) __builtin_expect(!!(x), 0)
#endif

#ifndef MIN
#define MIN(value$1, value$2) (                                                                                        \
{                                                                                                                      \
   __auto_type $value$1 = (value$1);                                                                                   \
   __auto_type $value$2 = (value$2);                                                                                   \
   $value$1 < $value$2 ? $value$1 : $value$2;                                                                          \
})
#endif

#ifndef MAX
#define MAX(value$1, value$2) (                                                                                        \
{                                                                                                                      \
   __auto_type $value$1 = (value$1);                                                                                   \
   __auto_type $value$2 = (value$2);                                                                                   \
   $value$1 > $value$2 ? $value$1 : $value$2;                                                                          \
})
#endif

#ifndef SIZEOF_MEMBER
#define SIZEOF_MEMBER(type, member) (sizeof(((type *)0)->member))
#endif

#ifndef BIT_SIZEOF
#define BIT_SIZEOF(value) (sizeof(value) * CHAR_BIT)
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
