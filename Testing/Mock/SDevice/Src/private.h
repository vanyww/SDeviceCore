#pragma once

#include "../Inc/public.h"

#include "SDeviceCore/errors.h"

SDEVICE_RUNTIME_DATA_FORWARD_DECLARATION(Test);
SDEVICE_RUNTIME_DATA_DECLARATION(Test)
{
   SDEVICE_PROPERTY_TYPE(Test, SimplePropertyValue) SimplePropertyValue;
   SDEVICE_PROPERTY_TYPE(Test, PartialPropertyValue) PartialPropertyValue;
};

SDEVICE_HANDLE_DECLARATION(Test);
SDEVICE_INTERNAL_ALIASES_DECLARATION(Test);
