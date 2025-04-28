#include "SDeviceCore/errors.h"

#include "../../Mock/SDevice/Inc/public.h"
#include "../../Mock/Bindings/sdevice_core.h"

#include "unity_fixture.h"

#define _cleanup __attribute__((cleanup(SDEVICE_DISPOSE_HANDLE(Test))))

static bool WasAssertHandlerCalled = false;
static const void *PanicHandle = NULL;
SDevicePanic Panic = UINT16_MAX;

static void TestAssertHandler(void)
{
   WasAssertHandlerCalled = true;

   TEST_MESSAGE("OK");
}

static void TestPanicHandler(const void *handle, SDevicePanic panic)
{
   PanicHandle = handle;
   Panic = panic;

   TEST_MESSAGE("OK");
}

TEST_GROUP(Errors);

TEST_SETUP(Errors) { }
TEST_TEAR_DOWN(Errors) { }

TEST(Errors, SDeviceAssert)
{
   SetAssertFailHandler(TestAssertHandler);

   SDeviceAssert(false);

   ResetAssertFailHandler();

   TEST_ASSERT(WasAssertHandlerCalled);
}

TEST(Errors, SDevicePanic)
{
   SDEVICE_INIT_DATA(Test) init = { };

   _cleanup SDEVICE_HANDLE(Test) *handle = SDEVICE_CREATE_HANDLE(Test)(&init, NULL);

   SetPanicHandler(TestPanicHandler);

   SDevicePanic panic = TEST_SDEVICE_PANIC;
   SDeviceThrowPanic(handle, panic);

   ResetPanicHandler();

   TEST_ASSERT_EQUAL(handle, PanicHandle);
   TEST_ASSERT_EQUAL(panic, Panic);
}

TEST_GROUP_RUNNER(Errors)
{
   RUN_TEST_CASE(Errors, SDeviceAssert);
   RUN_TEST_CASE(Errors, SDevicePanic);
}
