#pragma once

#ifndef likely
#define likely(x) __builtin_expect(!!(x), 1)
#endif

#ifndef unlikely
#define unlikely(x) __builtin_expect(!!(x), 0)
#endif

#ifndef __MIN
#define __MIN(value1, value2) (                                                                                        \
{                                                                                                                      \
   __auto_type __value1 = (value1);                                                                                    \
   __auto_type __value2 = (value2);                                                                                    \
   __value1 < __value2 ? __value1 : __value2;                                                                          \
})
#endif

#ifndef __MAX
#define __MAX(value1, value2) (                                                                                        \
{                                                                                                                      \
   __auto_type __value1 = (value1);                                                                                    \
   __auto_type __value2 = (value2);                                                                                    \
   __value1 > __value2 ? __value1 : __value2;                                                                          \
})
#endif

#ifndef __SIZEOF_MEMBER
#define __SIZEOF_MEMBER(type, member) (sizeof(((type *)0)->member))
#endif

#ifndef __LENGTHOF
#define __LENGTHOF(array) (sizeof(array) / sizeof(*array))
#endif
