#include "SDeviceCore/global.h"
#include "SDeviceCore/config.h"

SDEVICE_RUNTIME_DATA_FORWARD_DECLARATION(CoreGlobal);
SDEVICE_INIT_DATA_FORWARD_DECLARATION(CoreGlobal);

SDEVICE_RUNTIME_DATA_DECLARATION(CoreGlobal) { };
SDEVICE_INIT_DATA_DECLARATION(CoreGlobal) { };

SDEVICE_HANDLE_DECLARATION(CoreGlobal);

/* 78be0543-4a77-11ee-8689-93f017f8080a */
SDEVICE_UUID_DEFINITION(CoreGlobal, 0x78be05434a7711ee, 0x868993f017f8080a);

SDEVICE_HANDLE(CoreGlobal) *const CoreGlobalSDeviceHandle = &(SDEVICE_HANDLE(CoreGlobal))
{
   .Header =
   {
      .Context      = SDEVICE_CORE_GLOBAL_HANDLE_CONTEXT,
      .OwnerHandle  = NULL,
      .Uuid         = &SDEVICE_UUID(CoreGlobal),
      .LatestStatus = CORE_GLOBAL_SDEVICE_STATUS_OK,
      .Identifier   = SDEVICE_CORE_GLOBAL_HANDLE_IDENTIFIER
   }
};
