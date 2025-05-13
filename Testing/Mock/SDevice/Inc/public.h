#pragma once

#include "config.h"
#include "dependencies.h"

#define TEST_SDEVICE_VERSION_MAJOR 1
#define TEST_SDEVICE_VERSION_MINOR 0
#define TEST_SDEVICE_VERSION_PATCH 0

SDEVICE_HANDLE_FORWARD_DECLARATION(Test);
SDEVICE_INIT_DATA_FORWARD_DECLARATION(Test);

typedef struct
{
   int First;
   int Second;
} TestSDeviceDataType;

SDEVICE_INIT_DATA_DECLARATION(Test)
{
   TestSDeviceDataType InitData;
};

SDEVICE_CREATE_HANDLE_DECLARATION(Test, init, context);
SDEVICE_DISPOSE_HANDLE_DECLARATION(Test, handle);

SDEVICE_PROPERTY_TYPE_DECLARATION(Test, SimplePropertyValue, TestSDeviceDataType);
SDEVICE_GET_SIMPLE_PROPERTY_DECLARATION(Test, SimplePropertyValue, handle, value);
SDEVICE_SET_SIMPLE_PROPERTY_DECLARATION(Test, SimplePropertyValue, handle, value);

SDEVICE_PROPERTY_TYPE_DECLARATION(Test, PartialPropertyValue, struct { char Value[64]; });
SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(Test, PartialPropertyValue, handle, parameters);
SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(Test, PartialPropertyValue, handle, parameters);
