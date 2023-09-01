#include "SDeviceCore/errors.h"
#include "SDeviceCore/common.h"

#if defined(SDEVICE_USE_SIMPLE_ASSERT)
__attribute__((weak)) void SDeviceProcessAssertFail(void)
#else
__attribute__((weak)) void SDeviceProcessAssertFail(char *file, int line)
#endif
{
#if !defined(SDEVICE_USE_SIMPLE_ASSERT)
   UNUSED_PARAMETER(file);
   UNUSED_PARAMETER(line);
#endif

   for(;;);
}

__attribute__((weak)) void SDeviceProcessLogStatus(const void *handle, const void *extras, size_t extrasSize)
{
   UNUSED_PARAMETER(handle);
   UNUSED_PARAMETER(extras);
   UNUSED_PARAMETER(extrasSize);
}

__attribute__((weak)) void SDeviceProcessPanic(const void *handle)
{
   UNUSED_PARAMETER(handle);

   for(;;);
}
