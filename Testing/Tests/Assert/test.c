#include "SDeviceCore/assert.h"

#include "../../Mock/Bindings/sdevice_core.h"

#include "unity_fixture.h"

static bool was_assert_handler_called = false;

static void TestAssertHandler(void)
{
   was_assert_handler_called = true;
}

TEST_GROUP(Assert);

TEST_SETUP(Assert)
{
   was_assert_handler_called = false;
}

TEST_TEAR_DOWN(Assert) { }

TEST(Assert, SDeviceAssertTrue)
{
   SetAssertFailHandler(TestAssertHandler);

   SDeviceAssert(false);

   SetAssertFailHandler(NULL);

   TEST_ASSERT_TRUE(was_assert_handler_called);
}

TEST(Assert, SDeviceAssertFalse)
{
   SetAssertFailHandler(TestAssertHandler);

   SDeviceAssert(true);

   SetAssertFailHandler(NULL);

   TEST_ASSERT_FALSE(was_assert_handler_called);
}

TEST_GROUP_RUNNER(Assert)
{
   RUN_TEST_CASE(Assert, SDeviceAssertTrue);
   RUN_TEST_CASE(Assert, SDeviceAssertFalse);
}
