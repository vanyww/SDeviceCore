#include "SDeviceCore/assert.h"

#include "../../Mock/Bindings/sdevice_core.h"

#include "unity_fixture.h"

static bool WasAssertHandlerCalled = false;

static void TestAssertHandler(void)
{
   WasAssertHandlerCalled = true;

   TEST_MESSAGE("OK");
}

TEST_GROUP(Assert);

TEST_SETUP(Assert) { }
TEST_TEAR_DOWN(Assert) { }

TEST(Assert, SDeviceAssert)
{
   SetAssertFailHandler(TestAssertHandler);

   SDeviceAssert(false);

   ResetAssertFailHandler();

   TEST_ASSERT(WasAssertHandlerCalled);
}

TEST_GROUP_RUNNER(Assert)
{
   RUN_TEST_CASE(Assert, SDeviceAssert);
}
