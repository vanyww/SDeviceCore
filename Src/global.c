#include "SDeviceCore/global.h"

SDEVICE_RUNTIME_DATA_FORWARD_DECLARATION(CoreGlobal);

SDEVICE_STRING_NAME_DEFINITION(CoreGlobal);

struct SDEVICE_RUNTIME_DATA(CoreGlobal) { };

SDEVICE_HANDLE_DECLARATION(CoreGlobal);

SDEVICE_HANDLE(CoreGlobal) *CoreGlobalSDeviceHandle = &(SDEVICE_HANDLE(CoreGlobal))
{
   .Header =
   {
      .Context = NULL,
      .NameNode = { .Name = SDEVICE_STRING_NAME(CoreGlobal), .OuterNode = NULL },
      .LatestStatus = CORE_GLOBAL_SDEVICE_STATUS_OK
   }
};
