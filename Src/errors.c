#include "SDeviceCore/errors.h"
#include "SDeviceCore/common.h"

__attribute__((weak)) void _SDeviceProcessAssertFail(char *file, int line)
{
   __UNUSED_PARAMETER(file);
   __UNUSED_PARAMETER(line);

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
