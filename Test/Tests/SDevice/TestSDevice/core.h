#pragma once

#include "SDeviceCore/core.h"

__SDEVICE_HANDLE_FORWARD_DECLARATION(TestSDevice);
__SDEVICE_INIT_DATA_FORWARD_DECLARATION(TestSDevice);

typedef enum
{
   TEST_SDEVICE_STATUS_OK                                = 0x00,
   TEST_SDEVICE_STATUS_TEST_PARTIAL_PROPERTY_INVALID_SET = 0x01,
   TEST_SDEVICE_STATUS_TEST_PARTIAL_PROPERTY_INVALID_GET = 0x02
} TestSDeviceStatus;

struct __SDEVICE_INIT_DATA(TestSDevice)
{
   int TestPropertyInitialValue;
   int TestPartialPropertyInitialValue;
};

__SDEVICE_CREATE_HANDLE_DECLARATION(TestSDevice,,,);
__SDEVICE_DISPOSE_HANDLE_DECLARATION(TestSDevice,);

__SDEVICE_PROPERTY_TYPE_DECLARATION(TestSDevice, TestProperty, int);
__SDEVICE_SET_PROPERTY_DECLARATION(TestSDevice, TestProperty,,);
__SDEVICE_GET_PROPERTY_DECLARATION(TestSDevice, TestProperty,,);

__SDEVICE_PROPERTY_TYPE_DECLARATION(TestSDevice, TestPartialProperty, int);
__SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(TestSDevice, TestPartialProperty,,);
__SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(TestSDevice, TestPartialProperty,,);
