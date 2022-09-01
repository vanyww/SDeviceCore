#include "SDeviceCore/global.h"

__SDEVICE_RUNTIME_DATA_FORWARD_DECLARATION(CoreGlobal);

__SDEVICE_STRING_NAME_DEFINITION(CoreGlobal);

struct __SDEVICE_RUNTIME_DATA(CoreGlobal) { };

__SDEVICE_HANDLE_DECLARATION(CoreGlobal);

__SDEVICE_HANDLE(CoreGlobal) *CoreGlobalSDeviceHandle = &(__SDEVICE_HANDLE(CoreGlobal))
{
   .Header =
   {
      .Context = NULL,
      .NameNode = { .Name = __SDEVICE_STRING_NAME(CoreGlobal), .OuterNode = NULL },
      .LatestStatus = CORE_GLOBAL_SDEVICE_STATUS_OK
   }
};
