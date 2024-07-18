#include "SDeviceCore/heap.h"

#include "CoreGlobalSDevice/public.h"

#include <stdlib.h>

__attribute__((weak))
void * SDeviceMalloc(size_t size)
{
   if(!size)
      return NULL;

   void *memory = malloc(size);

   if(!memory)
      CoreGlobalSDeviceThrowPanic(CORE_GLOBAL_SDEVICE_PANIC_OUT_OF_MEMORY);

   return memory;
}

__attribute__((weak))
void SDeviceFree(void *memory)
{
   free(memory);
}

void * SDeviceAllocHandle(size_t initSize, size_t runtimeSize)
{
   SDeviceCommonHandle *handle = SDeviceMalloc(sizeof(SDeviceCommonHandle));

   handle->Init = SDeviceMalloc(initSize);
   handle->Runtime = SDeviceMalloc(runtimeSize);

   return handle;
}

void SDeviceFreeHandle(void *handle)
{
   if(!handle)
      return;

   SDeviceCommonHandle *_handle = handle;

   SDeviceFree(_handle->Runtime);
   _handle->Runtime = NULL;

   SDeviceFree(_handle->Init);
   _handle->Init = NULL;

   SDeviceFree(_handle);
}
