#include "SDeviceCore/global.h"

__SDEVICE_RUNTIME_DATA_FORWARD_DECLARATION(CoreGlobal);

struct __SDEVICE_RUNTIME_DATA(CoreGlobal) { };

__SDEVICE_HANDLE_DEFINITION(CoreGlobal);

__SDEVICE_HANDLE(CoreGlobal) *CoreGlobalSDeviceHandle = &(__SDEVICE_HANDLE(CoreGlobal))
{
   .Header =
   {
      .Context = NULL,
      .LatestStatus = CORE_GLOBAL_SDEVICE_STATUS_OK,
      .InstanceIndex = __CORE_GLOBAL_SDEVICE_INSTANCE_INDEX
   }
};
