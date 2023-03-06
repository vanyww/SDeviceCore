#include "core.h"

#include "SDeviceCore/heap.h"
#include "SDeviceCore/errors.h"

#include <memory.h>

SDEVICE_RUNTIME_DATA_FORWARD_DECLARATION(TestSDevice);

struct SDEVICE_RUNTIME_DATA(TestSDevice)
{
   SDEVICE_PROPERTY_TYPE(TestSDevice, TestProperty) TestProperty;
   SDEVICE_PROPERTY_TYPE(TestSDevice, TestPartialProperty) TestPartialProperty;
};

SDEVICE_HANDLE_DECLARATION(TestSDevice);
SDEVICE_INTERNAL_ALIASES_DECLARATION(TestSDevice);

SDEVICE_CREATE_HANDLE_DECLARATION(TestSDevice, _init, _parent, _id, _context)
{
   SDeviceAssert(_init != NULL);

   ThisHandle *instance = SDeviceMalloc(sizeof(ThisHandle));
   SDeviceAssert(instance != NULL);

   const ThisInitData *init = _init;

   instance->Init = *init;
   instance->Header = (SDeviceHandleHeader)
   {
      .Context = _context,
      .ParentHandle = _parent,
      .LatestStatus = TEST_SDEVICE_STATUS_OK,
      .Identifier = _id
   };

   instance->Runtime = (ThisRuntimeData)
   {
      .TestProperty = init->TestPropertyInitialValue,
      .TestPartialProperty = init->TestPartialPropertyInitialValue
   };

   return instance;
}

SDEVICE_DISPOSE_HANDLE_DECLARATION(TestSDevice, _handlePointer)
{
   ThisHandle **handlePointer = _handlePointer;
   SDeviceFree(*handlePointer);
   *handlePointer = NULL;
}

SDEVICE_SET_PROPERTY_DECLARATION(TestSDevice, TestProperty, _handle, _value)
{
   SDeviceAssert(_handle != NULL);
   SDeviceAssert(_value != NULL);

   ThisHandle *handle = _handle;

   memcpy(&handle->Runtime.TestProperty, _value, sizeof(handle->Runtime.TestProperty));

   return SDEVICE_PROPERTY_OPERATION_STATUS_OK;
}

SDEVICE_GET_PROPERTY_DECLARATION(TestSDevice, TestProperty, _handle, _value)
{
   SDeviceAssert(_handle != NULL);
   SDeviceAssert(_value != NULL);

   ThisHandle *handle = _handle;

   memcpy(_value, &handle->Runtime.TestProperty, sizeof(handle->Runtime.TestProperty));

   return SDEVICE_PROPERTY_OPERATION_STATUS_OK;
}

SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(TestSDevice, TestPartialProperty, _handle, parameters)
{
   SDeviceAssert(_handle != NULL);
   SDeviceAssert(parameters != NULL);
   SDeviceAssert(parameters->Data != NULL);

   ThisHandle *handle = _handle;

   if(parameters->Size > sizeof(handle->Runtime.TestPartialProperty) ||
      parameters->Offset > sizeof(handle->Runtime.TestPartialProperty) - parameters->Size)
   {
      SDeviceLogStatus(handle, TEST_SDEVICE_STATUS_TEST_PARTIAL_PROPERTY_INVALID_SET);
      return SDEVICE_PROPERTY_OPERATION_STATUS_VALIDATION_ERROR;
   }

   memcpy(&((char *)&handle->Runtime.TestPartialProperty)[parameters->Offset], parameters->Data, parameters->Size);

   return SDEVICE_PROPERTY_OPERATION_STATUS_OK;
}

SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(TestSDevice, TestPartialProperty, _handle, parameters)
{
   SDeviceAssert(_handle != NULL);
   SDeviceAssert(parameters != NULL);
   SDeviceAssert(parameters->Data != NULL);

   ThisHandle *handle = _handle;

   if(parameters->Size > sizeof(handle->Runtime.TestPartialProperty) ||
      parameters->Offset > sizeof(handle->Runtime.TestPartialProperty) - parameters->Size)
   {
      SDeviceLogStatus(handle, TEST_SDEVICE_STATUS_TEST_PARTIAL_PROPERTY_INVALID_GET);
      return SDEVICE_PROPERTY_OPERATION_STATUS_VALIDATION_ERROR;
   }

   memcpy(parameters->Data, &((char *)&handle->Runtime.TestPartialProperty)[parameters->Offset], parameters->Size);

   return SDEVICE_PROPERTY_OPERATION_STATUS_OK;
}
