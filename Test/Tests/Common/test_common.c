#include "test_common.h"
#include "SDeviceCore/common.h"

#include <stdint.h>

bool TestMaxMacro(void)
{
   int32_t min = INT32_MIN, max = INT32_MAX;
   return __MAX(min, max) == max;
}

bool TestMinMacro(void)
{
   int32_t min = INT32_MIN, max = INT32_MAX;
   return __MIN(min, max) == min;
}

bool WasAssertFailedCalled;

bool TestSDeviceAssert(void)
{
   WasAssertFailedCalled = false;
   SDeviceAssert(false);
   return WasAssertFailedCalled == true;
}

void SDeviceAssertFailed(char *file, int line)
{
   WasAssertFailedCalled = true;
}
