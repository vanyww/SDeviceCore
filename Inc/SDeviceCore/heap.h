#pragma once

#include <stddef.h>

void * SDeviceAllocateMemory(size_t memory_size);
void SDeviceFreeMemory(void *memory);

void * SDeviceAllocateHandle(
      size_t init_memory_size,
      size_t runtime_memory_size);

void SDeviceFreeHandle(void *handle);
