#include "SDeviceCore/heap.h"

#include "CoreGlobalSDevice/public.h"

#include <stdlib.h>

__attribute__((weak))
void * SDeviceAllocateMemory(size_t size)
{
   if(size > 0)
   {
      void *pointer = malloc(size);

      if(!pointer)
         CoreGlobalSDeviceThrowPanic(CORE_GLOBAL_SDEVICE_PANIC_OUT_OF_MEMORY);

      return pointer;
   }

   return NULL;
}

__attribute__((weak))
void SDeviceFreeMemory(void *pointer)
{
   free(pointer);
}

void * SDeviceAllocateHandle(size_t initSize, size_t runtimeSize)
{
   SDeviceCommonHandle *handle = SDeviceAllocateMemory(sizeof(SDeviceCommonHandle));

   handle->Init = SDeviceAllocateMemory(initSize);
   handle->Runtime = SDeviceAllocateMemory(runtimeSize);

   return handle;
}

void SDeviceFreeHandle(void *handle)
{
   if(handle)
   {
      SDeviceCommonHandle *_handle = handle;

      SDeviceFreeMemory(_handle->Runtime);
      _handle->Runtime = NULL;

      SDeviceFreeMemory(_handle->Init);
      _handle->Init = NULL;

      SDeviceFreeMemory(_handle);
   }
}
