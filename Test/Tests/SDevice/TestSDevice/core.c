#include "core.h"

#include "SDeviceCore/heap.h"
#include "SDeviceCore/errors.h"

#include <memory.h>

__SDEVICE_RUNTIME_DATA_FORWARD_DECLARATION(TestSDevice);

struct __SDEVICE_RUNTIME_DATA(TestSDevice)
{
   __SDEVICE_PROPERTY_TYPE(TestSDevice, TestProperty) TestProperty;
   __SDEVICE_PROPERTY_TYPE(TestSDevice, TestPartialProperty) TestPartialProperty;
};

__SDEVICE_HANDLE_DEFINITION(TestSDevice);

__SDEVICE_CREATE_HANDLE_DECLARATION(TestSDevice, _init, _context, index)
{
   SDeviceAssert(_init != NULL);

   __SDEVICE_HANDLE(TestSDevice) *instance = SDeviceMalloc(sizeof(__SDEVICE_HANDLE(TestSDevice)));
   SDeviceAssert(instance != NULL);

   __SDEVICE_INIT_DATA(TestSDevice) *init = _init;

   instance->Header = (SDeviceHandleHeader){ _context, TEST_SDEVICE_STATUS_OK, index };
   instance->Init = *init;
   instance->Runtime = (__SDEVICE_RUNTIME_DATA(TestSDevice))
   {
      .TestProperty = init->TestPropertyInitialValue,
      .TestPartialProperty = init->TestPartialPropertyInitialValue
   };

   return instance;
}

__SDEVICE_DISPOSE_HANDLE_DECLARATION(TestSDevice, _handlePointer)
{
   __SDEVICE_HANDLE(TestSDevice) **handlePointer = _handlePointer;
   SDeviceFree(*handlePointer);
   *handlePointer = NULL;
}

__SDEVICE_SET_PROPERTY_DECLARATION(TestSDevice, TestProperty, _handle, _value)
{
   SDeviceAssert(_handle != NULL);
   SDeviceAssert(_value != NULL);

   __SDEVICE_HANDLE(TestSDevice) *handle = _handle;

   memcpy(&handle->Runtime.TestProperty, _value, sizeof(handle->Runtime.TestProperty));

   return SDEVICE_PROPERTY_OPERATION_STATUS_OK;
}

__SDEVICE_GET_PROPERTY_DECLARATION(TestSDevice, TestProperty, _handle, _value)
{
   SDeviceAssert(_handle != NULL);
   SDeviceAssert(_value != NULL);

   __SDEVICE_HANDLE(TestSDevice) *handle = _handle;

   memcpy(_value, &handle->Runtime.TestProperty, sizeof(handle->Runtime.TestProperty));

   return SDEVICE_PROPERTY_OPERATION_STATUS_OK;
}

__SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(TestSDevice, TestPartialProperty, _handle, parameters)
{
   SDeviceAssert(_handle != NULL);
   SDeviceAssert(parameters != NULL);
   SDeviceAssert(parameters->Data != NULL);

   __SDEVICE_HANDLE(TestSDevice) *handle = _handle;

   if(parameters->Size > sizeof(handle->Runtime.TestPartialProperty) ||
      parameters->Offset > sizeof(handle->Runtime.TestPartialProperty) - parameters->Size)
   {
      SDeviceLogStatus(handle, TEST_SDEVICE_STATUS_TEST_PARTIAL_PROPERTY_INVALID_SET);
      return SDEVICE_PROPERTY_OPERATION_STATUS_VALIDATION_ERROR;
   }

   memcpy(&((char *)&handle->Runtime.TestPartialProperty)[parameters->Offset], parameters->Data, parameters->Size);

   return SDEVICE_PROPERTY_OPERATION_STATUS_OK;
}

__SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(TestSDevice, TestPartialProperty, _handle, parameters)
{
   SDeviceAssert(_handle != NULL);
   SDeviceAssert(parameters != NULL);
   SDeviceAssert(parameters->Data != NULL);

   __SDEVICE_HANDLE(TestSDevice) *handle = _handle;

   if(parameters->Size > sizeof(handle->Runtime.TestPartialProperty) ||
      parameters->Offset > sizeof(handle->Runtime.TestPartialProperty) - parameters->Size)
   {
      SDeviceLogStatus(handle, TEST_SDEVICE_STATUS_TEST_PARTIAL_PROPERTY_INVALID_GET);
      return SDEVICE_PROPERTY_OPERATION_STATUS_VALIDATION_ERROR;
   }

   memcpy(parameters->Data, &((char *)&handle->Runtime.TestPartialProperty)[parameters->Offset], parameters->Size);

   return SDEVICE_PROPERTY_OPERATION_STATUS_OK;
}
