#include "private.h"

#include "SDeviceCore/heap.h"

#include <memory.h>

SDEVICE_CREATE_HANDLE_DECLARATION(Test, init, context)
{
   SDeviceAssert(init);

   const ThisInitData *_init = init;

   ThisHandle *handle = SDeviceAllocateHandle(sizeof(*handle->Init), sizeof(*handle->Runtime));

   handle->Context = context;
   *handle->Init = *_init;
   *handle->Runtime = (ThisRuntimeData)
   {
      .SimplePropertyValue  = _init->InitData
   };

   return handle;
}

SDEVICE_DISPOSE_HANDLE_DECLARATION(Test, handlePointer)
{
   SDeviceAssert(handlePointer);

   ThisHandle **_handlePointer = handlePointer;
   ThisHandle *handle = *_handlePointer;

   SDeviceAssert(handle);

   SDeviceFreeHandle(handle);

   *_handlePointer = NULL;
}

SDEVICE_GET_SIMPLE_PROPERTY_DECLARATION(Test, SimplePropertyValue, handle, value)
{
   SDeviceAssert(value);
   SDeviceAssert(handle);

   ThisHandle *_handle = handle;

   memcpy(value, &_handle->Runtime->SimplePropertyValue, sizeof(_handle->Runtime->SimplePropertyValue));

   return SDEVICE_PROPERTY_STATUS_OK;
}

SDEVICE_SET_SIMPLE_PROPERTY_DECLARATION(Test, SimplePropertyValue, handle, value)
{
   SDeviceAssert(value);
   SDeviceAssert(handle);

   ThisHandle *_handle = handle;

   SDEVICE_PROPERTY_TYPE(Test, SimplePropertyValue) valueToWrite;
   memcpy(&valueToWrite, value, sizeof(valueToWrite));

   _handle->Runtime->SimplePropertyValue = valueToWrite;

   return SDEVICE_PROPERTY_STATUS_OK;
}

SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(Test, PartialPropertyValue, handle, parameters)
{
   SDeviceAssert(handle);
   SDeviceAssert(parameters);
   SDeviceAssert(parameters->Data);

   ThisHandle *_handle = handle;

   if (parameters->Size > sizeof(SDEVICE_PROPERTY_TYPE(Test, PartialPropertyValue)) ||
       parameters->Offset > sizeof(SDEVICE_PROPERTY_TYPE(Test, PartialPropertyValue)) - parameters->Size)
   {
       return SDEVICE_PROPERTY_STATUS_VALIDATION_ERROR;
   }

   memcpy(parameters->Data, &_handle->Runtime->PartialPropertyValue.Value[parameters->Offset], parameters->Size);

   return SDEVICE_PROPERTY_STATUS_OK;
}

SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(Test, PartialPropertyValue, handle, parameters)
{
   SDeviceAssert(handle);
   SDeviceAssert(parameters);
   SDeviceAssert(parameters->Data);

   ThisHandle *_handle = handle;

   if (parameters->Size > sizeof(SDEVICE_PROPERTY_TYPE(Test, PartialPropertyValue)) ||
       parameters->Offset > sizeof(SDEVICE_PROPERTY_TYPE(Test, PartialPropertyValue)) - parameters->Size)
   {
       return SDEVICE_PROPERTY_STATUS_VALIDATION_ERROR;
   }

   memcpy(&_handle->Runtime->PartialPropertyValue.Value[parameters->Offset], parameters->Data, parameters->Size);

   return SDEVICE_PROPERTY_STATUS_OK;
}
