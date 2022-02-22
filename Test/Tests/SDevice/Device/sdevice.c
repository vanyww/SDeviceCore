#include "sdevice.h"

#include <memory.h>

__SDEVICE_INITIALIZE_HANDLE_DECLARATION(TestDevice, handle)
{
   handle->IsInitialized = true;
}

__SDEVICE_SET_PARAMETER_DECLARATION(TestDevice, TestParameter, handle, value)
{
   __SDEVICE_HANDLE(TestDevice) *device = handle;
   memcpy(&device->Runtime.TestParameter, value, sizeof(device->Runtime.TestParameter));
   return SDEVICE_OPERATION_STATUS_OK;
}

__SDEVICE_GET_PARAMETER_DECLARATION(TestDevice, TestParameter, handle, value)
{
   __SDEVICE_HANDLE(TestDevice) *device = handle;
   memcpy(value, &device->Runtime.TestParameter, sizeof(device->Runtime.TestParameter));
   return SDEVICE_OPERATION_STATUS_OK;
}
