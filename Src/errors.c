#include "../Inc/SDeviceCore/assert.h"

#include <stdbool.h>

__attribute__((weak)) void SDeviceAssertFailed(char *file, int line)
{
   for(;;) { }
}

__attribute__((weak)) void SDeviceProcessRuntimeError(void *_handle)
{
   SDeviceAssert(false);
}
