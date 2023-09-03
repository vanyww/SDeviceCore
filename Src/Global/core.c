#include "private.h"

/* 78be0543-4a77-11ee-8689-93f017f8080a */
SDEVICE_UUID_DEFINITION(CoreGlobal, 0x78be05434a7711ee, 0x868993f017f8080a);

static SDEVICE_HANDLE(CoreGlobal) *const CoreGlobalSDeviceHandle = &(SDEVICE_HANDLE(CoreGlobal))
{
   .Header =
   {
      .Context      = CORE_GLOBAL_SDEVICE_HANDLE_CONTEXT,
      .OwnerHandle  = NULL,
      .Uuid         = &SDEVICE_UUID(CoreGlobal),
      .LatestStatus = CORE_GLOBAL_SDEVICE_STATUS_OK,
      .Identifier   = CORE_GLOBAL_SDEVICE_HANDLE_IDENTIFIER
   }
};

void CoreGlobalSDeviceThrowPanic(CoreGlobalSDevicePanic panic)
{
   SDevicePanic(CoreGlobalSDeviceHandle, panic);
}

void CoreGlobalSDeviceLogStatus(CoreGlobalSDeviceStatus status)
{
   SDeviceLogStatus(CoreGlobalSDeviceHandle, status);
}
