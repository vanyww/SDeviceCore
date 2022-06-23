#pragma once

#include "common.h"

#include <stddef.h>
#include <stdbool.h>

typedef struct
{
   const bool IsInitialized;
#ifdef __SDEVICE_RUNTIME_ERROR
   const uint16_t InstanceIndex;
#endif
   void *Context;
   void *Runtime;
   const char Init[];
} SDeviceCommonHandle;

typedef enum
{
    SDEVICE_OPERATION_STATUS_OK,
    SDEVICE_OPERATION_STATUS_VALIDATION_ERROR,
    SDEVICE_OPERATION_STATUS_PROCESSING_ERROR
} SDeviceOperationStatus;

typedef struct
{
   union
   {
      const void *Set;
      void *Get;
   } Data;
   size_t Offset;
   size_t Size;
} SDevicePartialParameterArguments;

/**********************************************************************************************************************/

#define __SDEVICE_INIT_ARGUMENTS(name) __##name##_SDeviceInitArguments
#define __SDEVICE_INIT_DATA(name) __##name##_SDeviceInitData

#define __SDEVICE_RUNTIME_DATA(name) __##name##_SDeviceRuntimeData
#define __SDEVICE_RUNTIME_DATA_FORWARD_DECLARATION(name)                                                               \
   typedef struct __SDEVICE_RUNTIME_DATA(name) __SDEVICE_RUNTIME_DATA(name)

#define __SDEVICE_HANDLE(name) name##_SDeviceHandle
#define __SDEVICE_HANDLE_FORWARD_DECLARATION(name)                                                                     \
   typedef struct __SDEVICE_HANDLE(name) __SDEVICE_HANDLE(name)

#ifdef __SDEVICE_RUNTIME_ERROR
#define __SDEVICE_HANDLE_DEFINITION(name) struct __SDEVICE_HANDLE(name)                                                \
{                                                                                                                      \
   const bool IsInitialized;                                                                                           \
   const uint16_t InstanceIndex;                                                                                       \
   void *Context;                                                                                                      \
   __SDEVICE_RUNTIME_DATA(name) *Runtime;                                                                              \
   const __SDEVICE_INIT_DATA(name) Init;                                                                               \
}
#else
#define __SDEVICE_HANDLE_DEFINITION(name) struct __SDEVICE_HANDLE(name)                                                \
{                                                                                                                      \
   const bool IsInitialized;                                                                                           \
   void *Context;                                                                                                      \
   __SDEVICE_RUNTIME_DATA(name) *Runtime;                                                                              \
   const __SDEVICE_INIT_DATA(name) Init;                                                                               \
}
#endif

/**********************************************************************************************************************/

#define __SDEVICE_SET_PARAMETER_RETURN_VALUE SDeviceOperationStatus
#define __SDEVICE_SET_PARAMETER_ARGUMENTS(handle_name, value_name) (void *handle_name, const void *value_name)
#define __SDEVICE_SET_PARAMETER_POINTER(name)                                                                          \
   __SDEVICE_SET_PARAMETER_RETURN_VALUE (* name) __SDEVICE_SET_PARAMETER_ARGUMENTS(,)

#define __SDEVICE_SET_PARAMETER_NAME(name, parameter_name) __##name##_SDeviceSetParameter_##parameter_name
#define __SDEVICE_SET_PARAMETER(name, parameter_name) __SDEVICE_SET_PARAMETER_NAME(name, parameter_name)
#define __SDEVICE_SET_PARAMETER_DECLARATION(name, parameter_name, handle_name, value_name)                             \
   __SDEVICE_SET_PARAMETER_RETURN_VALUE                                                                                \
   __SDEVICE_SET_PARAMETER_NAME(name, parameter_name)                                                                  \
   __SDEVICE_SET_PARAMETER_ARGUMENTS(handle_name, value_name)

#define __SDEVICE_PARTIAL_SET_PARAMETER_NAME(name, parameter_name)                                                     \
   __##name##_SDevicePartialSetParameter_##parameter_name
#define __SDEVICE_PARTIAL_SET_PARAMETER(name, parameter_name) __SDEVICE_PARTIAL_SET_PARAMETER_NAME(name, parameter_name)
#define __SDEVICE_PARTIAL_SET_PARAMETER_DECLARATION(name, parameter_name, handle_name, value_name)                     \
   __SDEVICE_SET_PARAMETER_RETURN_VALUE                                                                                \
   __SDEVICE_PARTIAL_SET_PARAMETER_NAME(name, parameter_name)                                                          \
   __SDEVICE_SET_PARAMETER_ARGUMENTS(handle_name, value_name)

/**********************************************************************************************************************/

#define __SDEVICE_GET_PARAMETER_RETURN_VALUE SDeviceOperationStatus
#define __SDEVICE_GET_PARAMETER_ARGUMENTS(handle_name, value_name) (void *handle_name, void *value_name)
#define __SDEVICE_GET_PARAMETER_POINTER(name)                                                                          \
   __SDEVICE_GET_PARAMETER_RETURN_VALUE (* name) __SDEVICE_GET_PARAMETER_ARGUMENTS(,)

#define __SDEVICE_GET_PARAMETER_NAME(name, parameter_name) __##name##_SDeviceGetParameter_##parameter_name
#define __SDEVICE_GET_PARAMETER(name, parameter_name) __SDEVICE_GET_PARAMETER_NAME(name, parameter_name)
#define __SDEVICE_GET_PARAMETER_DECLARATION(name, parameter_name, handle_name, value_name)                             \
   __SDEVICE_GET_PARAMETER_RETURN_VALUE                                                                                \
   __SDEVICE_GET_PARAMETER_NAME(name, parameter_name)                                                                  \
   __SDEVICE_GET_PARAMETER_ARGUMENTS(handle_name, value_name)

#define __SDEVICE_PARTIAL_GET_PARAMETER_NAME(name, parameter_name)                                                     \
   __##name##_SDevicePartialGetParameter_##parameter_name
#define __SDEVICE_PARTIAL_GET_PARAMETER(name, parameter_name) __SDEVICE_PARTIAL_GET_PARAMETER_NAME(name, parameter_name)
#define __SDEVICE_PARTIAL_GET_PARAMETER_DECLARATION(name, parameter_name, handle_name, value_name)                     \
   __SDEVICE_GET_PARAMETER_RETURN_VALUE                                                                                \
   __SDEVICE_PARTIAL_GET_PARAMETER_NAME(name, parameter_name)                                                          \
   __SDEVICE_GET_PARAMETER_ARGUMENTS(handle_name, value_name)

/**********************************************************************************************************************/

#define __SDEVICE_CREATE_HANDLE_NAME(name) __##name##_SDeviceCreateHandle
#define __SDEVICE_CREATE_HANDLE(name) __SDEVICE_CREATE_HANDLE_NAME(name)
#define __SDEVICE_CREATE_HANDLE_DECLARATION(name, arguments_name, instance_index_name, context_name)                   \
   __SDEVICE_HANDLE(name) __SDEVICE_CREATE_HANDLE_NAME(name)(const __SDEVICE_INIT_ARGUMENTS(name) *arguments_name,     \
                                                             uint16_t instance_index_name,                             \
                                                             void *context_name)

/**********************************************************************************************************************/

/**********************************************************************************************************************/

#define __SDEVICE_DISPOSE_HANDLE_NAME(name) __##name##_SDeviceDisposeHandle
#define __SDEVICE_DISPOSE_HANDLE(name) __SDEVICE_DISPOSE_HANDLE_NAME(name)
#define __SDEVICE_DISPOSE_HANDLE_DECLARATION(name, handle_name)                                                        \
   void __SDEVICE_DISPOSE_HANDLE_NAME(name)(__SDEVICE_HANDLE(name) *handle_name)

/**********************************************************************************************************************/
