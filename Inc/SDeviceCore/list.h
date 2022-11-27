#pragma once

#include <stddef.h>

#define __SDEVICE_LIST(device_name, name) __##device_name##_SDevice_##name##_List
#define __SDEVICE_LIST_FORWARD_DECLARATION(device_name, name)                                                          \
   typedef struct __SDEVICE_LIST(device_name, name) __SDEVICE_LIST(device_name, name)
#define __SDEVICE_LIST_DECLARATION(device_name, name, type) struct __SDEVICE_LIST(device_name, name)                   \
{                                                                                                                      \
   type *Values;                                                                                                       \
   size_t Length;                                                                                                      \
}                                                                                                                      \
