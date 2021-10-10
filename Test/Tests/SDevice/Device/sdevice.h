#pragma once

#include "SDeviceCore/interface.h"

__SDEVICE_HANDLE_FORWARD_DECLARATION(TestDevice);

typedef struct { int TestConstantValue; } __SDEVICE_CONSTANT_DATA(TestDevice);

typedef struct { int TestSettingValue; } __SDEVICE_SETTINGS_DATA(TestDevice);

typedef struct { int TestDynamicValue; } __SDEVICE_DYNAMIC_DATA(TestDevice);

__SDEVICE_HANDLE_DEFINITION(TestDevice);

__SDEVICE_INITIALIZE_HANDLE_DECLARATION(TestDevice,);

__SDEVICE_SET_SETTING_DECLARATION(TestDevice, TestSetting,,);
