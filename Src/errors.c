#include "SDeviceCore/errors.h"
#include "SDeviceCore/common.h"

#ifdef SDEVICE_USE_SIMPLE_ASSERT
__attribute__((weak)) void SDeviceProcessAssertFail(void)
#else
__attribute__((weak)) void SDeviceProcessAssertFail(char *file, int line)
#endif
{
#ifndef __SDEVICE_USE_SIMPLE_ASSERT
   UNUSED_PARAMETER(file);
   UNUSED_PARAMETER(line);
#endif

   for(;;) { }
}

__attribute__((weak)) void SDeviceProcessLogStatus(const void *_handle)
{
   UNUSED_PARAMETER(_handle);
}

__attribute__((weak)) void SDeviceProcessUnhandledThrow(CEXCEPTION_T _handle)
{
   UNUSED_PARAMETER(_handle);

   for(;;) { }
}

#include "../Submodules/cexception/lib/CException.c"
