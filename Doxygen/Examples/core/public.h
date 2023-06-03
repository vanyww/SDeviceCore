#pragma once

#include "SDeviceCore/core.h"

#define EXAMPLE_SDEVICE_VERSION_MAJOR 1
#define EXAMPLE_SDEVICE_VERSION_MINOR 0
#define EXAMPLE_SDEVICE_VERSION_PATCH 0
#define EXAMPLE_SDEVICE_CORE_VERSION ((SDeviceVersion) \
{                                                      \
   .Major = EXAMPLE_SDEVICE_VERSION_MAJOR,             \
   .Minor = EXAMPLE_SDEVICE_VERSION_MINOR,             \
   .Patch = EXAMPLE_SDEVICE_VERSION_PATCH              \
})

SDEVICE_HANDLE_FORWARD_DECLARATION(Example);
SDEVICE_INIT_DATA_FORWARD_DECLARATION(Example);

typedef enum
{
   EXAMPLE_SDEVICE_EXCEPTION_SOME_EXCEPTION_0,
   EXAMPLE_SDEVICE_EXCEPTION_SOME_EXCEPTION_1,
   /* any other exceptions to throw */
} ExampleSDeviceException;

typedef enum
{
   EXAMPLE_SDEVICE_STATUS_OK,
   EXAMPLE_SDEVICE_STATUS_ERROR_1,
   EXAMPLE_SDEVICE_STATUS_ERROR_2,
   EXAMPLE_SDEVICE_STATUS_ERROR_3
   /* any other status entries to log */
} ExampleSDeviceStatus;

SDEVICE_INIT_DATA_DECLARATION(Example)
{
   /* any init data: callbacks, constants, etc. */
};

SDEVICE_STRING_NAME_DECLARATION(Example);

SDEVICE_CREATE_HANDLE_DECLARATION(Example, init, owner, identifier, context);
SDEVICE_DISPOSE_HANDLE_DECLARATION(Example, handlePointer);

SDEVICE_PROPERTY_TYPE_DECLARATION(Example, IntValue, int);
SDEVICE_GET_PROPERTY_DECLARATION(Example, IntValue, handle, value);
SDEVICE_SET_PROPERTY_DECLARATION(Example, IntValue, handle, value);

SDEVICE_PROPERTY_TYPE_DECLARATION(Example, FixedLengthString, struct { char Value[64]; });
SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(Example, FixedLengthString, handle, value);
SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(Example, FixedLengthString, handle, value);

void CommonExampleSDeviceFunction(SDEVICE_HANDLE(Example) *handle);
