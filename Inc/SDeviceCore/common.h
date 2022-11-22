#pragma once

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

#ifndef __LENGTHOF
#define __LENGTHOF(array) (sizeof(array) / sizeof(*array))
#endif

#ifndef __UNUSED_PARAMETER
#define __UNUSED_PARAMETER(parameter) (void)(parameter)
#endif
