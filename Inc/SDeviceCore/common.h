#pragma once

#ifndef likely
#define likely(x) __builtin_expect(!!(x), 1)
#endif

#ifndef unlikely
#define unlikely(x) __builtin_expect(!!(x), 0)
#endif

#ifndef __MIN
#define __MIN(_value1, _value2) (                                                                                      \
{                                                                                                                      \
   __auto_type value1 = (_value1);                                                                                     \
   __auto_type value2 = (_value2);                                                                                     \
   value1 < value2 ? value1 : value2;                                                                                  \
})
#endif

#ifndef __MAX
#define __MAX(_value1, _value2) (                                                                                      \
{                                                                                                                      \
   __auto_type value1 = (_value1);                                                                                     \
   __auto_type value2 = (_value2);                                                                                     \
   value1 > value2 ? value1 : value2;                                                                                  \
})
#endif

#ifndef __SIZEOF_MEMBER
#define __SIZEOF_MEMBER(type, member) (sizeof(((type *)0)->member))
#endif

#ifndef __LENGTHOF
#define __LENGTHOF(array) (sizeof(array) / sizeof(*array))
#endif
