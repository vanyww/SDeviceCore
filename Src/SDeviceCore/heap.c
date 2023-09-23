#include "SDeviceCore/heap.h"

#include "CoreGlobalSDevice/public.h"

#include <stdlib.h>

__attribute__((weak)) void * SDeviceMalloc(size_t size)
{
   void *memory = malloc(size);

   if(memory == NULL)
      CoreGlobalSDeviceThrowPanic(CORE_GLOBAL_SDEVICE_PANIC_OUT_OF_MEMORY);

   return memory;
}

__attribute__((weak)) void SDeviceFree(void *memory)
{
   free(memory);
}

void * SDeviceAllocHandle(size_t initSize, size_t runtimeSize)
{
   SDeviceCommonHandle *handle = SDeviceMalloc(sizeof(SDeviceCommonHandle));

   handle->Init = initSize != 0 ? SDeviceMalloc(initSize) : NULL;
   handle->Runtime = runtimeSize != 0 ? SDeviceMalloc(runtimeSize) : NULL;

   return handle;
}

void SDeviceFreeHandle(void *handle)
{
   if(handle == NULL)
      return;

   SDeviceCommonHandle *_handle = handle;

   if(_handle->Runtime != NULL)
   {
      SDeviceFree(_handle->Runtime);
      _handle->Runtime = NULL;
   }

   if(_handle->Init != NULL)
   {
      SDeviceFree(_handle->Init);
      _handle->Init = NULL;
   }

   SDeviceFree(_handle);
}
