#include "SDeviceCore/heap.h"
#include "SDeviceCore/core.h"

#include <stdlib.h>

__attribute__((weak))
void * SDeviceAllocateMemory(size_t memory_size)
{
   return malloc(memory_size);
}

__attribute__((weak))
void SDeviceFreeMemory(void *memory)
{
   free(memory);
}

__attribute__((weak))
void * SDeviceAllocateHandle(
      size_t init_memory_size,
      size_t runtime_memory_size)
{
   SDeviceCommonHandle *handle =
         SDeviceAllocateMemory(
               sizeof(*handle));

   handle->Init =
         SDeviceAllocateMemory(
               init_memory_size);

   handle->Runtime =
         SDeviceAllocateMemory(
               runtime_memory_size);

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
