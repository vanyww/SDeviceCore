#include "SDeviceCore/global.h"

#ifdef SDEVICE_USE_EXTERNAL_GLOBAL_CONTEXT
#include "global_sdevice_context.h"
#endif

SDEVICE_RUNTIME_DATA_FORWARD_DECLARATION(CoreGlobal);
SDEVICE_INIT_DATA_FORWARD_DECLARATION(CoreGlobal);

SDEVICE_RUNTIME_DATA_DECLARATION(CoreGlobal) { };
SDEVICE_INIT_DATA_DECLARATION(CoreGlobal) { };

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
