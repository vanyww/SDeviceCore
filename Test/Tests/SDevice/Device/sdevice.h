#pragma once

#include "SDeviceCore/interface.h"

__SDEVICE_HANDLE_FORWARD_DECLARATION(TestDevice);
typedef struct { int TestConstant; } __SDEVICE_INIT_DATA(TestDevice);
typedef struct { int TestParameter; } __SDEVICE_RUNTIME_DATA(TestDevice);
__SDEVICE_HANDLE_DEFINITION(TestDevice);
__SDEVICE_INITIALIZE_HANDLE_DECLARATION(TestDevice,);

__SDEVICE_SET_PARAMETER_DECLARATION(TestDevice, TestParameter,,);
__SDEVICE_GET_PARAMETER_DECLARATION(TestDevice, TestParameter,,);
