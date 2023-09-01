#include "SDeviceCore/heap.h"
#include "SDeviceCore/errors.h"
#include "SDeviceCore/global.h"

#include <stdlib.h>

__attribute__((weak)) void * SDeviceMalloc(size_t size)
{
   void *memory = malloc(size);

   if(memory == NULL)
      SDevicePanic(CoreGlobalSDeviceHandle, CORE_GLOBAL_SDEVICE_PANIC_OUT_OF_MEMORY);

   return memory;
}

__attribute__((weak)) void SDeviceFree(void *memory)
{
   free(memory);
}
