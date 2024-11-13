#pragma once

#include "log.h"
#include "config.h"
#include "dependencies.h"

/* 00000000-0000-0000-0000-000000000001 */
#define TEST_SDEVICE_UUID_HIGH 0x0000000000000000
#define TEST_SDEVICE_UUID_LOW  0x0000000000000001

#define TEST_SDEVICE_VERSION_MAJOR 0
#define TEST_SDEVICE_VERSION_MINOR 0
#define TEST_SDEVICE_VERSION_PATCH 1

SDEVICE_HANDLE_FORWARD_DECLARATION(Test);
SDEVICE_INIT_DATA_FORWARD_DECLARATION(Test);

typedef struct
{
   int FirstValue;
   int SecondValue;
} TestSDeviceDataType;

typedef enum
{
   TEST_SDEVICE_SOME_PANIC
} TestSDevicePanic;

SDEVICE_INIT_DATA_DECLARATION(Test)
{
   TestSDeviceDataType TestData;
};

SDEVICE_IDENTITY_BLOCK_DECLARATION(Test);

SDEVICE_CREATE_HANDLE_DECLARATION(Test, init, owner, identifier, context);
SDEVICE_DISPOSE_HANDLE_DECLARATION(Test, handlePointer);

SDEVICE_PROPERTY_TYPE_DECLARATION(Test, PropertyValue, TestSDeviceDataType);
SDEVICE_GET_SIMPLE_PROPERTY_DECLARATION(Test, PropertyValue, handle, value);
SDEVICE_SET_SIMPLE_PROPERTY_DECLARATION(Test, PropertyValue, handle, value);

SDEVICE_PROPERTY_TYPE_DECLARATION(Test, PartialPropertyValue, int);
SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(Test, PartialPropertyValue, handle, parameters);
SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(Test, PartialPropertyValue, handle, parameters);
