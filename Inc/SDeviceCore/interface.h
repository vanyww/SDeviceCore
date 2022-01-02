#pragma once

#include "common.h"

#include <stdbool.h>

#define __SDEVICE_CONSTANT_DATA(name) __##name##_SDeviceConstantData
#define __SDEVICE_SETTINGS_DATA(name) __##name##_SDeviceSettingsData
#define __SDEVICE_DYNAMIC_DATA(name) __##name##_SDeviceDynamicData

#define __SDEVICE_HANDLE(name) name##_SDeviceHandle
#define __SDEVICE_HANDLE_FORWARD_DECLARATION(name) typedef struct __SDEVICE_HANDLE(name) __SDEVICE_HANDLE(name)

#ifdef __SDEVICE_RUNTIME_ERROR
#define __SDEVICE_HANDLE_DEFINITION(name) struct __SDEVICE_HANDLE(name)                                                \
{                                                                                                                      \
   bool IsInitialized;                                                                                                 \
   uint16_t InstanceId;                                                                                                \
   void *Context;                                                                                                      \
   const __SDEVICE_CONSTANT_DATA(name) *Constant;                                                                      \
   __SDEVICE_SETTINGS_DATA(name) Settings;                                                                             \
   __SDEVICE_DYNAMIC_DATA(name) Dynamic;                                                                               \
}
#else
#define __SDEVICE_HANDLE_DEFINITION(name) struct __SDEVICE_HANDLE(name)                                                \
{                                                                                                                      \
   bool IsInitialized;                                                                                                 \
   void *Context;                                                                                                      \
   const __SDEVICE_CONSTANT_DATA(name) *Constant;                                                                      \
   __SDEVICE_SETTINGS_DATA(name) Settings;                                                                             \
   __SDEVICE_DYNAMIC_DATA(name) Dynamic;                                                                               \
}
#endif

#define __SDEVICE_SET_SETTING_NAME(name, setting_name) __##name##_SDeviceSettingSet_##setting_name
#define __SDEVICE_SET_SETTING(name, setting_name) __SDEVICE_SET_SETTING_NAME(name, setting_name)
#define __SDEVICE_SET_SETTING_DECLARATION(name, setting_name, handle_name, value_name)                                 \
   SDeviceSettingSetStatus __SDEVICE_SET_SETTING_NAME(name, setting_name)(                                             \
         __attribute__((unused)) void *handle_name,                                                                    \
         __attribute__((unused)) const void *value_name)

#define __SDEVICE_INITIALIZE_HANDLE_NAME(name) __##name##_SDeviceInitializeHandle
#define __SDEVICE_INITIALIZE_HANDLE(name) __SDEVICE_INITIALIZE_HANDLE_NAME(name)
#define __SDEVICE_INITIALIZE_HANDLE_DECLARATION(name, handle_name)                                                     \
   void __SDEVICE_INITIALIZE_HANDLE_NAME(name)(__attribute__((unused)) __SDEVICE_HANDLE(name) *handle_name)

typedef enum
{
    SDEVICE_SETTING_SET_STATUS_OK,
    SDEVICE_SETTING_SET_STATUS_VALIDATION_ERROR,
    SDEVICE_SETTING_SET_STATUS_SET_ERROR,
} SDeviceSettingSetStatus;

typedef struct
{
   bool IsInitialized;

#ifdef __SDEVICE_RUNTIME_ERROR
   uint16_t InstanceId;
#endif

   void *Context;
   const void *Constant;
   uint8_t SettingsAndDynamic[];
} SDeviceCommonHandle;
