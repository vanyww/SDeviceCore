#include "SDeviceCore/errors.h"
#include "SDeviceCore/heap.h"

#include <stdlib.h>
#include <stdbool.h>

void _SDeviceProcessAssertFail(char *file, int line)
{
   for(;;) { }
}

void _SDeviceProcessUnhandledThrow(const void *_handle)
{
   SDeviceAssert(false);
}

void _SDeviceLogStatus(const void *_handle)
{

}

void * SDeviceMalloc(size_t size)
{
   return malloc(size);
}

void SDeviceFree(void *_handle)
{
   free(_handle);
}
