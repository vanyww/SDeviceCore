#include "SDeviceCore/global.h"

static const char DeviceName[] = "CoreGlobal\0";

__SDEVICE_RUNTIME_DATA_FORWARD_DECLARATION(CoreGlobal);

struct __SDEVICE_RUNTIME_DATA(CoreGlobal) { };

__SDEVICE_HANDLE_DEFINITION(CoreGlobal);

__SDEVICE_HANDLE(CoreGlobal) *CoreGlobalSDeviceHandle = &(__SDEVICE_HANDLE(CoreGlobal))
{
   .Header =
   {
      .Context = NULL,
      .NameNode = { .Name = DeviceName, .OuterNode = NULL },
      .LatestStatus = CORE_GLOBAL_SDEVICE_STATUS_OK
   }
};
