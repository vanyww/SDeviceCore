#include "SDeviceCore/errors.h"

#include "../../Mock/SDevice/Inc/public.h"
#include "../../Mock/Errors/errors.h"

#include "unity_fixture.h"

#define _cleanup __attribute__((cleanup(SDEVICE_DISPOSE_HANDLE(Test))))

TEST_GROUP(Errors);

TEST_SETUP(Errors) { }
TEST_TEAR_DOWN(Errors) { }

TEST(Errors, SDeviceAssert)
{
   WasAssertFailedCalled = false;

   SDeviceAssert(false);

   TEST_ASSERT(WasAssertFailedCalled);
}

TEST(Errors, SDevicePanic)
{
   void *owner = NULL;
   void *context = NULL;
   SDeviceHandleIdentifier identifier = 0;

   SDEVICE_INIT_DATA(Test) init = { .TestData = { .FirstValue = 0, .SecondValue = 0 } };

   _cleanup SDEVICE_HANDLE(Test) *handle = SDEVICE_CREATE_HANDLE(Test)(&init, owner, identifier, context);

   SDeviceHandleStatus panic = TEST_SDEVICE_SOME_PANIC;
   SDevicePanic(handle, panic);

   TEST_ASSERT_EQUAL(handle, LastThrowedPanicHandle);
   TEST_ASSERT_EQUAL(panic, SDeviceGetHandleLatestStatus(LastThrowedPanicHandle));
}

TEST(Errors, SDeviceLogStatus)
{
   void *owner = NULL;
   void *context = NULL;
   SDeviceHandleIdentifier identifier = 0;

   SDEVICE_INIT_DATA(Test) init = { .TestData = { .FirstValue = 0, .SecondValue = 0 } };

   _cleanup SDEVICE_HANDLE(Test) *handle = SDEVICE_CREATE_HANDLE(Test)(&init, owner, identifier, context);

   SDeviceHandleStatus status = 0xAAAA;
   SDeviceLogStatus(handle, status);

   TEST_ASSERT_EQUAL(handle, LastLogStatusHandle);
   TEST_ASSERT_EQUAL(status, SDeviceGetHandleLatestStatus(LastLogStatusHandle));
}

TEST_GROUP_RUNNER(Errors)
{
   RUN_TEST_CASE(Errors, SDeviceAssert);
   RUN_TEST_CASE(Errors, SDevicePanic);
   RUN_TEST_CASE(Errors, SDeviceLogStatus);
}
