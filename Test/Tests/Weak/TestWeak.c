#include "unity_fixture.h"
#include "weak.h"
#include "SDeviceCore/errors.h"
#include "../SDevice/TestCore.h"

#define _cleanup __attribute__((cleanup(SDEVICE_DISPOSE_HANDLE(TestDevice))))

TEST_GROUP(Weak);

TEST_SETUP(Weak){}
TEST_TEAR_DOWN(Weak){}

TEST(Weak, SDeviceAssert)
{
   AssertFailedCalled = false;

   SDeviceAssert(false);
   TEST_ASSERT(AssertFailedCalled);
}

TEST(Weak, SDeviceHandledThrow)
{
   void *context = NULL;
   void *owner = NULL;
   SDeviceHandleIdentifier id = 0;

   SDEVICE_INIT_DATA(TestDevice) init = { .testDeviceData ={ .FirstValue = 0, .SecondValue = 0 } };

   _cleanup SDEVICE_HANDLE(TestDevice) *handle = SDEVICE_CREATE_HANDLE(TestDevice)(&init, owner, id, context);

   int16_t exception = 0xAAAA;
   volatile CEXCEPTION_T e;

   Try
   {
      SDeviceThrow(handle, exception);
   }
   Catch(e)
   {
      TEST_ASSERT(handle == e && SDeviceGetHandleLatestStatus (e) == exception);
   }
}

TEST(Weak, SDeviceUnhandledThrow)
{
   void *context = NULL;
   void *owner = NULL;
   SDeviceHandleIdentifier id = 0;

   SDEVICE_INIT_DATA(TestDevice) init = { .testDeviceData ={ .FirstValue = 0, .SecondValue = 0 } };

   _cleanup SDEVICE_HANDLE(TestDevice) *handle = SDEVICE_CREATE_HANDLE(TestDevice)(&init, owner, id, context);

   int16_t exception = 0xAAAA;

   SDeviceThrow(handle, exception);

   TEST_ASSERT(handle == LastUnhandledThrowHandle && SDeviceGetHandleLatestStatus(LastUnhandledThrowHandle) == exception);
}

TEST(Weak, SDeviceLogStatus)
{
   void *context = NULL;
   void *owner = NULL;
   SDeviceHandleIdentifier id = 0;

   SDEVICE_INIT_DATA(TestDevice) init = { .testDeviceData = { .FirstValue = 0, .SecondValue = 0 } };

   _cleanup SDEVICE_HANDLE(TestDevice) *handle = SDEVICE_CREATE_HANDLE(TestDevice)(&init, owner, id, context);

   int16_t status = 0xAAAA;

   SDeviceLogStatus(handle, status);

   TEST_ASSERT(handle == LastLogStatusHandle && SDeviceGetHandleLatestStatus(LastLogStatusHandle) == status);
}
