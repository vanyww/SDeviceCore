#include "test.h"

#include "TestSDevice/core.h"

bool TestSDeviceHandleInitialization(void)
{
   void *context = (void *)0x123;
   uint32_t instanceIndex = 0x456;
   __SDEVICE_INIT_DATA(TestSDevice) init = { 0x789, 0xABC };
   __attribute__((cleanup(__SDEVICE_DISPOSE_HANDLE(TestSDevice)))) __SDEVICE_HANDLE(TestSDevice) *handle =
            __SDEVICE_CREATE_HANDLE(TestSDevice)(&init, context, instanceIndex);

   if(SDeviceGetHandleContext(handle) != context)
      return false;

   if(SDeviceGetHandleInstanceIndex(handle) != instanceIndex)
      return false;

   {
      __SDEVICE_PROPERTY_TYPE(TestSDevice, TestProperty) value;
      if(__SDEVICE_GET_PROPERTY(TestSDevice, TestProperty)(handle, &value) != SDEVICE_PROPERTY_OPERATION_STATUS_OK)
         return false;

      if(value != init.TestPropertyInitialValue)
         return false;
   }

   {
      __SDEVICE_PROPERTY_TYPE(TestSDevice, TestPartialProperty) value;
      SDeviceGetPartialPropertyParameters parameters = { &value, 0, sizeof(value) };
      SDevicePropertyOperationStatus status =
               __SDEVICE_GET_PARTIAL_PROPERTY(TestSDevice, TestPartialProperty)(handle, &parameters);

      if(status != SDEVICE_PROPERTY_OPERATION_STATUS_OK)
         return false;

      if(value != init.TestPartialPropertyInitialValue)
         return false;
   }

   return true;
}

bool TestSDeviceHandleProperty(void)
{
   __SDEVICE_INIT_DATA(TestSDevice) init = { 0, 0 };
   __attribute__((cleanup(__SDEVICE_DISPOSE_HANDLE(TestSDevice)))) __SDEVICE_HANDLE(TestSDevice) *handle =
            __SDEVICE_CREATE_HANDLE(TestSDevice)(&init, NULL, 0);

   __SDEVICE_PROPERTY_TYPE(TestSDevice, TestProperty) writeValue = 0xABCDEF;
   if(__SDEVICE_SET_PROPERTY(TestSDevice, TestProperty)(handle, &writeValue) != SDEVICE_PROPERTY_OPERATION_STATUS_OK)
      return false;

   __SDEVICE_PROPERTY_TYPE(TestSDevice, TestProperty) readValue;
   if(__SDEVICE_GET_PROPERTY(TestSDevice, TestProperty)(handle, &readValue) != SDEVICE_PROPERTY_OPERATION_STATUS_OK)
      return false;

   if(writeValue != readValue)
      return false;

   return true;
}

bool TestSDeviceHandlePartialProperty(void)
{
   __SDEVICE_INIT_DATA(TestSDevice) init = { 0, 0 };
   __attribute__((cleanup(__SDEVICE_DISPOSE_HANDLE(TestSDevice)))) __SDEVICE_HANDLE(TestSDevice) *handle =
            __SDEVICE_CREATE_HANDLE(TestSDevice)(&init, NULL, 0);
   SDevicePropertyOperationStatus status;

   __SDEVICE_PROPERTY_TYPE(TestSDevice, TestPartialProperty) writeValue = 0xABCDEF;
   SDeviceSetPartialPropertyParameters writeParameters = { &writeValue, 0, sizeof(writeValue) };
   status = __SDEVICE_SET_PARTIAL_PROPERTY(TestSDevice, TestPartialProperty)(handle, &writeParameters);
   if(status != SDEVICE_PROPERTY_OPERATION_STATUS_OK)
      return false;


   __SDEVICE_PROPERTY_TYPE(TestSDevice, TestPartialProperty) readValue;
   SDeviceGetPartialPropertyParameters readParameters = { &readValue, 0, sizeof(readValue) };
   status = __SDEVICE_GET_PARTIAL_PROPERTY(TestSDevice, TestPartialProperty)(handle, &readParameters);
   if(status != SDEVICE_PROPERTY_OPERATION_STATUS_OK)
      return false;

   if(writeValue != readValue)
      return false;

   return true;
}
