#include "test_sdevice.h"
#include "Device/sdevice.h"

bool TestHandleParameter(void)
{
   const __SDEVICE_INIT_ARGUMENTS(TestDevice) arguments = { 0 };
   __attribute__((cleanup(__SDEVICE_DISPOSE_HANDLE(TestDevice)))) __SDEVICE_HANDLE(TestDevice) device =
         __SDEVICE_CREATE_HANDLE(TestDevice)(&arguments, NULL);

   int writeValue = 0x123456;
   if(__SDEVICE_SET_PARAMETER(TestDevice, TestParameter)(&device, &writeValue) != SDEVICE_OPERATION_STATUS_OK)
      return false;

   int readValue;
   if(__SDEVICE_GET_PARAMETER(TestDevice, TestParameter)(&device, &readValue) != SDEVICE_OPERATION_STATUS_OK)
      return false;

   if(writeValue != readValue)
      return false;

   return true;
}
