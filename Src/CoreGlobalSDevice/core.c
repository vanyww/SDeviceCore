#include "private.h"

SDEVICE_IDENTITY_BLOCK_DEFINITION(CoreGlobal,
                                  ((const SDeviceUuid)
                                  {
                                     .High = CORE_GLOBAL_SDEVICE_UUID_HIGH,
                                     .Low  = CORE_GLOBAL_SDEVICE_UUID_LOW
                                  }),
                                  ((const SDeviceVersion)
                                  {
                                     .Major = CORE_GLOBAL_SDEVICE_VERSION_MAJOR,
                                     .Minor = CORE_GLOBAL_SDEVICE_VERSION_MINOR,
                                     .Patch = CORE_GLOBAL_SDEVICE_VERSION_PATCH
                                  }));

static ThisHandle *const CoreGlobalSDeviceHandle = &(ThisHandle)
{
   .Header =
   {
      .Context       = CORE_GLOBAL_SDEVICE_HANDLE_CONTEXT,
      .OwnerHandle   = NULL,
      .IdentityBlock = &SDEVICE_IDENTITY_BLOCK(CoreGlobal),
      .LatestStatus  = CORE_GLOBAL_SDEVICE_STATUS_OK,
      .Identifier    = CORE_GLOBAL_SDEVICE_HANDLE_IDENTIFIER
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
