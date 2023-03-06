#include "SDeviceCore/global.h"

#ifdef SDEVICE_USE_EXTERNAL_GLOBAL_CONTEXT
#include "global_sdevice_context.h"
#endif

SDEVICE_RUNTIME_DATA_FORWARD_DECLARATION(CoreGlobal);
SDEVICE_INIT_DATA_FORWARD_DECLARATION(CoreGlobal);

SDEVICE_RUNTIME_DATA_DECLARATION(CoreGlobal) { };
SDEVICE_INIT_DATA_DECLARATION(CoreGlobal) { };

SDEVICE_HANDLE_DECLARATION(CoreGlobal);

SDEVICE_HANDLE(CoreGlobal) *const CoreGlobalSDeviceHandle = &(SDEVICE_HANDLE(CoreGlobal))
{
   .Header =
   {
#ifdef SDEVICE_CORE_GLOBAL_CONTEXT
      .Context = &SDEVICE_CORE_GLOBAL_CONTEXT,
#else
      .Context = NULL,
#endif

#ifdef SDEVICE_CORE_GLOBAL_HANDLE_IDENTIFIER
      .Identifier = SDEVICE_CORE_GLOBAL_HANDLE_ID,
#endif

      .ParentHandle = NULL,
      .LatestStatus = CORE_GLOBAL_SDEVICE_STATUS_OK
   }
};
