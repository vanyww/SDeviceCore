#include "../Inc/SDeviceCore/interface.h"

__attribute__((weak)) void SDeviceAssertFailed(char *file, int line)
{
   for(;;) { }
}

__attribute__((weak)) void SDeviceProcessRuntimeError(void *handle, int32_t error)
{
   SDeviceAssert(false);
}
