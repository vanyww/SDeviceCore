#include "TestCore.h"
#include "unity_fixture.h"
#include "SDeviceCore/core.h"
#include "../Weak/weak.h"

#define _cleanup __attribute__((cleanup(SDEVICE_DISPOSE_HANDLE(TestDevice))))

TEST_GROUP(SDeviceCore);

TEST_SETUP(SDeviceCore){ }
TEST_TEAR_DOWN(SDeviceCore)
{
   AssertFailedCalled = false;
}

TEST(SDeviceCore,HandleInitialization)
{
   void *context = (void*)"hello_from_test";
   void *owner = (void*)0x123;
   SDeviceHandleIdentifier id = 0;
   TestDeviceDataType writeValue = { .FirstValue = 1, .SecondValue = 2 };
   TestDeviceDataType readValue;

   SDEVICE_INIT_DATA(TestDevice) init = { .testDeviceData = writeValue };

   _cleanup SDEVICE_HANDLE(TestDevice) *handle = SDEVICE_CREATE_HANDLE(TestDevice)(&init, owner, id, context);

   TEST_ASSERT(AssertFailedCalled != true);
   TEST_ASSERT(handle != NULL);
   TEST_ASSERT(context == SDeviceGetHandleContext(handle));
   TEST_ASSERT(owner == SDeviceGetHandleOwnerHandle(handle));
   TEST_ASSERT(id == SDeviceGetHandleIdentifier(handle));
   TEST_ASSERT(TEST_DEVICE_STATUS_OK == SDeviceGetHandleLatestStatus(handle));
   TEST_ASSERT(SDEVICE_STRING_NAME(TestDevice) == SDeviceGetHandleSDeviceStringName(handle));
   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK, SDEVICE_GET_PROPERTY(TestDevice, PropertyValue)(handle, &readValue));
   TEST_ASSERT(readValue.FirstValue == writeValue.FirstValue && readValue.SecondValue == writeValue.SecondValue);
}

TEST(SDeviceCore, HandleProperty)
{
   void *context = NULL;
   void *owner = NULL;
   SDeviceHandleIdentifier id = 0;

   SDEVICE_INIT_DATA(TestDevice) init = { .testDeviceData ={ .FirstValue = 0, .SecondValue = 0 } };

   _cleanup SDEVICE_HANDLE(TestDevice) *handle = SDEVICE_CREATE_HANDLE(TestDevice)(&init, owner, id, context);

   SDEVICE_PROPERTY_TYPE(TestDevice, PropertyValue) writeValue ={ .FirstValue = 10, .SecondValue = 20 };
   SDEVICE_PROPERTY_TYPE(TestDevice, PropertyValue) readValue;

   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK, SDEVICE_SET_PROPERTY(TestDevice,PropertyValue)(handle, &writeValue));
   TEST_ASSERT(AssertFailedCalled != true);
   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK, SDEVICE_GET_PROPERTY(TestDevice, PropertyValue)(handle, &readValue));
   TEST_ASSERT(AssertFailedCalled != true);
   TEST_ASSERT(readValue.FirstValue == writeValue.FirstValue && readValue.SecondValue == writeValue.SecondValue);
}

TEST(SDeviceCore, HandlePartialProperty)
{
   void *context = NULL;
   void *owner = NULL;
   SDeviceHandleIdentifier id = 0;

   SDEVICE_INIT_DATA(TestDevice) init = { .testDeviceData = { .FirstValue = 0, .SecondValue = 0 } };

   _cleanup SDEVICE_HANDLE(TestDevice) *handle = SDEVICE_CREATE_HANDLE(TestDevice)(&init, owner, id, context);

   SDEVICE_PROPERTY_TYPE(TestDevice, partialPropertyValue) writeValue = 100;
   SDeviceSetPartialPropertyParameters writeParam = { .Data = &writeValue, .Offset = 0, .Size = sizeof(writeValue)};
   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK, SDEVICE_SET_PARTIAL_PROPERTY(TestDevice, partialPropertyValue)(handle, &writeParam));
   TEST_ASSERT(AssertFailedCalled != true);

   SDEVICE_PROPERTY_TYPE(TestDevice, partialPropertyValue) readValue;
   SDeviceGetPartialPropertyParameters readParam = { .Data = &readValue, .Offset = 0, .Size = sizeof(readValue)};
   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK, SDEVICE_GET_PARTIAL_PROPERTY(TestDevice, partialPropertyValue)(handle, &readParam));
   TEST_ASSERT(AssertFailedCalled != true);

   TEST_ASSERT(readValue == writeValue);

   writeValue = 400;
   writeParam.Data = &writeValue;
   writeParam.Offset = sizeof(writeValue);
   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK, SDEVICE_SET_PARTIAL_PROPERTY(TestDevice, partialPropertyValue)(handle, &writeParam));
   TEST_ASSERT(AssertFailedCalled != true);
   
   readParam.Offset = sizeof(readValue);
   TEST_ASSERT_EQUAL(SDEVICE_PROPERTY_STATUS_OK, SDEVICE_GET_PARTIAL_PROPERTY(TestDevice, partialPropertyValue)(handle, &readParam));
   TEST_ASSERT(AssertFailedCalled != true);
   
   TEST_ASSERT(readValue == writeValue);
}

TEST_GROUP_RUNNER(SDeviceCore)
{
   RUN_TEST_CASE(SDeviceCore, HandleInitialization);
   RUN_TEST_CASE(SDeviceCore, HandleProperty);
   RUN_TEST_CASE(SDeviceCore, HandlePartialProperty);
}