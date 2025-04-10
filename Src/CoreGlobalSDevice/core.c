#include "private.h"

#include "SDeviceCore/errors.h"

static ThisHandle *const CoreGlobalHandle = &(ThisHandle)
{
   .Context = CORE_GLOBAL_SDEVICE_HANDLE_CONTEXT
};

void CoreGlobalSDeviceThrowPanic(CoreGlobalSDevicePanic panic)
{
   SDeviceThrowPanic(CoreGlobalHandle, panic);
}
