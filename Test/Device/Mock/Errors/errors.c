#include "errors.h"
#include "SDeviceCore/errors.h"

const void *LastThrowedPanicHandle;
const void *LastLogStatusHandle;
bool AssertFailedCalled;

void SDeviceProcessAssertFail(char *file, int line)
{
   AssertFailedCalled = true;
}

void SDeviceProcessPanic(const void *_handle)
{
   LastThrowedPanicHandle = _handle;
}

void SDeviceProcessLogStatus(const void *_handle, const void *extras, size_t extrasSize)
{
   LastLogStatusHandle = _handle;
}
