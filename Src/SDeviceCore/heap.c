#include "SDeviceCore/heap.h"
#include "SDeviceCore/core.h"

#include <stdlib.h>

__attribute__((weak))
void * SDeviceAllocateMemory(size_t size)
{
   return malloc(size);
}

__attribute__((weak))
void SDeviceFreeMemory(void *pointer)
{
   free(pointer);
}

__attribute__((weak))
void * SDeviceAllocateHandle(
      size_t init_size,
      size_t runtime_size)
{
   SDeviceCommonHandle *handle =
         SDeviceAllocateMemory(
               sizeof(*handle));

   handle->Init =
         SDeviceAllocateMemory(
               init_size);

   handle->Runtime =
         SDeviceAllocateMemory(
               runtime_size);

   return handle;
}

__attribute__((weak))
void SDeviceFreeHandle(void *handle)
{
   SDeviceCommonHandle *_handle = handle;

   SDeviceFreeMemory(_handle->Runtime);
   SDeviceFreeMemory(_handle->Init);
   SDeviceFreeMemory(_handle);
}
