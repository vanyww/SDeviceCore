#pragma once

#include "config.h"
#include "dependencies.h"

#define TEST_SDEVICE_VERSION_MAJOR 1
#define TEST_SDEVICE_VERSION_MINOR 0
#define TEST_SDEVICE_VERSION_PATCH 0

typedef struct
{
   int First;
   int Second;
} TestSDeviceData;

SDEVICE_HANDLE_FORWARD_DECLARATION(Test);
SDEVICE_INIT_DATA_FORWARD_DECLARATION(Test);

SDEVICE_INIT_DATA_DECLARATION(Test)
{
   TestSDeviceData InitData;
};

SDEVICE_CREATE_HANDLE_DECLARATION(Test, init, context);
SDEVICE_DISPOSE_HANDLE_DECLARATION(Test, this);

SDEVICE_PROPERTY_TYPE_DECLARATION(Test, SimplePropertyValue, TestSDeviceData);
SDEVICE_GET_SIMPLE_PROPERTY_DECLARATION(Test, SimplePropertyValue, this, value);
SDEVICE_SET_SIMPLE_PROPERTY_DECLARATION(Test, SimplePropertyValue, this, value);

SDEVICE_PROPERTY_TYPE_DECLARATION(Test, PartialPropertyValue, struct { char Value[64]; });
SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(Test, PartialPropertyValue, this, parameters);
SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(Test, PartialPropertyValue, this, parameters);
