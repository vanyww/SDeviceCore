#pragma once

#include "SDeviceCore/core.h"

SDEVICE_HANDLE_FORWARD_DECLARATION(CoreGlobal);

typedef enum
{
   CORE_GLOBAL_SDEVICE_STATUS_OK
} CoreGlobalSDeviceStatus;

typedef enum
{
   CORE_GLOBAL_SDEVICE_EXCEPTION_OUT_OF_MEMORY
} CoreGlobalSDeviceException;

extern SDEVICE_HANDLE(CoreGlobal) *CoreGlobalSDeviceHandle;
