#include "SDeviceCore/interface.h"

#include <stddef.h>

void SDeviceInitializeHandleCommon(bool (* initializeInternals)(void *),
                                   const void *constantData,
                                   void *settingsData,
                                   void *handle)
{
   SDeviceAssert(handle != NULL);
   SDeviceAssert(initializeInternals != NULL);

   SDeviceCommonHandle *commonHandle = handle;

   commonHandle->Constant = constantData;
   commonHandle->Settings = settingsData;

   bool __attribute__((unused)) status = initializeInternals(handle);

   SDeviceAssert(status == true);
}

__attribute__((weak)) void SDeviceAssertFailed(char *file, int line)
{
   for(;;) { }
}
