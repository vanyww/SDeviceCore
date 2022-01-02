#pragma once

#include <stdint.h>

#ifndef likely
#define likely(x) __builtin_expect(!!(x), 1)
#endif

#ifndef unlikely
#define unlikely(x) __builtin_expect(!!(x), 0)
#endif

#ifndef __MIN
#define __MIN(value1, value2) (                                                                                        \
{                                                                                                                      \
   __auto_type _value1 = (value1);                                                                                     \
   __auto_type _value2 = (value2);                                                                                     \
   _value1 < _value2 ? _value1 : _value2;                                                                              \
})
#endif

#ifndef __MAX
#define __MAX(value1, value2) (                                                                                        \
{                                                                                                                      \
   __auto_type _value1 = (value1);                                                                                     \
   __auto_type _value2 = (value2);                                                                                     \
   _value1 > _value2 ? _value1 : _value2;                                                                              \
})
#endif

#ifndef __SIZEOF_MEMBER
#define __SIZEOF_MEMBER(type, member) sizeof(((type *)0)->member)
#endif

#ifdef __SDEVICE_ASSERT
#define SDeviceAssert(expression) ((expression) ? (void)0U : SDeviceAssertFailed(__FILE__, __LINE__))
void SDeviceAssertFailed(char *, int);
#else
#define SDeviceAssert(expression) ((void)0U)
#endif

#ifdef __SDEVICE_RUNTIME_ERROR
#define SDeviceRuntimeErrorRaised(handle, error) SDeviceProcessRuntimeError(handle, error)
void SDeviceProcessRuntimeError(void *, int32_t);
#else
#define SDeviceRuntimeErrorRaised(handle, error) ((void)0U)
#endif
