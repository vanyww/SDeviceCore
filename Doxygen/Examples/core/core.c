#include "private.h"

SDEVICE_CREATE_HANDLE_DECLARATION(Example, _init, _context)
{
   SDeviceAssert(_init != NULL);

   ThisHandle *handle = SDeviceMalloc(sizeof(ThisHandle));
   handle->Header = (SDeviceHandleHeader)
   {
      .Context = _context,
      .LatestStatus = EXAMPLE_SDEVICE_STATUS_OK
   };
   const ThisInitData *init = _init;
   handle->Init = *init;
   handle->Runtime = (ThisRuntimeData){ /* initializer list for runtime data */ };

   /* perform any other init actions */

   return handle;
}

SDEVICE_DISPOSE_HANDLE_DECLARATION(Example, _handlePointer)
{
   SDeviceAssert(_handlePointer != NULL);

   ThisHandle **handlePointer = _handlePointer;
   ThisHandle *handle = *handlePointer;

   SDeviceAssert(handle != NULL);

   /* perform any other dispose actions */

   SDeviceFree(*handlePointer);
   *handlePointer = NULL;
}

SDEVICE_GET_PROPERTY_DECLARATION(Example, IntValue, handle, value)
{
   SDeviceAssert(handle != NULL);
   SDeviceAssert(value != NULL);

   SDEVICE_PROPERTY_TYPE(Example, IntValue) valueToRead;

   /* read value to "valueToRead" variable */

   memcpy(value, valueToRead, sizeof(valueToRead));

   return SDEVICE_PROPERTY_OPERATION_STATUS_OK;
}

SDEVICE_SET_PROPERTY_DECLARATION(Example, IntValue, handle, value)
{
   SDeviceAssert(handle != NULL);
   SDeviceAssert(value != NULL);

   SDEVICE_PROPERTY_TYPE(Example, IntValue) valueToWrite;

   memcpy(valueToWrite, value, sizeof(valueToWrite));

   /* write value from "valueToWrite" variable */

   return SDEVICE_PROPERTY_OPERATION_STATUS_OK;
}

SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(Example, FixedLengthString, handle, value)
{
   SDeviceAssert(handle != NULL);
   SDeviceAssert(value != NULL);

   /* read property part by offset "value.Offset" and of size "value.Size" to "value.Data" */

   return SDEVICE_PROPERTY_OPERATION_STATUS_OK;
}

SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(Example, FixedLengthString, handle, value)
{
   SDeviceAssert(handle != NULL);
   SDeviceAssert(value != NULL);

   /* write property part by offset "value.Offset" and of size "value.Size" from "value.Data" */

   return SDEVICE_PROPERTY_OPERATION_STATUS_OK;
}

/** [error_processing_example] */

void CommonExampleSDeviceFunction(SDEVICE_HANDLE(Example) *handle)
{
   SDeviceAssert(handle != NULL);

   int randomValue = GetRandomIntGreaterThanZero(handle);
   SDeviceDebugAssert(result >= 0);

   int randomValue;
   SDeviceDebugEvalAssert((randomValue = GetRandomIntGreaterThanZero(handle)) >= 0);

   try /* dummy exception handler */
   {
      if(randomValue <= 0) /* dummy example check */
         SDeviceThrow(handle, EXAMPLE_SDEVICE_EXCEPTION_SOME_EXCEPTION_0);
   }
   catch(e)
   {
      /* `e` has type `const void *` and is identical to `handle` */
      /* process exception */
   }

   if(randomValue <= 0) /* dummy example check */
      SDeviceLogStatus(handle, EXAMPLE_SDEVICE_STATUS_ERROR_1);
}

/** [error_processing_example] */
