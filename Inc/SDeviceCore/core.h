#pragma once

#include <stddef.h>

#define SDEVICE_CORE_VERSION_MAJOR 10
#define SDEVICE_CORE_VERSION_MINOR 0
#define SDEVICE_CORE_VERSION_PATCH 0

#define SDEVICE_INIT_DATA(device_name) device_name##SDeviceInitData
#define SDEVICE_INIT_DATA_DECLARATION(device_name) struct SDEVICE_INIT_DATA(device_name)
#define SDEVICE_INIT_DATA_FORWARD_DECLARATION(device_name)                                                             \
   typedef SDEVICE_INIT_DATA_DECLARATION(device_name) SDEVICE_INIT_DATA(device_name)

#define SDEVICE_RUNTIME_DATA(device_name) device_name##SDeviceRuntimeData
#define SDEVICE_RUNTIME_DATA_DECLARATION(device_name) struct SDEVICE_RUNTIME_DATA(device_name)
#define SDEVICE_RUNTIME_DATA_FORWARD_DECLARATION(device_name)                                                          \
   typedef SDEVICE_RUNTIME_DATA_DECLARATION(device_name) SDEVICE_RUNTIME_DATA(device_name)

#define SDEVICE_CREATE_HANDLE(device_name) device_name##SDeviceCreateHandle
#define SDEVICE_CREATE_HANDLE_RETURN_VALUE void *
#define SDEVICE_CREATE_HANDLE_ARGUMENTS(init_data_name, context_name)                                                  \
   (const void *init_data_name, void *context_name)
#define SDEVICE_CREATE_HANDLE_POINTER(pointer_name)                                                                    \
   SDEVICE_CREATE_HANDLE_RETURN_VALUE (* pointer_name) SDEVICE_CREATE_HANDLE_ARGUMENTS(,)
#define SDEVICE_CREATE_HANDLE_DECLARATION(device_name, init_data_name, context_name)                                   \
   SDEVICE_CREATE_HANDLE_RETURN_VALUE                                                                                  \
   SDEVICE_CREATE_HANDLE(device_name)                                                                                  \
   SDEVICE_CREATE_HANDLE_ARGUMENTS(init_data_name, context_name)

#define SDEVICE_DISPOSE_HANDLE_RETURN_VALUE void
#define SDEVICE_DISPOSE_HANDLE_ARGUMENTS(handle_name) (void *handle_name)
#define SDEVICE_DISPOSE_HANDLE_POINTER(pointer_name)                                                                   \
   SDEVICE_DISPOSE_HANDLE_RETURN_VALUE (* pointer_name) SDEVICE_DISPOSE_HANDLE_ARGUMENTS()
#define SDEVICE_DISPOSE_HANDLE(device_name) device_name##SDeviceDisposeHandle
#define SDEVICE_DISPOSE_HANDLE_DECLARATION(device_name, handle_name)                                                   \
   SDEVICE_DISPOSE_HANDLE_RETURN_VALUE                                                                                 \
   SDEVICE_DISPOSE_HANDLE(device_name)                                                                                 \
   SDEVICE_DISPOSE_HANDLE_ARGUMENTS(handle_name)

typedef struct
{
   void *restrict Init;
   void *restrict Runtime;
   void *restrict Context;
} __attribute__((may_alias)) SDeviceCommonHandle;

#define SDEVICE_HANDLE(device_name) device_name##SDeviceHandle
#define SDEVICE_HANDLE_FORWARD_DECLARATION(device_name)                                                                \
   typedef struct SDEVICE_HANDLE(device_name) SDEVICE_HANDLE(device_name)
#define SDEVICE_HANDLE_DECLARATION(device_name)                                                                        \
   struct SDEVICE_HANDLE(device_name)                                                                                  \
   {                                                                                                                   \
      SDEVICE_INIT_DATA(device_name)    *Init;                                                                         \
      SDEVICE_RUNTIME_DATA(device_name) *Runtime;                                                                      \
      void                              *Context;                                                                      \
   }

#define SDEVICE_INTERNAL_ALIASES_DECLARATION(device_name)                                                              \
   typedef SDEVICE_INIT_DATA(device_name) ThisInitData;                                                                \
   typedef SDEVICE_RUNTIME_DATA(device_name) ThisRuntimeData;                                                          \
   typedef SDEVICE_HANDLE(device_name) ThisHandle

__attribute__((always_inline))
static inline const void * SDeviceGetHandleInitData(const void *handle)
{
   const SDeviceCommonHandle *_handle = handle;
   return _handle->Init;
}

__attribute__((always_inline))
static inline void * SDeviceGetHandleRuntimeData(const void *handle)
{
   const SDeviceCommonHandle *_handle = handle;
   return _handle->Runtime;
}

__attribute__((always_inline))
static inline void * SDeviceGetHandleContext(const void *handle)
{
   const SDeviceCommonHandle *_handle = handle;
   return _handle->Context;
}

typedef enum
{
   SDEVICE_PROPERTY_STATUS_OK,
   SDEVICE_PROPERTY_STATUS_VALIDATION_ERROR,
   SDEVICE_PROPERTY_STATUS_PROCESSING_ERROR
} SDevicePropertyStatus;

#define SDEVICE_IS_VALID_PROPERTY_STATUS(status) (                                                                     \
   {                                                                                                                   \
      __auto_type _mStatus = (status);                                                                                 \
                                                                                                                       \
      _mStatus == SDEVICE_PROPERTY_STATUS_OK               ||                                                          \
      _mStatus == SDEVICE_PROPERTY_STATUS_VALIDATION_ERROR ||                                                          \
      _mStatus == SDEVICE_PROPERTY_STATUS_PROCESSING_ERROR;                                                            \
   })

#define SDEVICE_PROPERTY_TYPE(device_name, property_name)                                                              \
   device_name##SDevice##property_name##PropertyType
#define SDEVICE_PROPERTY_TYPE_DECLARATION(device_name, property_name, type)                                            \
   typedef type SDEVICE_PROPERTY_TYPE(device_name, property_name)

#define SDEVICE_SET_SIMPLE_PROPERTY_RETURN_VALUE SDevicePropertyStatus
#define SDEVICE_SET_SIMPLE_PROPERTY_ARGUMENTS(handle_name, value_name) (void *handle_name, const void *value_name)
#define SDEVICE_SET_SIMPLE_PROPERTY_POINTER(pointer_name)                                                              \
   SDEVICE_SET_SIMPLE_PROPERTY_RETURN_VALUE (* pointer_name) SDEVICE_SET_SIMPLE_PROPERTY_ARGUMENTS(,)
#define SDEVICE_SET_SIMPLE_PROPERTY(device_name, property_name)                                                        \
   device_name##SDevice##property_name##SetSimpleProperty
#define SDEVICE_SET_SIMPLE_PROPERTY_DECLARATION(device_name, property_name, handle_name, value_name)                   \
   SDEVICE_SET_SIMPLE_PROPERTY_RETURN_VALUE                                                                            \
   SDEVICE_SET_SIMPLE_PROPERTY(device_name, property_name)                                                             \
   SDEVICE_SET_SIMPLE_PROPERTY_ARGUMENTS(handle_name, value_name)

#define SDEVICE_GET_SIMPLE_PROPERTY_RETURN_VALUE SDevicePropertyStatus
#define SDEVICE_GET_SIMPLE_PROPERTY_ARGUMENTS(handle_name, value_name) (void *handle_name, void *value_name)
#define SDEVICE_GET_SIMPLE_PROPERTY_POINTER(pointer_name)                                                              \
   SDEVICE_GET_SIMPLE_PROPERTY_RETURN_VALUE (* pointer_name) SDEVICE_GET_SIMPLE_PROPERTY_ARGUMENTS(,)
#define SDEVICE_GET_SIMPLE_PROPERTY(device_name, property_name)                                                        \
   device_name##SDevice##property_name##GetSimpleProperty
#define SDEVICE_GET_SIMPLE_PROPERTY_DECLARATION(device_name, property_name, handle_name, value_name)                   \
   SDEVICE_GET_SIMPLE_PROPERTY_RETURN_VALUE                                                                            \
   SDEVICE_GET_SIMPLE_PROPERTY(device_name, property_name)                                                             \
   SDEVICE_GET_SIMPLE_PROPERTY_ARGUMENTS(handle_name, value_name)

typedef struct
{
   const void *Data;
   size_t      Offset;
   size_t      Size;
} SDeviceSetPartialPropertyParameters;

#define SDEVICE_SET_PARTIAL_PROPERTY_RETURN_VALUE SDevicePropertyStatus
#define SDEVICE_SET_PARTIAL_PROPERTY_ARGUMENTS(handle_name, parameters_name) (                                         \
   void *handle_name, const SDeviceSetPartialPropertyParameters *parameters_name)
#define SDEVICE_SET_PARTIAL_PROPERTY_POINTER(pointer_name)                                                             \
   SDEVICE_SET_PARTIAL_PROPERTY_RETURN_VALUE (* pointer_name) SDEVICE_SET_PARTIAL_PROPERTY_ARGUMENTS(,)
#define SDEVICE_SET_PARTIAL_PROPERTY(device_name, property_name)                                                       \
   device_name##SDevice##property_name##SetPartialProperty
#define SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(device_name, property_name, handle_name, parameters_name)             \
   SDEVICE_SET_PARTIAL_PROPERTY_RETURN_VALUE                                                                           \
   SDEVICE_SET_PARTIAL_PROPERTY(device_name, property_name)                                                            \
   SDEVICE_SET_PARTIAL_PROPERTY_ARGUMENTS(handle_name, parameters_name)

typedef struct
{
   void  *Data;
   size_t Offset;
   size_t Size;
} SDeviceGetPartialPropertyParameters;

#define SDEVICE_GET_PARTIAL_PROPERTY_RETURN_VALUE SDevicePropertyStatus
#define SDEVICE_GET_PARTIAL_PROPERTY_ARGUMENTS(handle_name, parameters_name) (                                         \
   void *handle_name, const SDeviceGetPartialPropertyParameters *parameters_name)
#define SDEVICE_GET_PARTIAL_PROPERTY_POINTER(pointer_name)                                                             \
   SDEVICE_GET_PARTIAL_PROPERTY_RETURN_VALUE (* pointer_name) SDEVICE_GET_PARTIAL_PROPERTY_ARGUMENTS(,)
#define SDEVICE_GET_PARTIAL_PROPERTY(device_name, property_name)                                                       \
   device_name##SDevice##property_name##GetPartialProperty
#define SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(device_name, property_name, handle_name, parameters_name)             \
   SDEVICE_GET_PARTIAL_PROPERTY_RETURN_VALUE                                                                           \
   SDEVICE_GET_PARTIAL_PROPERTY(device_name, property_name)                                                            \
   SDEVICE_GET_PARTIAL_PROPERTY_ARGUMENTS(handle_name, parameters_name)
