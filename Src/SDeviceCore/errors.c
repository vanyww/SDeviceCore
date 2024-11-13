#include "SDeviceCore/errors.h"
#include "SDeviceCore/common.h"

__attribute__((weak))
#if SDEVICE_USE_SIMPLE_ASSERT
void SDeviceProcessAssertFail(void)
#else
void SDeviceProcessAssertFail(char *file, int line)
#endif
{
#if !SDEVICE_USE_SIMPLE_ASSERT
   UNUSED_PARAMETER(file);
   UNUSED_PARAMETER(line);
#endif

   for(;;);
}

__attribute__((weak))
void SDeviceProcessLogStatus(const void *handle, const void *extras, size_t extrasSize)
{
   UNUSED_PARAMETER(handle);
   UNUSED_PARAMETER(extras);
   UNUSED_PARAMETER(extrasSize);
}

__attribute__((weak))
void SDeviceProcessPanic(const void *handle)
{
   UNUSED_PARAMETER(handle);

   for(;;);
}
