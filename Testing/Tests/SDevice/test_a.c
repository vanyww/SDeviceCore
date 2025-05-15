#include "../../Mock/SDevice/Inc/public.h"

#include "unity_fixture.h"

static int HandleContext;
static SDEVICE_HANDLE(Test) *Handle;
static SDEVICE_INIT_DATA(Test) HandleInit =
{
   .InitData =
   {
      .First  = 1,
      .Second = 2
   }
};

TEST_GROUP(SDeviceCore_A);

TEST_SETUP(SDeviceCore_A)
{
   Handle = SDEVICE_CREATE_HANDLE(Test)(&HandleInit, &HandleContext);
}

TEST_TEAR_DOWN(SDeviceCore_A)
{
   SDEVICE_DISPOSE_HANDLE(Test)(Handle);
}

TEST(SDeviceCore_A, Initialization)
{
   TEST_ASSERT_NOT_NULL(Handle);
   TEST_ASSERT_EQUAL_PTR(&HandleContext, SDeviceGetHandleContext(Handle));

   SDEVICE_PROPERTY_TYPE(Test, SimplePropertyValue) read;

   TEST_ASSERT_EQUAL(
         SDEVICE_PROPERTY_STATUS_OK,
         SDEVICE_GET_SIMPLE_PROPERTY(Test, SimplePropertyValue)(Handle, &read));

   TEST_ASSERT_EQUAL_INT(HandleInit.InitData.First, read.First);
   TEST_ASSERT_EQUAL_INT(HandleInit.InitData.Second, read.Second);
}

TEST_GROUP_RUNNER(SDeviceCore_A)
{
   RUN_TEST_CASE(SDeviceCore_A, Initialization);
}
