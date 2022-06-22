#include "../Inc/SDeviceCore/interface.h"

#include <stdbool.h>

__attribute__((weak)) void SDeviceAssertFailed(char *file, int line)
{
   for(;;) { }
}

__attribute__((weak)) void SDeviceProcessRuntimeError(void *handle, int32_t error)
{
   SDeviceAssert(false);
}
