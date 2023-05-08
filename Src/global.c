#include "SDeviceCore/global.h"
#include "SDeviceCore/config.h"

SDEVICE_RUNTIME_DATA_FORWARD_DECLARATION(CoreGlobal);
SDEVICE_INIT_DATA_FORWARD_DECLARATION(CoreGlobal);

SDEVICE_RUNTIME_DATA_DECLARATION(CoreGlobal)
{

};

SDEVICE_INIT_DATA_DECLARATION(CoreGlobal)
{

};

SDEVICE_HANDLE_DECLARATION(CoreGlobal);
SDEVICE_STRING_NAME_DEFINITION(CoreGlobal);

SDEVICE_HANDLE(CoreGlobal) *const CoreGlobalSDeviceHandle = &(SDEVICE_HANDLE(CoreGlobal))
{
   .Header =
   {
      .Context = SDEVICE_CORE_GLOBAL_HANDLE_CONTEXT,
      .OwnerHandle = NULL,
      .SDeviceStringName = SDEVICE_STRING_NAME(CoreGlobal),
      .LatestStatus = CORE_GLOBAL_SDEVICE_STATUS_OK,
      .Identifier = SDEVICE_CORE_GLOBAL_HANDLE_IDENTIFIER
   }
};
