#pragma once

#include "config.h"

#if SDEVICE_USE_ASSERT
   #if SDEVICE_USE_SIMPLE_ASSERT
      #define SDeviceAssert(expression)                                                                                \
         ((expression) ? (void)0 : SDeviceProcessAssertFail())
   #else /* SDEVICE_USE_SIMPLE_ASSERT */
      #define SDeviceAssert(expression)                                                                                \
         ((expression) ? (void)0 : SDeviceProcessAssertFail(__FILE__, __LINE__))
   #endif /* SDEVICE_USE_SIMPLE_ASSERT */
#else /* SDEVICE_USE_ASSERT */
   #define SDeviceAssert(expression) ((void)0)
#endif /* SDEVICE_USE_ASSERT */

#if SDEVICE_USE_ASSERT
   #define SDeviceEvalAssert(expression, condition)                                                                    \
      SDeviceAssert((expression) condition)
#else /* SDEVICE_USE_ASSERT */
   #define SDeviceEvalAssert(expression, condition)                                                                    \
      (expression)
#endif /* SDEVICE_USE_ASSERT */

#if SDEVICE_USE_SIMPLE_ASSERT
void SDeviceProcessAssertFail(void);
#else /* SDEVICE_USE_SIMPLE_ASSERT */
void SDeviceProcessAssertFail(char *file, int line);
#endif /* SDEVICE_USE_SIMPLE_ASSERT */
