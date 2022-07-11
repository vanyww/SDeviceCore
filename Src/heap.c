#include "../Inc/SDeviceCore/heap.h"

#include <stdlib.h>

__attribute__((weak)) void * SDeviceMalloc(size_t size)
{
   return malloc(size);
}

__attribute__((weak)) void SDeviceFree(void *_handle)
{
   free(_handle);
}
