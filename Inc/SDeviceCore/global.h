#pragma once

#include "SDeviceCore/core.h"

#define __CORE_GLOBAL_SDEVICE_INSTANCE_INDEX 0

__SDEVICE_HANDLE_FORWARD_DECLARATION(CoreGlobal);
__SDEVICE_INIT_DATA_FORWARD_DECLARATION(CoreGlobal);

typedef enum
{
   CORE_GLOBAL_SDEVICE_STATUS_OK
} CoreGlobalSDeviceStatus;

typedef enum
{
   CORE_GLOBAL_SDEVICE_EXCEPTION_OUT_OF_MEMORY
} CoreGlobalSDeviceException;

struct __SDEVICE_INIT_DATA(CoreGlobal) { };

extern __SDEVICE_HANDLE(CoreGlobal) *CoreGlobalSDeviceHandle;
