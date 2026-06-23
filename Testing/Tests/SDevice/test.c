#include "../../Mock/SDevice/Inc/public.h"

#include "SDeviceCore/common.h"

#include "unity_fixture.h"

#include <memory.h>

static int handle_context;

static SDEVICE_HANDLE(Test) *handle;

static SDEVICE_INIT_DATA(Test) handle_init =
{
   .InitData =
   {
      .First  = 1,
      .Second = 2
   }
};

TEST_GROUP(SDeviceCore);

TEST_SETUP(SDeviceCore)
{
   handle = SDEVICE_CREATE_HANDLE(Test)(&handle_init, &handle_context);
}

TEST_TEAR_DOWN(SDeviceCore)
{
   SDEVICE_DISPOSE_HANDLE(Test)(handle);
}

TEST(SDeviceCore, Initialization)
{
   TEST_ASSERT_NOT_NULL(handle);
   TEST_ASSERT_EQUAL_PTR(&handle_context, SDeviceGetHandleContext(handle));

   SDEVICE_PROPERTY_TYPE(Test, SimplePropertyValue) read;

   TEST_ASSERT_EQUAL(
         SDevicePropertyStatusOk,
         SDEVICE_GET_SIMPLE_PROPERTY(Test, SimplePropertyValue)(handle, &read));

   TEST_ASSERT_EQUAL_INT(handle_init.InitData.First, read.First);
   TEST_ASSERT_EQUAL_INT(handle_init.InitData.Second, read.Second);
}

TEST(SDeviceCore, HandleAccessors)
{
   TEST_ASSERT_EQUAL_PTR(&handle_context, SDeviceGetHandleContext(handle));

   const SDEVICE_INIT_DATA(Test) *init_data = SDeviceGetHandleInitData(handle);
   TEST_ASSERT_NOT_NULL(init_data);
   TEST_ASSERT_EQUAL_INT(handle_init.InitData.First, init_data->InitData.First);
   TEST_ASSERT_EQUAL_INT(handle_init.InitData.Second, init_data->InitData.Second);

   TEST_ASSERT_NOT_NULL(SDeviceGetHandleRuntimeData(handle));
}

TEST(SDeviceCore, PropertyStatusValidation)
{
   TEST_ASSERT_TRUE(SDevicePropertyStatusIsValid(SDevicePropertyStatusOk));
   TEST_ASSERT_TRUE(SDevicePropertyStatusIsValid(SDevicePropertyStatusValidationError));
   TEST_ASSERT_TRUE(SDevicePropertyStatusIsValid(SDevicePropertyStatusProcessingError));
   TEST_ASSERT_FALSE(SDevicePropertyStatusIsValid((SDevicePropertyStatus)-1));
   TEST_ASSERT_FALSE(SDevicePropertyStatusIsValid((SDevicePropertyStatus)999));
}

TEST(SDeviceCore, SimpleProperty)
{
   SDEVICE_PROPERTY_TYPE(Test, SimplePropertyValue) read, write =
   {
      .First  = 10,
      .Second = 20
   };

   TEST_ASSERT_EQUAL(
         SDevicePropertyStatusOk,
         SDEVICE_SET_SIMPLE_PROPERTY(Test, SimplePropertyValue)(handle, &write));

   TEST_ASSERT_EQUAL(
         SDevicePropertyStatusOk,
         SDEVICE_GET_SIMPLE_PROPERTY(Test, SimplePropertyValue)(handle, &read));

   TEST_ASSERT_EQUAL_INT(write.First, read.First);
   TEST_ASSERT_EQUAL_INT(write.Second, read.Second);
}

TEST(SDeviceCore, PartialPropertyFullRoundTrip)
{
   SDEVICE_PROPERTY_TYPE(Test, PartialPropertyValue) write =
   {
      .Value[0 ... LENGTHOF(write.Value) - 1] = '1'
   };

   SDeviceSetPartialPropertyParameters write_parameters =
   {
      .Data   = &write,
      .Offset = 0,
      .Size   = sizeof(write)
   };

   TEST_ASSERT_EQUAL(
         SDevicePropertyStatusOk,
         SDEVICE_SET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(handle, &write_parameters));

   SDEVICE_PROPERTY_TYPE(Test, PartialPropertyValue) read;
   SDeviceGetPartialPropertyParameters read_parameters =
   {
      .Data   = &read,
      .Offset = 0,
      .Size   = sizeof(read)
   };

   TEST_ASSERT_EQUAL(
         SDevicePropertyStatusOk,
         SDEVICE_GET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(handle, &read_parameters));

   TEST_ASSERT_EQUAL_CHAR_ARRAY(write.Value, read.Value, LENGTHOF(read.Value));
}

TEST(SDeviceCore, PartialPropertyOffsetWrite)
{
   SDEVICE_PROPERTY_TYPE(Test, PartialPropertyValue) write =
   {
      .Value[0 ... LENGTHOF(write.Value) - 1] = '1'
   };
   SDEVICE_PROPERTY_TYPE(Test, PartialPropertyValue) read;

   SDeviceSetPartialPropertyParameters write_parameters =
   {
      .Data   = &write,
      .Offset = 0,
      .Size   = sizeof(write)
   };

   /* initialize the whole property to '1' */
   TEST_ASSERT_EQUAL(
         SDevicePropertyStatusOk,
         SDEVICE_SET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(handle, &write_parameters));

   /* overwrite only the second half with '2' */
   size_t write_offset = LENGTHOF(write.Value) / 2;
   size_t write_size = (LENGTHOF(write.Value) - write_offset) * sizeof(*write.Value);

   memset(&write.Value[write_offset], '2', write_size);

   write_parameters.Offset = write_offset;
   write_parameters.Size = write_size;
   write_parameters.Data = &write.Value[write_offset];

   TEST_ASSERT_EQUAL(
         SDevicePropertyStatusOk,
         SDEVICE_SET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(handle, &write_parameters));

   /* read the whole property back and compare */
   SDeviceGetPartialPropertyParameters read_parameters =
   {
      .Data   = &read,
      .Offset = 0,
      .Size   = sizeof(read)
   };

   TEST_ASSERT_EQUAL(
         SDevicePropertyStatusOk,
         SDEVICE_GET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(handle, &read_parameters));

   TEST_ASSERT_EQUAL_CHAR_ARRAY(write.Value, read.Value, LENGTHOF(read.Value));
}

TEST(SDeviceCore, PartialPropertyValidationErrors)
{
   SDEVICE_PROPERTY_TYPE(Test, PartialPropertyValue) value;

   SDeviceSetPartialPropertyParameters set_parameters =
   {
      .Data   = &value,
      .Offset = 0,
      .Size   = 0
   };

   /* Size larger than the property */
   set_parameters.Size = sizeof(value) + 1;
   TEST_ASSERT_EQUAL(
         SDevicePropertyStatusValidationError,
         SDEVICE_SET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(handle, &set_parameters));

   /* Offset + Size overflows the property */
   set_parameters.Size = 1;
   set_parameters.Offset = sizeof(value);
   TEST_ASSERT_EQUAL(
         SDevicePropertyStatusValidationError,
         SDEVICE_SET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(handle, &set_parameters));

   /* Size + Offset overflows size_t itself (arithmetic overflow) */
   set_parameters.Size = (size_t)-1;
   set_parameters.Offset = 1;
   TEST_ASSERT_EQUAL(
         SDevicePropertyStatusValidationError,
         SDEVICE_SET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(handle, &set_parameters));

   SDeviceGetPartialPropertyParameters get_parameters =
   {
      .Data   = &value,
      .Offset = 0,
      .Size   = 0
   };

   get_parameters.Size = sizeof(value) + 1;
   TEST_ASSERT_EQUAL(
         SDevicePropertyStatusValidationError,
         SDEVICE_GET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(handle, &get_parameters));

   get_parameters.Size = 1;
   get_parameters.Offset = sizeof(value);
   TEST_ASSERT_EQUAL(
         SDevicePropertyStatusValidationError,
         SDEVICE_GET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(handle, &get_parameters));

   /* Size + Offset overflows size_t itself (arithmetic overflow) */
   get_parameters.Size = (size_t)-1;
   get_parameters.Offset = 1;
   TEST_ASSERT_EQUAL(
         SDevicePropertyStatusValidationError,
         SDEVICE_GET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(handle, &get_parameters));
}

TEST_GROUP_RUNNER(SDeviceCore)
{
   RUN_TEST_CASE(SDeviceCore, Initialization);
   RUN_TEST_CASE(SDeviceCore, HandleAccessors);
   RUN_TEST_CASE(SDeviceCore, PropertyStatusValidation);
   RUN_TEST_CASE(SDeviceCore, SimpleProperty);
   RUN_TEST_CASE(SDeviceCore, PartialPropertyFullRoundTrip);
   RUN_TEST_CASE(SDeviceCore, PartialPropertyOffsetWrite);
   RUN_TEST_CASE(SDeviceCore, PartialPropertyValidationErrors);
}
