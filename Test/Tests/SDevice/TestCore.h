#pragma once
#include "SDeviceCore/core.h"

SDEVICE_HANDLE_FORWARD_DECLARATION(TestDevice);
SDEVICE_INIT_DATA_FORWARD_DECLARATION(TestDevice);


typedef struct
{
   int FirstValue;
   int SecondValue;
} TestDeviceDataType;

SDEVICE_INIT_DATA_DECLARATION(TestDevice)
{
   TestDeviceDataType testDeviceData;
};

typedef enum
{
   TEST_DEVICE_STATUS_OK = 0x00,
   TEST_DEVICE_STATUS_TEST_PARTIAL_PROPERTY_INVALID_SET = 0x01,
   TEST_DEVICE_STATUS_TEST_PARTIAL_PROPERTY_INVALID_GET = 0x02
} TestSDeviceStatus;

SDEVICE_CREATE_HANDLE_DECLARATION(TestDevice, _init, _owner, _id, _context);
SDEVICE_DISPOSE_HANDLE_DECLARATION(TestDevice, _handlePtr);

SDEVICE_PROPERTY_TYPE_DECLARATION(TestDevice, PropertyValue, TestDeviceDataType);
SDEVICE_GET_PROPERTY_DECLARATION(TestDevice, PropertyValue, _handle, _value);
SDEVICE_SET_PROPERTY_DECLARATION(TestDevice, PropertyValue, _handle, _value);

SDEVICE_PROPERTY_TYPE_DECLARATION(TestDevice, partialPropertyValue, int);
SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(TestDevice, partialPropertyValue, _handle, _parameters);
SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(TestDevice, partialPropertyValue, _handle, _parameters);

SDEVICE_STRING_NAME_DECLARATION(TestDevice);
