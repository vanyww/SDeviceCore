#pragma once

#include "SDeviceCore/core.h"
#include "SDeviceCore/config.h"

#if (SDEVICE_CORE_VERSION_MAJOR != 9) || (SDEVICE_CORE_VERSION_MINOR < 0)
   #error SDevice core version is incorrect.
#endif

#if defined(EXAMPLE_SDEVICE_USE_EXTERNAL_CONFIG)
   #include "example_sdevice_config.h"
#endif

#define EXAMPLE_SDEVICE_VERSION_MAJOR 0
#define EXAMPLE_SDEVICE_VERSION_MINOR 0
#define EXAMPLE_SDEVICE_VERSION_PATCH 0

SDEVICE_HANDLE_FORWARD_DECLARATION(Example);
SDEVICE_INIT_DATA_FORWARD_DECLARATION(Example);

typedef enum
{
   EXAMPLE_SDEVICE_PANIC_SOME_PANIC_0,
   EXAMPLE_SDEVICE_PANIC_SOME_PANIC_1,
   /* any other panics to throw */
} ExampleSDevicePanic;

SDEVICE_INIT_DATA_DECLARATION(Example)
{
   /* any init data: callbacks, constants, etc. */
};

SDEVICE_IDENTITY_BLOCK_DECLARATION(Example);

SDEVICE_CREATE_HANDLE_DECLARATION(Example, init, context);
SDEVICE_DISPOSE_HANDLE_DECLARATION(Example, handlePointer);

SDEVICE_PROPERTY_TYPE_DECLARATION(Example, IntValue, int);
SDEVICE_GET_SIMPLE_PROPERTY_DECLARATION(Example, IntValue, handle, value);
SDEVICE_SET_SIMPLE_PROPERTY_DECLARATION(Example, IntValue, handle, value);

SDEVICE_PROPERTY_TYPE_DECLARATION(Example, StringValue, struct { char Value[64]; });
SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(Example, StringValue, handle, value);
SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(Example, StringValue, handle, value);

void CommonExampleSDeviceFunction(SDEVICE_HANDLE(Example) *handle);
