#include "sdevice.h"

#include <memory.h>
#include <stdlib.h>

struct __SDEVICE_RUNTIME_DATA(TestDevice) { int TestParameter; };

__SDEVICE_CREATE_HANDLE_DECLARATION(TestDevice, arguments, instanceIndex, context)
{
   __SDEVICE_HANDLE(TestDevice) instance =
   {
      .Init =
      {
         .TestConstant = arguments->TestConstant
      },
      .Runtime = __SDEVICE_MALLOC(sizeof(__SDEVICE_RUNTIME_DATA(TestDevice))),
      .Context = context,
      .InstanceIndex = instanceIndex,
      .IsInitialized = true
   };

   return instance;
}

__SDEVICE_DISPOSE_HANDLE_DECLARATION(TestDevice, handle)
{
   __SDEVICE_FREE(handle->Runtime);
   handle->Runtime = NULL;
}

__SDEVICE_SET_PARAMETER_DECLARATION(TestDevice, TestParameter, handle, value)
{
   __SDEVICE_HANDLE(TestDevice) *device = handle;
   memcpy(&device->Runtime->TestParameter, value, sizeof(device->Runtime->TestParameter));
   return SDEVICE_OPERATION_STATUS_OK;
}

__SDEVICE_GET_PARAMETER_DECLARATION(TestDevice, TestParameter, handle, value)
{
   __SDEVICE_HANDLE(TestDevice) *device = handle;
   memcpy(value, &device->Runtime->TestParameter, sizeof(device->Runtime->TestParameter));
   return SDEVICE_OPERATION_STATUS_OK;
}
