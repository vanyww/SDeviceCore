#pragma once

#include <limits.h>

#ifndef likely
#define likely(x) __builtin_expect(!!(x), 1)
#endif

#ifndef unlikely
#define unlikely(x) __builtin_expect(!!(x), 0)
#endif

#ifndef __MIN
#define __MIN(value$1, value$2) (                                                                                      \
{                                                                                                                      \
   __auto_type __value$1 = (value$1);                                                                                  \
   __auto_type __value$2 = (value$2);                                                                                  \
   __value$1 < __value$2 ? __value$1 : __value$2;                                                                      \
})
#endif

#ifndef __MAX
#define __MAX(value$1, value$2) (                                                                                      \
{                                                                                                                      \
   __auto_type __value$1 = (value$1);                                                                                  \
   __auto_type __value$2 = (value$2);                                                                                  \
   __value$1 > __value$2 ? __value$1 : __value$2;                                                                      \
})
#endif

#ifndef __SIZEOF_MEMBER
#define __SIZEOF_MEMBER(type, member) (sizeof(((type *)0)->member))
#endif

#ifndef __BIT_SIZEOF
#define __BIT_SIZEOF(value) (sizeof(value) * CHAR_BIT)
#endif

#ifndef __BIT_SIZEOF_MEMBER
#define __BIT_SIZEOF_MEMBER(type, member) (__SIZEOF_MEMBER(type, member) * CHAR_BIT)
#endif

#ifndef __LENGTHOF
#define __LENGTHOF(array) (sizeof(array) / sizeof(*array))
#endif

#ifndef __UNUSED_PARAMETER
#define __UNUSED_PARAMETER(parameter) (void)(parameter)
#endif

#ifndef __SET_BITS
#define __SET_BITS(value, bits) ((value) |= (bits))
#endif

#ifndef __CLEAR_BITS
#define __CLEAR_BITS(value, bits) ((value) &= ~(bits))
#endif

#ifndef __READ_BITS
#define __READ_BITS(value, bits) ((value) & (bits))
#endif
