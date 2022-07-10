#include "SDeviceCore/assert.h"
#include "SDeviceCore/heap.h"

#include <stdlib.h>
#include <stdbool.h>

void SDeviceAssertFailed(char *file, int line)
{
   for(;;) { }
}

void SDeviceProcessRuntimeError(void *_handle)
{
   SDeviceAssert(false);
}

void * SDeviceMalloc(size_t size)
{
   return malloc(size);
}

void SDeviceFree(void *_handle)
{
   free(_handle);
}
