#pragma once

#include "../Inc/public.h"

#include "SDeviceCore/errors.h"
#include "SDeviceCore/heap.h"

SDEVICE_RUNTIME_DATA_FORWARD_DECLARATION(TestDevice);
SDEVICE_RUNTIME_DATA_DECLARATION(TestDevice)
{
   SDEVICE_PROPERTY_TYPE(TestDevice, PropertyValue) testDeviceData;
};

SDEVICE_HANDLE_DECLARATION(TestDevice);
SDEVICE_INTERNAL_ALIASES_DECLARATION(TestDevice);
