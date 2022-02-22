#include "test_sdevice.h"
#include "Device/sdevice.h"

bool TestHandleInitialization(void)
{
   __SDEVICE_HANDLE(TestDevice) device;
   __SDEVICE_INITIALIZE_HANDLE(TestDevice)(&device);

   if(device.IsInitialized != true)
      return false;

   return true;
}

bool TestHandleParameterSet(void)
{
   __SDEVICE_HANDLE(TestDevice) device;
   __SDEVICE_INITIALIZE_HANDLE(TestDevice)(&device);

   int testValue = 0x123456;
   if(__SDEVICE_SET_PARAMETER(TestDevice, TestParameter)(&device, &testValue) != SDEVICE_OPERATION_STATUS_OK)
      return false;

   if(device.Runtime.TestParameter != testValue)
      return false;

   return true;
}

bool TestHandleParameterGet(void)
{
   __SDEVICE_HANDLE(TestDevice) device;
   __SDEVICE_INITIALIZE_HANDLE(TestDevice)(&device);

   int testValue = 0x123456;
   __SDEVICE_SET_PARAMETER(TestDevice, TestParameter)(&device, &testValue);

   int readValue;
   if(__SDEVICE_GET_PARAMETER(TestDevice, TestParameter)(&device, &readValue) != SDEVICE_OPERATION_STATUS_OK)
      return false;

   if(testValue != readValue)
      return false;

   return true;
}
