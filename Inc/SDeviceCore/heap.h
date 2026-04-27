#pragma once

#include <stddef.h>

void * SDeviceAllocateMemory(size_t size);
void SDeviceFreeMemory(void *pointer);

void * SDeviceAllocateHandle(
      size_t init_size,
      size_t runtime_size);

void SDeviceFreeHandle(void *handle);
