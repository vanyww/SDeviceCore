#include "sdevice.h"

#include <memory.h>

__SDEVICE_INITIALIZE_HANDLE_DECLARATION(TestDevice, handle)
{
   handle->Dynamic.TestDynamicValue = handle->Constant->TestConstantValue;
   handle->IsInitialized = true;
}

__SDEVICE_SET_SETTING_DECLARATION(TestDevice, TestSetting, handle, value)
{
   __SDEVICE_HANDLE(TestDevice) *deviceHandle = handle;
   memcpy(&deviceHandle->Settings.TestSettingValue, value, sizeof(deviceHandle->Settings.TestSettingValue));
   return SDEVICE_SETTING_SET_STATUS_OK;
}
