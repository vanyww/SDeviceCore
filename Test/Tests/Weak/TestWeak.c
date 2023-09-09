#include "SDeviceCore/errors.h"

#include "../../Device/Inc/public.h"
#include "../../Device/Mock/Errors/errors.h"

#include "unity_fixture.h"

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

TEST(Weak, SDevicePanic)
{
   void *context = NULL;
   void *owner = NULL;
   SDeviceHandleIdentifier id = 0;

   SDEVICE_INIT_DATA(TestDevice) init = { .testDeviceData ={ .FirstValue = 0, .SecondValue = 0 } };

   _cleanup SDEVICE_HANDLE(TestDevice) *handle = SDEVICE_CREATE_HANDLE(TestDevice)(&init, owner, id, context);

   int16_t status = TEST_DEVICE_SDEVICE_SOME_PANIC;

   SDevicePanic(handle, TEST_DEVICE_SDEVICE_SOME_PANIC);

   TEST_ASSERT_EQUAL(handle, LastThrowedPanicHandle);
   TEST_ASSERT_EQUAL(status, SDeviceGetHandleLatestStatus(LastThrowedPanicHandle));
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

TEST_GROUP_RUNNER(Weak)
{
   RUN_TEST_CASE(Weak, SDeviceAssert);
   RUN_TEST_CASE(Weak, SDevicePanic);
   RUN_TEST_CASE(Weak, SDeviceLogStatus);
}