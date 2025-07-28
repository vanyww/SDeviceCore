#pragma once

#include <stddef.h>

void * SDeviceAllocateMemory(size_t size);
void SDeviceFreeMemory(void *pointer);

void * SDeviceAllocateHandle(
      size_t initSize,
      size_t runtimeSize);

void SDeviceFreeHandle(void *handle);
