#pragma once

#include "SDeviceCore/common.h"

#include <stdbool.h>

#define __PARTIAL_APPLICATION_MACRO_HELPER(...) __VA_ARGS__)

#define __SDEVICE_CONSTANT_DATA(name) __##name##_SDeviceConstantData
#define __SDEVICE_SETTINGS_DATA(name) __##name##_SDeviceSettingsData
#define __SDEVICE_DYNAMIC_DATA(name) __##name##_SDeviceDynamicData

#define __SDEVICE_HANDLE(name) name##_SDeviceHandle
#define __SDEVICE_HANDLE_FORWARD_DECLARATION(name) typedef struct __SDEVICE_HANDLE(name) __SDEVICE_HANDLE(name)
#define __SDEVICE_HANDLE_DEFINITION(name) struct __SDEVICE_HANDLE(name)                                                \
{                                                                                                                      \
   const __SDEVICE_CONSTANT_DATA(name) *Constant;                                                                      \
   __SDEVICE_SETTINGS_DATA(name) *Settings;                                                                            \
   __SDEVICE_DYNAMIC_DATA(name) Dynamic;                                                                               \
}

#define __SDEVICE_INITIALIZE(name) SDeviceInitializeHandleCommon(                                                      \
         (bool (*)(void *))__SDEVICE_INITIALIZE_DYNAMIC_DATA(name),                                                    \
         __PARTIAL_APPLICATION_MACRO_HELPER

#define __SDEVICE_SET_SETTING(name, setting_name) __##name##_SDeviceSettingSet_##setting_name
#define __SDEVICE_SET_SETTING_DECLARATION(name, setting_name, handle_name, value_name)                                 \
   SDeviceSettingSetStatus __SDEVICE_SET_SETTING(name, setting_name)(                                                  \
         __attribute__((unused)) void *handle_name,                                                                    \
         __attribute__((unused)) const void *value_name)

#define __SDEVICE_INITIALIZE_INTERNALS(name) __##name##_SDeviceInitializeInternals
#define __SDEVICE_INITIALIZE_INTERNALS_DECLARATION(name, handle_name)                                                  \
   bool __SDEVICE_INITIALIZE_INTERNALS(name)(__attribute__((unused)) __SDEVICE_HANDLE(name) *handle_name)

typedef enum
{
    SDEVICE_SETTING_SET_STATUS_OK,
    SDEVICE_SETTING_SET_STATUS_VALIDATION_ERROR,
    SDEVICE_SETTING_SET_STATUS_SET_ERROR,
} SDeviceSettingSetStatus;

typedef struct
{
   const void *Constant;
   void *Settings;
   char Dynamic[];
} SDeviceCommonHandle;

void SDeviceInitializeHandleCommon(bool (*)(void *), const void *, void *, void *);
