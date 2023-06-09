#include "weak.h"
#include "SDeviceCore/heap.h"
#include "SDeviceCore/errors.h"
#include "SDeviceCore/global.h"
#include <stdlib.h>

const void *LastUnhandledThrowHandle;
const void *LastLogStatusHandle;
bool AssertFailedCalled;


void SDeviceProcessAssertFail(char *file, int line)
{
   AssertFailedCalled = true;
}

void SDeviceProcessUnhandledThrow(const void *_handle)
{
   LastUnhandledThrowHandle = _handle;
}

void SDeviceProcessLogStatus(const void *_handle)
{
   LastLogStatusHandle = _handle;
}

void* SDeviceMalloc(size_t size)
{
   void *memory = malloc(size);

   if (memory == NULL)
      SDeviceThrow(CoreGlobalSDeviceHandle, CORE_GLOBAL_SDEVICE_EXCEPTION_OUT_OF_MEMORY);

   return memory;
}

void SDeviceFree(void *_handle)
{
   free(_handle);
}
