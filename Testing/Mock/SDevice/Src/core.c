#include "private.h"

#include "SDeviceCore/heap.h"

#include <memory.h>

SDEVICE_IDENTITY_BLOCK_DEFINITION(Test,
                                  ((const SDeviceUuid)
                                  {
                                     .High = TEST_SDEVICE_UUID_HIGH,
                                     .Low  = TEST_SDEVICE_UUID_LOW
                                  }),
                                  ((const SDeviceVersion)
                                  {
                                     .Major = TEST_SDEVICE_VERSION_MAJOR,
                                     .Minor = TEST_SDEVICE_VERSION_MINOR,
                                     .Patch = TEST_SDEVICE_VERSION_PATCH
                                  }));

SDEVICE_CREATE_HANDLE_DECLARATION(Test, init, owner, identifier, context)
{
   SDeviceAssert(init != NULL);

   const ThisInitData *_init = init;

   ThisHandle *handle = SDeviceAllocHandle(sizeof(ThisInitData), sizeof(ThisRuntimeData));

   handle->Header = (SDeviceHandleHeader)
   {
      .Context       = context,
      .OwnerHandle   = owner,
      .LatestStatus  = TEST_SDEVICE_STATUS_OK,
      .IdentityBlock = &SDEVICE_IDENTITY_BLOCK(Test),
      .Identifier    = identifier
   };
   *handle->Init = *_init;
   *handle->Runtime = (ThisRuntimeData)
   {
      .TestData = _init->TestData
   };

   return handle;
}

SDEVICE_DISPOSE_HANDLE_DECLARATION(Test, handlePointer)
{
   SDeviceAssert(handlePointer != NULL);

   ThisHandle **_handlePointer = handlePointer;
   ThisHandle *handle = *_handlePointer;

   SDeviceAssert(handle != NULL);

   SDeviceFreeHandle(handle);
   *_handlePointer = NULL;
}

SDEVICE_GET_PROPERTY_DECLARATION(Test, PropertyValue, handle, value)
{
   SDeviceAssert(value != NULL);
   SDeviceAssert(handle != NULL);

   ThisHandle *_handle = handle;

   memcpy(value, &_handle->Runtime->TestData, sizeof(_handle->Runtime->TestData));

   return SDEVICE_PROPERTY_STATUS_OK;
}

SDEVICE_SET_PROPERTY_DECLARATION(Test, PropertyValue, handle, value)
{
   SDeviceAssert(value != NULL);
   SDeviceAssert(handle != NULL);

   ThisHandle *_handle = handle;

   memcpy(&_handle->Runtime->TestData, value, sizeof(_handle->Runtime->TestData));

   return SDEVICE_PROPERTY_STATUS_OK;
}

SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(Test, PartialPropertyValue, handle, parameters)
{
   SDeviceAssert(handle != NULL);
   SDeviceAssert(parameters != NULL);
   SDeviceAssert(parameters->Data != NULL);

   ThisHandle *_handle = handle;

   if (parameters->Size > sizeof(SDEVICE_PROPERTY_TYPE(Test, PropertyValue)) ||
       parameters->Offset > sizeof(SDEVICE_PROPERTY_TYPE(Test, PropertyValue)) - parameters->Size)
   {
       return SDEVICE_PROPERTY_STATUS_VALIDATION_ERROR;
   }

   memcpy(parameters->Data, &((char *)&_handle->Runtime->TestData)[parameters->Offset], parameters->Size);

   return SDEVICE_PROPERTY_STATUS_OK;
}

SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(Test, PartialPropertyValue, handle, parameters)
{
   SDeviceAssert(handle != NULL);
   SDeviceAssert(parameters != NULL);
   SDeviceAssert(parameters->Data != NULL);

   ThisHandle *_handle = handle;

   if (parameters->Size > sizeof(SDEVICE_PROPERTY_TYPE(Test, PropertyValue)) ||
       parameters->Offset > sizeof(SDEVICE_PROPERTY_TYPE(Test, PropertyValue)) - parameters->Size)
   {
       return SDEVICE_PROPERTY_STATUS_VALIDATION_ERROR;
   }

   memcpy(&((char *)&_handle->Runtime->TestData)[parameters->Offset], parameters->Data, parameters->Size);

   return SDEVICE_PROPERTY_STATUS_OK;
}
