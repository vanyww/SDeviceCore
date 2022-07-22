#include "SDeviceCore/errors.h"

#include <stdbool.h>

__attribute__((weak)) void _SDeviceProcessAssertFail(char *file, int line)
{
   (void)file;
   (void)line;

   for(;;) { }
}

__attribute__((weak)) void _SDeviceProcessUnhandledThrow(const void *_handle)
{
   (void)_handle;

   for(;;) { }
}

__attribute__((weak)) void _SDeviceLogStatus(const void *_handle)
{
   (void)_handle;
}
