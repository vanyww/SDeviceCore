#pragma once

#include "common.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct
{
   bool IsInitialized;
#ifdef __SDEVICE_RUNTIME_ERROR
   uint16_t InstanceId;
#endif
   void *Context;
   const uint8_t Data[];
} SDeviceCommonHandle;

#define __SDEVICE_INIT_DATA(name) __##name##_SDeviceInitData
#define __SDEVICE_RUNTIME_DATA(name) __##name##_SDeviceRuntimeData

#define __SDEVICE_HANDLE(name) name##_SDeviceHandle
#define __SDEVICE_HANDLE_FORWARD_DECLARATION(name) typedef struct __SDEVICE_HANDLE(name) __SDEVICE_HANDLE(name)

#ifdef __SDEVICE_RUNTIME_ERROR
#define __SDEVICE_HANDLE_DEFINITION(name) struct __SDEVICE_HANDLE(name)                                                \
{                                                                                                                      \
   bool IsInitialized;                                                                                                 \
   uint16_t InstanceId;                                                                                                \
   void *Context;                                                                                                      \
   const __SDEVICE_INIT_DATA(name) Init;                                                                               \
   __SDEVICE_RUNTIME_DATA(name) Runtime;                                                                               \
}
#else
#define __SDEVICE_HANDLE_DEFINITION(name) struct __SDEVICE_HANDLE(name)                                                \
{                                                                                                                      \
   bool IsInitialized;                                                                                                 \
   void *Context;                                                                                                      \
   const __SDEVICE_INIT_DATA(name) Init;                                                                               \
   __SDEVICE_RUNTIME_DATA(name) Runtime;                                                                               \
}
#endif

#define __SDEVICE_SET_SETTING_NAME(name, setting_name) __##name##_SDeviceSettingSet_##setting_name
#define __SDEVICE_SET_SETTING(name, setting_name) __SDEVICE_SET_SETTING_NAME(name, setting_name)
#define __SDEVICE_SET_SETTING_RETURN_VALUE SDeviceOperationStatus
#define __SDEVICE_SET_SETTING_PARAMETERS(handle_name, value_name) (void *handle_name, const void *value_name)
#define __SDEVICE_SET_SETTING_POINTER(name)                                                                            \
   __SDEVICE_SET_SETTING_RETURN_VALUE (* name) __SDEVICE_SET_SETTING_PARAMETERS(,)
#define __SDEVICE_SET_SETTING_DECLARATION(name, setting_name, handle_name, value_name)                                 \
        __SDEVICE_SET_SETTING_RETURN_VALUE                                                                             \
        __SDEVICE_SET_SETTING_NAME(name, setting_name)                                                                 \
        __SDEVICE_SET_SETTING_PARAMETERS(handle_name, value_name)

typedef struct
{
   void *Data;
   size_t Size;
   size_t Offset;
} SDeviceTryGetParameterParameters;

#define __SDEVICE_TRY_GET_PARAMETER_NAME(name, parameter_name) __##name##_SDeviceTryGetParameter_##parameter_name
#define __SDEVICE_TRY_GET_PARAMETER(name, parameter_name) __SDEVICE_TRY_GET_PARAMETER_NAME(name, parameter_name)
#define __SDEVICE_TRY_GET_PARAMETER_RETURN_VALUE SDeviceOperationStatus
#define __SDEVICE_TRY_GET_PARAMETER_PARAMETERS(handle_name, parameters_name)                                           \
   (void *handle_name, SDeviceTryGetParameterParameters *parameters_name)
#define __SDEVICE_TRY_GET_PARAMETER_POINTER(name)                                                                      \
   __SDEVICE_TRY_GET_PARAMETER_RETURN_VALUE (* name) __SDEVICE_TRY_GET_PARAMETER_PARAMETERS(,)
#define __SDEVICE_TRY_GET_PARAMETER_DECLARATION(name, parameter_name, handle_name, parameters_name)                    \
        __SDEVICE_TRY_GET_PARAMETER_RETURN_VALUE                                                                       \
        __SDEVICE_TRY_GET_PARAMETER_NAME(name, parameter_name)                                                         \
        __SDEVICE_TRY_GET_PARAMETER_PARAMETERS(handle_name, parameters_name)

#define __SDEVICE_INITIALIZE_HANDLE_NAME(name) __##name##_SDeviceInitializeHandle
#define __SDEVICE_INITIALIZE_HANDLE(name) __SDEVICE_INITIALIZE_HANDLE_NAME(name)
#define __SDEVICE_INITIALIZE_HANDLE_DECLARATION(name, handle_name)                                                     \
   void __SDEVICE_INITIALIZE_HANDLE_NAME(name)(__SDEVICE_HANDLE(name) *handle_name)
