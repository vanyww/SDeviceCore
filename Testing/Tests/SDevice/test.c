#include "../../Mock/SDevice/Inc/public.h"

#include "SDeviceCore/common.h"

#include "unity_fixture.h"

#include <memory.h>

#define _cleanup __attribute__((cleanup(SDEVICE_DISPOSE_HANDLE(Test))))

TEST_GROUP(SDeviceCore);

TEST_SETUP(SDeviceCore) { }
TEST_TEAR_DOWN(SDeviceCore) { }

TEST(SDeviceCore, Initialization)
{
   SDEVICE_INIT_DATA(Test) init =
   {
      .InitData =
      {
         .First  = 1,
         .Second = 2
      }
   };

   int context;

   _cleanup SDEVICE_HANDLE(Test) *handle = SDEVICE_CREATE_HANDLE(Test)(&init, &context);

   TEST_ASSERT_NOT_NULL(handle);
   TEST_ASSERT_EQUAL_PTR(&context, SDeviceGetHandleContext(handle));

   SDEVICE_PROPERTY_TYPE(Test, SimplePropertyValue) read;

   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK,
                     SDEVICE_GET_SIMPLE_PROPERTY(Test, SimplePropertyValue)(handle, &read));

   TEST_ASSERT_EQUAL_INT(init.InitData.First, read.First);
   TEST_ASSERT_EQUAL_INT(init.InitData.Second, read.Second);
}

TEST(SDeviceCore, SimpleProperty)
{
   SDEVICE_INIT_DATA(Test) init = { };

   _cleanup SDEVICE_HANDLE(Test) *handle = SDEVICE_CREATE_HANDLE(Test)(&init, NULL);

   SDEVICE_PROPERTY_TYPE(Test, SimplePropertyValue) read, write =
   {
      .First  = 10,
      .Second = 20
   };

   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK,
                     SDEVICE_SET_SIMPLE_PROPERTY(Test, SimplePropertyValue)(handle, &write));

   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK,
                     SDEVICE_GET_SIMPLE_PROPERTY(Test, SimplePropertyValue)(handle, &read));

   TEST_ASSERT_EQUAL_INT(write.First, read.First);
   TEST_ASSERT_EQUAL_INT(write.Second, read.Second);
}

TEST(SDeviceCore, PartialProperty)
{
   SDEVICE_INIT_DATA(Test) init = { };

   _cleanup SDEVICE_HANDLE(Test) *handle = SDEVICE_CREATE_HANDLE(Test)(&init, NULL);

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

   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK,
                     SDEVICE_SET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(handle, &writeParameters));

   SDEVICE_PROPERTY_TYPE(Test, PartialPropertyValue) read;
   SDeviceGetPartialPropertyParameters readParameters =
   {
      .Data   = &read,
      .Offset = 0,
      .Size   = sizeof(read)
   };

   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK,
                     SDEVICE_GET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(handle, &readParameters));

   TEST_ASSERT_EQUAL_CHAR_ARRAY(write.Value, read.Value, LENGTHOF(read.Value));

   size_t writeOffset = LENGTHOF(write.Value) / 2;
   size_t writeSize = (LENGTHOF(write.Value) - writeOffset) * sizeof(*write.Value);

   memset(&write.Value[writeOffset], '2', writeSize);

   writeParameters.Offset = writeOffset;
   writeParameters.Size = writeSize;
   writeParameters.Data = &write.Value[writeOffset];

   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK,
                     SDEVICE_SET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(handle, &writeParameters));

   readParameters.Offset = writeOffset;
   readParameters.Size = writeSize;
   readParameters.Data = &read.Value[writeOffset];

   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK,
                     SDEVICE_GET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(handle, &readParameters));

   TEST_ASSERT_EQUAL_CHAR_ARRAY(write.Value, read.Value, LENGTHOF(read.Value));
}

TEST_GROUP_RUNNER(SDeviceCore)
{
   RUN_TEST_CASE(SDeviceCore, Initialization);
   RUN_TEST_CASE(SDeviceCore, SimpleProperty);
   RUN_TEST_CASE(SDeviceCore, PartialProperty);
}
