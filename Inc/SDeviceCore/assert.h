#pragma once

#include "config.h"

#if SDEVICE_USE_ASSERT || defined(DOXYGEN)
   #if SDEVICE_USE_SIMPLE_ASSERT
      #define SDeviceAssert(expression) ((expression) ? (void)0U : SDeviceProcessAssertFail())
   #else
      #define SDeviceAssert(expression) ((expression) ? (void)0U : SDeviceProcessAssertFail(__FILE__, __LINE__))
   #endif
#else
   #define SDeviceAssert(expression) ((void)0U)
#endif

#if SDEVICE_USE_ASSERT || defined(DOXYGEN)
   #define SDeviceEvalAssert(expression, condition) SDeviceAssert((expression) condition)
#else
   #define SDeviceEvalAssert(expression, condition) expression
#endif

#if !SDEVICE_USE_SIMPLE_ASSERT || defined(DOXYGEN)
void SDeviceProcessAssertFail(char *file, int line);
#else
void SDeviceProcessAssertFail(void);
#endif
