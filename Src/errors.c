#include "SDeviceCore/errors.h"
#include "SDeviceCore/common.h"

#ifdef __SDEVICE_USE_SIMPLE_ASSERT
__attribute__((weak)) void _SDeviceProcessAssertFail(void)
#else
__attribute__((weak)) void _SDeviceProcessAssertFail(char *file, int line)
#endif
{
#ifndef __SDEVICE_USE_SIMPLE_ASSERT
   __UNUSED_PARAMETER(file);
   __UNUSED_PARAMETER(line);
#endif

   for(;;) { }
}

__attribute__((weak)) void _SDeviceProcessUnhandledThrow(CEXCEPTION_T _handle)
{
   __UNUSED_PARAMETER(_handle);

   for(;;) { }
}

__attribute__((weak)) void _SDeviceLogStatus(const void *_handle)
{
   __UNUSED_PARAMETER(_handle);
}

#include "../Submodules/cexception/lib/CException.c"
