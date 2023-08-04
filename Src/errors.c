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

   for(;;) { }
}

__attribute__((weak)) void SDeviceProcessLogStatus(const void *handle)
{
   UNUSED_PARAMETER(handle);
}

__attribute__((weak)) void SDeviceProcessUnhandledThrow(CEXCEPTION_T handle)
{
   UNUSED_PARAMETER(handle);

   for(;;) { }
}

#include "../Submodules/cexception/lib/CException.c"
