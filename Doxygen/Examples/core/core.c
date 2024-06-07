#include "private.h"

#include "SDeviceCore/heap.h"

#include <stdlib.h>

SDEVICE_IDENTITY_BLOCK_DEFINITION(Example,
                                  ((const SDeviceUuid)
                                  {
                                     .High = EXAMPLE_SDEVICE_UUID_HIGH,
                                     .Low  = EXAMPLE_SDEVICE_UUID_LOW
                                  }),
                                  ((const SDeviceVersion)
                                  {
                                     .Major = EXAMPLE_SDEVICE_VERSION_MAJOR,
                                     .Minor = EXAMPLE_SDEVICE_VERSION_MINOR,
                                     .Patch = EXAMPLE_SDEVICE_VERSION_PATCH
                                  }));

SDEVICE_CREATE_HANDLE_DECLARATION(Example, init, owner, identifier, context)
{
   SDeviceAssert(init != NULL);

   const ThisInitData *_init = init;

   ThisHandle *handle = SDeviceMalloc(sizeof(ThisHandle));
   handle->Header = (SDeviceHandleHeader)
   {
      .Context       = context,
      .OwnerHandle   = owner,
      .IdentityBlock = &SDEVICE_IDENTITY_BLOCK(Example),
      .LatestStatus  = EXAMPLE_SDEVICE_STATUS_OK,
      .Identifier    = identifier
   };

   handle->Init = *_init;
   handle->Runtime = (ThisRuntimeData){ /* initializer list for runtime data */ };

   /* perform any other init actions */

   return handle;
}

SDEVICE_DISPOSE_HANDLE_DECLARATION(Example, handlePointer)
{
   SDeviceAssert(handlePointer != NULL);

   ThisHandle **_handlePointer = handlePointer;
   ThisHandle *handle = *_handlePointer;

   SDeviceAssert(handle != NULL);

   /* perform any other dispose actions */

   SDeviceFree(*_handlePointer);
   *_handlePointer = NULL;
}

SDEVICE_GET_SIMPLE_PROPERTY_DECLARATION(Example, IntValue, handle, value)
{
   SDeviceAssert(handle != NULL);
   SDeviceAssert(value != NULL);

   SDEVICE_PROPERTY_TYPE(Example, IntValue) valueToRead;

   /* read value to "valueToRead" variable */

   memcpy(value, valueToRead, sizeof(valueToRead));

   return SDEVICE_PROPERTY_STATUS_OK;
}

SDEVICE_SET_SIMPLE_PROPERTY_DECLARATION(Example, IntValue, handle, value)
{
   SDeviceAssert(handle != NULL);
   SDeviceAssert(value != NULL);

   SDEVICE_PROPERTY_TYPE(Example, IntValue) valueToWrite;

   memcpy(valueToWrite, value, sizeof(valueToWrite));

   /* write value from "valueToWrite" variable */

   return SDEVICE_PROPERTY_STATUS_OK;
}

SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(Example, FixedLengthString, handle, value)
{
   SDeviceAssert(handle != NULL);
   SDeviceAssert(value != NULL);

   /* read property part by offset "value.Offset" and of size "value.Size" to "value.Data" */

   return SDEVICE_PROPERTY_STATUS_OK;
}

SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(Example, FixedLengthString, handle, value)
{
   SDeviceAssert(handle != NULL);
   SDeviceAssert(value != NULL);

   /* write property part by offset "value.Offset" and of size "value.Size" from "value.Data" */

   return SDEVICE_PROPERTY_STATUS_OK;
}

void CommonExampleSDeviceFunction(SDEVICE_HANDLE(Example) *handle)
{
   SDeviceAssert(handle != NULL);

   /* any special logic */
}

