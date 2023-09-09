#pragma once

#include "log.h"
#include "config.h"
#include "dependencies.h"

/* 00000000-0000-0000-0000-000000000001 */
#define TEST_DEVICE_SDEVICE_UUID_HIGH 0x0000000000000000
#define TEST_DEVICE_SDEVICE_UUID_LOW  0x0000000000000001

#define TEST_DEVICE_SDEVICE_VERSION_MAJOR 0
#define TEST_DEVICE_SDEVICE_VERSION_MINOR 0
#define TEST_DEVICE_SDEVICE_VERSION_PATCH 1

SDEVICE_HANDLE_FORWARD_DECLARATION(TestDevice);
SDEVICE_INIT_DATA_FORWARD_DECLARATION(TestDevice);

typedef struct
{
   int FirstValue;
   int SecondValue;
} TestDeviceSdeviceDataType;

typedef enum
{
   TEST_DEVICE_SDEVICE_SOME_PANIC
} TestDeviceSdevicePanic;

SDEVICE_INIT_DATA_DECLARATION(TestDevice)
{
   TestDeviceSdeviceDataType testDeviceData;
};

SDEVICE_CREATE_HANDLE_DECLARATION(TestDevice, _init, _owner, _id, _context);
SDEVICE_DISPOSE_HANDLE_DECLARATION(TestDevice, _handlePtr);

SDEVICE_PROPERTY_TYPE_DECLARATION(TestDevice, PropertyValue, TestDeviceSdeviceDataType);
SDEVICE_GET_PROPERTY_DECLARATION(TestDevice, PropertyValue, _handle, _value);
SDEVICE_SET_PROPERTY_DECLARATION(TestDevice, PropertyValue, _handle, _value);

SDEVICE_PROPERTY_TYPE_DECLARATION(TestDevice, partialPropertyValue, int);
SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(TestDevice, partialPropertyValue, _handle, _parameters);
SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(TestDevice, partialPropertyValue, _handle, _parameters);

SDEVICE_IDENTITY_BLOCK_DECLARATION(TestDevice);
