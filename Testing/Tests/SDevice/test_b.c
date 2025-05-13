#include "../../Mock/SDevice/Inc/public.h"

#include "SDeviceCore/common.h"

#include "unity_fixture.h"

#include <memory.h>

SDEVICE_HANDLE(Test) *Handle;

TEST_GROUP(SDeviceCore_B);

TEST_SETUP(SDeviceCore_B)
{
   SDEVICE_INIT_DATA(Test) init = { };

   Handle = SDEVICE_CREATE_HANDLE(Test)(&init, NULL);
}

TEST_TEAR_DOWN(SDeviceCore_B)
{
   SDEVICE_DISPOSE_HANDLE(Test)(Handle);
}

TEST(SDeviceCore_B, SimpleProperty)
{
   SDEVICE_PROPERTY_TYPE(Test, SimplePropertyValue) read, write =
   {
      .First  = 10,
      .Second = 20
   };

   TEST_ASSERT_EQUAL(
         SDEVICE_PROPERTY_STATUS_OK,
         SDEVICE_SET_SIMPLE_PROPERTY(Test, SimplePropertyValue)(Handle, &write));

   TEST_ASSERT_EQUAL(
         SDEVICE_PROPERTY_STATUS_OK,
         SDEVICE_GET_SIMPLE_PROPERTY(Test, SimplePropertyValue)(Handle, &read));

   TEST_ASSERT_EQUAL_INT(write.First, read.First);
   TEST_ASSERT_EQUAL_INT(write.Second, read.Second);
}

TEST(SDeviceCore_B, PartialProperty)
{
   SDEVICE_PROPERTY_TYPE(Test, PartialPropertyValue) write =
   {
      .Value[0 ... LENGTHOF(write.Value) - 1] = '1'
   };

   SDeviceSetPartialPropertyParameters writeParameters =
   {
      .Data   = &write,
      .Offset = 0,
      .Size   = sizeof(write)
   };

   TEST_ASSERT_EQUAL(
         SDEVICE_PROPERTY_STATUS_OK,
         SDEVICE_SET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(Handle, &writeParameters));

   SDEVICE_PROPERTY_TYPE(Test, PartialPropertyValue) read;
   SDeviceGetPartialPropertyParameters readParameters =
   {
      .Data   = &read,
      .Offset = 0,
      .Size   = sizeof(read)
   };

   TEST_ASSERT_EQUAL(
         SDEVICE_PROPERTY_STATUS_OK,
         SDEVICE_GET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(Handle, &readParameters));

   TEST_ASSERT_EQUAL_CHAR_ARRAY(write.Value, read.Value, LENGTHOF(read.Value));

   size_t writeOffset = LENGTHOF(write.Value) / 2;
   size_t writeSize = (LENGTHOF(write.Value) - writeOffset) * sizeof(*write.Value);

   memset(&write.Value[writeOffset], '2', writeSize);

   writeParameters.Offset = writeOffset;
   writeParameters.Size = writeSize;
   writeParameters.Data = &write.Value[writeOffset];

   TEST_ASSERT_EQUAL(
         SDEVICE_PROPERTY_STATUS_OK,
         SDEVICE_SET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(Handle, &writeParameters));

   readParameters.Offset = writeOffset;
   readParameters.Size = writeSize;
   readParameters.Data = &read.Value[writeOffset];

   TEST_ASSERT_EQUAL(
         SDEVICE_PROPERTY_STATUS_OK,
         SDEVICE_GET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(Handle, &readParameters));

   TEST_ASSERT_EQUAL_CHAR_ARRAY(write.Value, read.Value, LENGTHOF(read.Value));
}

TEST_GROUP_RUNNER(SDeviceCore_B)
{
   RUN_TEST_CASE(SDeviceCore_B, SimpleProperty);
   RUN_TEST_CASE(SDeviceCore_B, PartialProperty);
}
