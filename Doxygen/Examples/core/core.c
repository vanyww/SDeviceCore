#include "private.h"

#include "SDeviceCore/heap.h"

#include <stdlib.h>

SDEVICE_CREATE_HANDLE_DECLARATION(Example, init, context)
{
   SDeviceAssert(init);

   const ThisInitData *_init = init;

   ThisHandle *handle = SDeviceAllocateHandle(sizeof(*handle->Init), sizeof(*handle->Runtime));

   handle->Context = context;
   *handle->Init = *_init;
   *handle->Runtime = (ThisRuntimeData){ /* initializer list for runtime data */ };

   /* perform any other init actions */

   return handle;
}

SDEVICE_DISPOSE_HANDLE_DECLARATION(Example, handlePointer)
{
   SDeviceAssert(handlePointer);

   ThisHandle **_handlePointer = handlePointer;
   ThisHandle *handle = *_handlePointer;

   SDeviceAssert(handle);

   /* perform any other dispose actions */

   SDeviceFreeHandle(handle);

   *_handlePointer = NULL;
}

SDEVICE_GET_SIMPLE_PROPERTY_DECLARATION(Example, IntValue, handle, value)
{
   SDeviceAssert(handle);
   SDeviceAssert(value);

   SDEVICE_PROPERTY_TYPE(Example, IntValue) valueToRead;

   /* read value to "valueToRead" variable */

   memcpy(value, &valueToRead, sizeof(valueToRead));

   return SDEVICE_PROPERTY_STATUS_OK;
}

SDEVICE_SET_SIMPLE_PROPERTY_DECLARATION(Example, IntValue, handle, value)
{
   SDeviceAssert(handle);
   SDeviceAssert(value);

   SDEVICE_PROPERTY_TYPE(Example, IntValue) valueToWrite;

   memcpy(&valueToWrite, value, sizeof(valueToWrite));

   /* write value from "valueToWrite" variable */

   return SDEVICE_PROPERTY_STATUS_OK;
}

SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(Example, StringValue, handle, value)
{
   SDeviceAssert(handle);
   SDeviceAssert(value);

   /* read property part by offset "value.Offset" and of size "value.Size" to "value.Data" */

   return SDEVICE_PROPERTY_STATUS_OK;
}

SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(Example, StringValue, handle, value)
{
   SDeviceAssert(handle);
   SDeviceAssert(value);

   /* write property part by offset "value.Offset" and of size "value.Size" from "value.Data" */

   return SDEVICE_PROPERTY_STATUS_OK;
}

void CommonExampleSDeviceFunction(SDEVICE_HANDLE(Example) *handle)
{
   SDeviceAssert(handle);

   /* any special logic */
}
