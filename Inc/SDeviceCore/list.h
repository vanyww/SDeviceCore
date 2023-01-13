#pragma once

#include <stddef.h>

#define SDEVICE_LIST(device_name, name) $##device_name##SDevice##name##List
#define SDEVICE_LIST_FORWARD_DECLARATION(device_name, name)                                                            \
   typedef struct SDEVICE_LIST(device_name, name) SDEVICE_LIST(device_name, name)
#define SDEVICE_LIST_DECLARATION(device_name, name, type) struct SDEVICE_LIST(device_name, name)                       \
{                                                                                                                      \
   type *Values;                                                                                                       \
   size_t Length;                                                                                                      \
}
