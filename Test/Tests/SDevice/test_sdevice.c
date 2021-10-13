#include "test_sdevice.h"
#include "Device/sdevice.h"

bool TestHandleInitialization(void)
{
   int testValue = 0x123456;
   __SDEVICE_HANDLE(TestDevice) handle = { { .TestConstantValue = testValue } };
   __SDEVICE_INITIALIZE_HANDLE(TestDevice)(&handle);

   if(handle.IsInitialized != true)
      return false;

   if(handle.Dynamic.TestDynamicValue != testValue)
      return false;

   return true;
}

bool TestHandleSettingSet(void)
{
   __SDEVICE_HANDLE(TestDevice) handle;
   __SDEVICE_INITIALIZE_HANDLE(TestDevice)(&handle);

   int testSettingValue = 0x123456;

   if(__SDEVICE_SET_SETTING(TestDevice, TestSetting)(&handle, &testSettingValue) != SDEVICE_SETTING_SET_STATUS_OK)
      return false;

   if(handle.Settings.TestSettingValue != testSettingValue)
      return false;

   return true;
}
