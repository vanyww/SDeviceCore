#include "../../Mock/SDevice/Inc/public.h"
#include "../../Mock/Errors/errors.h"

#include "unity_fixture.h"

#define _cleanup __attribute__((cleanup(SDEVICE_DISPOSE_HANDLE(Test))))

TEST_GROUP(SDeviceCore);

TEST_SETUP(SDeviceCore) { }
TEST_TEAR_DOWN(SDeviceCore)
{
   WasAssertFailedCalled = false;
}

TEST(SDeviceCore, HandleInitialization)
{
   void *owner = (void*)0x123;
   void *context = (void*)"hello_from_test";
   SDeviceHandleIdentifier identifier = 0;

   SDEVICE_PROPERTY_TYPE(Test, PropertyValue) writeValue = { .FirstValue = 1, .SecondValue = 2 };
   SDEVICE_PROPERTY_TYPE(Test, PropertyValue) readValue;

   SDEVICE_INIT_DATA(Test) init = { .TestData = writeValue };

   _cleanup SDEVICE_HANDLE(Test) *handle = SDEVICE_CREATE_HANDLE(Test)(&init, owner, identifier, context);

   TEST_ASSERT(!WasAssertFailedCalled);
   TEST_ASSERT(handle != NULL);
   TEST_ASSERT(context == SDeviceGetHandleContext(handle));
   TEST_ASSERT(owner == SDeviceGetHandleOwnerHandle(handle));
   TEST_ASSERT(identifier == SDeviceGetHandleIdentifier(handle));
   TEST_ASSERT(TEST_SDEVICE_STATUS_OK == SDeviceGetHandleLatestStatus(handle));
   TEST_ASSERT(SDeviceCompareIdentityBlocks(&SDEVICE_IDENTITY_BLOCK(Test), SDeviceGetHandleIdentityBlock(handle)));
   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK, SDEVICE_GET_PROPERTY(Test, PropertyValue)(handle, &readValue));
   TEST_ASSERT(readValue.FirstValue == writeValue.FirstValue && readValue.SecondValue == writeValue.SecondValue);
}

TEST(SDeviceCore, HandleProperty)
{
   void *owner = NULL;
   void *context = NULL;
   SDeviceHandleIdentifier identifier = 0;

   SDEVICE_INIT_DATA(Test) init = { .TestData = { .FirstValue = 0, .SecondValue = 0 } };

   _cleanup SDEVICE_HANDLE(Test) *handle = SDEVICE_CREATE_HANDLE(Test)(&init, owner, identifier, context);

   SDEVICE_PROPERTY_TYPE(Test, PropertyValue) writeValue = { .FirstValue = 10, .SecondValue = 20 };
   SDEVICE_PROPERTY_TYPE(Test, PropertyValue) readValue;

   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK, SDEVICE_SET_PROPERTY(Test, PropertyValue)(handle, &writeValue));
   TEST_ASSERT(!WasAssertFailedCalled);
   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK, SDEVICE_GET_PROPERTY(Test, PropertyValue)(handle, &readValue));
   TEST_ASSERT(!WasAssertFailedCalled);
   TEST_ASSERT(readValue.FirstValue == writeValue.FirstValue && readValue.SecondValue == writeValue.SecondValue);
}

TEST(SDeviceCore, HandlePartialProperty)
{
   void *context = NULL;
   void *owner = NULL;
   SDeviceHandleIdentifier id = 0;

   SDEVICE_INIT_DATA(Test) init = { .TestData = { .FirstValue = 0, .SecondValue = 0 } };

   _cleanup SDEVICE_HANDLE(Test) *handle = SDEVICE_CREATE_HANDLE(Test)(&init, owner, id, context);

   SDEVICE_PROPERTY_TYPE(Test, PartialPropertyValue) writeValue = 100;
   SDeviceSetPartialPropertyParameters writeParam = { .Data = &writeValue, .Offset = 0, .Size = sizeof(writeValue)};
   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK,
                     SDEVICE_SET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(handle, &writeParam));

   TEST_ASSERT(!WasAssertFailedCalled);

   SDEVICE_PROPERTY_TYPE(Test, PartialPropertyValue) readValue;
   SDeviceGetPartialPropertyParameters readParam = { .Data = &readValue, .Offset = 0, .Size = sizeof(readValue)};
   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK,
                     SDEVICE_GET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(handle, &readParam));

   TEST_ASSERT(!WasAssertFailedCalled);
   TEST_ASSERT(readValue == writeValue);

   writeValue = 400;
   writeParam.Data = &writeValue;
   writeParam.Offset = sizeof(writeValue);
   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK,
                     SDEVICE_SET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(handle, &writeParam));

   TEST_ASSERT(!WasAssertFailedCalled);
   
   readParam.Offset = sizeof(readValue);
   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK,
                     SDEVICE_GET_PARTIAL_PROPERTY(Test, PartialPropertyValue)(handle, &readParam));

   TEST_ASSERT(!WasAssertFailedCalled);
   TEST_ASSERT(readValue == writeValue);
}

TEST_GROUP_RUNNER(SDeviceCore)
{
   RUN_TEST_CASE(SDeviceCore, HandleInitialization);
   RUN_TEST_CASE(SDeviceCore, HandleProperty);
   RUN_TEST_CASE(SDeviceCore, HandlePartialProperty);
}
