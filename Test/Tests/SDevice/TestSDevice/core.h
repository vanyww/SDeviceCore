#pragma once

#include "SDeviceCore/core.h"

SDEVICE_HANDLE_FORWARD_DECLARATION(TestSDevice);
SDEVICE_INIT_DATA_FORWARD_DECLARATION(TestSDevice);

typedef enum
{
   TEST_SDEVICE_STATUS_OK                                = 0x00,
   TEST_SDEVICE_STATUS_TEST_PARTIAL_PROPERTY_INVALID_SET = 0x01,
   TEST_SDEVICE_STATUS_TEST_PARTIAL_PROPERTY_INVALID_GET = 0x02
} TestSDeviceStatus;

struct SDEVICE_INIT_DATA(TestSDevice)
{
   int TestPropertyInitialValue;
   int TestPartialPropertyInitialValue;
};

SDEVICE_CREATE_HANDLE_DECLARATION(TestSDevice,,);
SDEVICE_DISPOSE_HANDLE_DECLARATION(TestSDevice,);

SDEVICE_PROPERTY_TYPE_DECLARATION(TestSDevice, TestProperty, int);
SDEVICE_SET_PROPERTY_DECLARATION(TestSDevice, TestProperty,,);
SDEVICE_GET_PROPERTY_DECLARATION(TestSDevice, TestProperty,,);

SDEVICE_PROPERTY_TYPE_DECLARATION(TestSDevice, TestPartialProperty, int);
SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(TestSDevice, TestPartialProperty,,);
SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(TestSDevice, TestPartialProperty,,);
