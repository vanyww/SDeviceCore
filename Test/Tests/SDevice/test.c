#include "test.h"

#include "TestSDevice/core.h"
#include "TestSDevice/Weak/weak.h"
#include "SDeviceCore/errors.h"

bool TestSDeviceHandleInitialization(void)
{
   void *context = (void *)0x123;
   SDEVICE_INIT_DATA(TestSDevice) init = { 0x789, 0xABC };
   __attribute__((cleanup(SDEVICE_DISPOSE_HANDLE(TestSDevice)))) SDEVICE_HANDLE(TestSDevice) *handle =
            SDEVICE_CREATE_HANDLE(TestSDevice)(&init, context);

   if(SDeviceGetHandleContext(handle) != context)
      return false;

   {
      SDEVICE_PROPERTY_TYPE(TestSDevice, TestProperty) value;
      if(SDEVICE_GET_PROPERTY(TestSDevice, TestProperty)(handle, &value) != SDEVICE_PROPERTY_OPERATION_STATUS_OK)
         return false;

      if(value != init.TestPropertyInitialValue)
         return false;
   }

   {
      SDEVICE_PROPERTY_TYPE(TestSDevice, TestPartialProperty) value;
      SDeviceGetPartialPropertyParameters parameters = { &value, 0, sizeof(value) };
      SDevicePropertyOperationStatus status =
            SDEVICE_GET_PARTIAL_PROPERTY(TestSDevice, TestPartialProperty)(handle, &parameters);

      if(status != SDEVICE_PROPERTY_OPERATION_STATUS_OK)
         return false;

      if(value != init.TestPartialPropertyInitialValue)
         return false;
   }

   return true;
}

bool TestSDeviceHandleProperty(void)
{
   SDEVICE_INIT_DATA(TestSDevice) init = { 0, 0 };
   __attribute__((cleanup(SDEVICE_DISPOSE_HANDLE(TestSDevice)))) SDEVICE_HANDLE(TestSDevice) *handle =
            SDEVICE_CREATE_HANDLE(TestSDevice)(&init, NULL);

   SDEVICE_PROPERTY_TYPE(TestSDevice, TestProperty) writeValue = 0xABCDEF;
   if(SDEVICE_SET_PROPERTY(TestSDevice, TestProperty)(handle, &writeValue) != SDEVICE_PROPERTY_OPERATION_STATUS_OK)
      return false;

   SDEVICE_PROPERTY_TYPE(TestSDevice, TestProperty) readValue;
   if(SDEVICE_GET_PROPERTY(TestSDevice, TestProperty)(handle, &readValue) != SDEVICE_PROPERTY_OPERATION_STATUS_OK)
      return false;

   if(writeValue != readValue)
      return false;

   return true;
}

bool TestSDeviceHandlePartialProperty(void)
{
   SDEVICE_INIT_DATA(TestSDevice) init = { 0, 0 };
   __attribute__((cleanup(SDEVICE_DISPOSE_HANDLE(TestSDevice)))) SDEVICE_HANDLE(TestSDevice) *handle =
            SDEVICE_CREATE_HANDLE(TestSDevice)(&init, NULL);
   SDevicePropertyOperationStatus status;

   SDEVICE_PROPERTY_TYPE(TestSDevice, TestPartialProperty) writeValue = 0xABCDEF;
   SDeviceSetPartialPropertyParameters writeParameters = { &writeValue, 0, sizeof(writeValue) };
   status = SDEVICE_SET_PARTIAL_PROPERTY(TestSDevice, TestPartialProperty)(handle, &writeParameters);
   if(status != SDEVICE_PROPERTY_OPERATION_STATUS_OK)
      return false;


   SDEVICE_PROPERTY_TYPE(TestSDevice, TestPartialProperty) readValue;
   SDeviceGetPartialPropertyParameters readParameters = { &readValue, 0, sizeof(readValue) };
   status = SDEVICE_GET_PARTIAL_PROPERTY(TestSDevice, TestPartialProperty)(handle, &readParameters);
   if(status != SDEVICE_PROPERTY_OPERATION_STATUS_OK)
      return false;

   if(writeValue != readValue)
      return false;

   return true;
}

bool TestSDeviceHandledThrow(void)
{
   SDEVICE_INIT_DATA(TestSDevice) init = { 0, 0 };
   __attribute__((cleanup(SDEVICE_DISPOSE_HANDLE(TestSDevice)))) SDEVICE_HANDLE(TestSDevice) *handle =
            SDEVICE_CREATE_HANDLE(TestSDevice)(&init, NULL);
   int32_t exception = 0xAAAAAAAA;
   volatile CEXCEPTION_T e;

   Try
   {
      SDeviceThrow(handle, exception);
   }
   Catch(e)
   {
      if(handle == e && SDeviceGetHandleLatestStatus(e) == exception)
         return true;
   }

   return false;
}

bool TestSDeviceUnhandledThrow(void)
{
   SDEVICE_INIT_DATA(TestSDevice) init = { 0, 0 };
   __attribute__((cleanup(SDEVICE_DISPOSE_HANDLE(TestSDevice)))) SDEVICE_HANDLE(TestSDevice) *handle =
            SDEVICE_CREATE_HANDLE(TestSDevice)(&init, NULL);
   int32_t exception = 0xAAAAAAAA;

   SDeviceThrow(handle, exception);

   if(handle == LastUnhandledThrowHandle && SDeviceGetHandleLatestStatus(LastUnhandledThrowHandle) == exception)
      return true;

   return false;
}

bool TestSDeviceLogStatus(void)
{
   SDEVICE_INIT_DATA(TestSDevice) init = { 0, 0 };
   __attribute__((cleanup(SDEVICE_DISPOSE_HANDLE(TestSDevice)))) SDEVICE_HANDLE(TestSDevice) *handle =
            SDEVICE_CREATE_HANDLE(TestSDevice)(&init, NULL);
   int32_t status = 0xAAAAAAAA;

   SDeviceLogStatus(handle, status);

   if(handle == LastLogStatusHandle && SDeviceGetHandleLatestStatus(LastLogStatusHandle) == status)
      return true;

   return false;
}

bool TestSDeviceAssert(void)
{
   AssertFailedCalled = false;

   SDeviceAssert(false);

   if(AssertFailedCalled == true)
      return true;

   return false;
}
