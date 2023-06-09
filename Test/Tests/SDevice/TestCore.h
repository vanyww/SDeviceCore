#pragma once
#include "SDeviceCore/core.h"

SDEVICE_HANDLE_FORWARD_DECLARATION(TestDevice);
SDEVICE_INIT_DATA_FORWARD_DECLARATION(TestDevice);

typedef int TestDevicePartialDataType;

typedef struct
{
   TestDevicePartialDataType firstValue;
   TestDevicePartialDataType secondValue;
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

SDEVICE_CREATE_HANDLE_DECLARATION(TestDevice,,,,);
SDEVICE_DISPOSE_HANDLE_DECLARATION(TestDevice,);

SDEVICE_PROPERTY_TYPE_DECLARATION(TestDevice, PropertyValue, TestDeviceDataType);
SDEVICE_GET_PROPERTY_DECLARATION(TestDevice, PropertyValue,,);
SDEVICE_SET_PROPERTY_DECLARATION(TestDevice, PropertyValue,,);

SDEVICE_PROPERTY_TYPE_DECLARATION(TestDevice, partialPropertyValue, TestDevicePartialDataType);
SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(TestDevice, partialPropertyValue,,);
SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(TestDevice, partialPropertyValue,,);

SDEVICE_STRING_NAME_DECLARATION(TestDevice);
