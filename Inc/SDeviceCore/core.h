#pragma once

#include <stdint.h>
#include <stddef.h>

/* version ************************************************************************************************************/

#define SDEVICE_CORE_VERSION_MAJOR 5
#define SDEVICE_CORE_VERSION_MINOR 0
#define SDEVICE_CORE_VERSION_PATCH 0
#define SDEVICE_CORE_VERSION ((SDeviceVersion)                                                                         \
{                                                                                                                      \
   .Major = SDEVICE_CORE_VERSION_MAJOR,                                                                                \
   .Minor = SDEVICE_CORE_VERSION_MINOR,                                                                                \
   .Patch = SDEVICE_CORE_VERSION_PATCH                                                                                 \
})

typedef struct
{
   uint16_t Major;
   uint8_t Minor;
   uint8_t Patch;
} SDeviceVersion;

/* handle *************************************************************************************************************/

typedef struct SDeviceNameNode SDeviceNameNode;

struct SDeviceNameNode
{
   const char *Name;
   const SDeviceNameNode *OuterNode;
};

typedef struct
{
   void *Context;
   SDeviceNameNode NameNode;
   int32_t LatestStatus;
} SDeviceHandleHeader;

typedef struct
{
   SDeviceHandleHeader Header;
   char Data[];
} SDeviceCommonHandle;

#define SDEVICE_INIT_DATA(device_name) $##device_name##SDeviceInitData
#define SDEVICE_INIT_DATA_FORWARD_DECLARATION(device_name)                                                             \
   typedef struct SDEVICE_INIT_DATA(device_name) SDEVICE_INIT_DATA(device_name)

#define SDEVICE_RUNTIME_DATA(device_name) $##device_name##SDeviceRuntimeData
#define SDEVICE_RUNTIME_DATA_FORWARD_DECLARATION(device_name)                                                          \
   typedef struct SDEVICE_RUNTIME_DATA(device_name) SDEVICE_RUNTIME_DATA(device_name)

#define SDEVICE_HANDLE(device_name) $##device_name##SDeviceHandle
#define SDEVICE_HANDLE_FORWARD_DECLARATION(device_name)                                                                \
   typedef struct SDEVICE_HANDLE(device_name) SDEVICE_HANDLE(device_name)
#define SDEVICE_HANDLE_DECLARATION(device_name) struct SDEVICE_HANDLE(device_name)                                     \
{                                                                                                                      \
   SDeviceHandleHeader Header;                                                                                         \
   SDEVICE_INIT_DATA(device_name) Init;                                                                                \
   SDEVICE_RUNTIME_DATA(device_name) Runtime;                                                                          \
}

#define SDEVICE_INTERNAL_ALIASES_DECLARATION(device_name)                                                              \
   typedef SDEVICE_INIT_DATA(device_name) ThisInitData;                                                                \
   typedef SDEVICE_RUNTIME_DATA(device_name) ThisRuntimeData;                                                          \
   typedef SDEVICE_HANDLE(device_name) ThisHandle

#define SDEVICE_STRING_NAME(device_name) $##device_name##SDeviceStringName
#define SDEVICE_STRING_NAME_DECLARATION(device_name) extern const char SDEVICE_STRING_NAME(device_name)[];
#define SDEVICE_STRING_NAME_DEFINITION(device_name) const char SDEVICE_STRING_NAME(device_name)[] = #device_name;

static inline void * SDeviceGetHandleContext(const void *_handle)
{
   const SDeviceCommonHandle *handle = _handle;
   return handle->Header.Context;
}

static inline int32_t SDeviceGetHandleLatestStatus(const void *_handle)
{
   const SDeviceCommonHandle *handle = _handle;
   return handle->Header.LatestStatus;
}

static inline const SDeviceNameNode * SDeviceGetHandleNameNodePointer(const void *_handle)
{
   const SDeviceCommonHandle *handle = _handle;
   return &handle->Header.NameNode;
}

/* create handle ******************************************************************************************************/

#define SDEVICE_CREATE_HANDLE_RETURN_VALUE void *
#define SDEVICE_CREATE_HANDLE_ARGUMENTS(init_data_name, context_name, outer_name_node_name)                            \
   (const void *init_data_name, void *context_name, const SDeviceNameNode *outer_name_node_name)
#define SDEVICE_CREATE_HANDLE_POINTER(pointer_name)                                                                    \
   SDEVICE_CREATE_HANDLE_RETURN_VALUE (* pointer_name) SDEVICE_CREATE_HANDLE_ARGUMENTS(,,)
#define SDEVICE_CREATE_HANDLE(device_name) $##device_name##SDeviceCreateHandle
#define SDEVICE_CREATE_HANDLE_DECLARATION(device_name, init_data_name, context_name, outer_name_node_name)             \
   SDEVICE_CREATE_HANDLE_RETURN_VALUE                                                                                  \
   SDEVICE_CREATE_HANDLE(device_name)                                                                                  \
   SDEVICE_CREATE_HANDLE_ARGUMENTS(init_data_name, context_name, outer_name_node_name)

/* dispose handle *****************************************************************************************************/

#define SDEVICE_DISPOSE_HANDLE_RETURN_VALUE void
#define SDEVICE_DISPOSE_HANDLE_ARGUMENTS(handle_pointer_name) (void *handle_pointer_name)
#define SDEVICE_DISPOSE_HANDLE_POINTER(pointer_name)                                                                   \
   SDEVICE_DISPOSE_HANDLE_RETURN_VALUE (* pointer_name) SDEVICE_DISPOSE_HANDLE_ARGUMENTS()
#define SDEVICE_DISPOSE_HANDLE(device_name) $##device_name##SDeviceDisposeHandle
#define SDEVICE_DISPOSE_HANDLE_DECLARATION(device_name, handle_pointer_name)                                           \
   SDEVICE_DISPOSE_HANDLE_RETURN_VALUE                                                                                 \
   SDEVICE_DISPOSE_HANDLE(device_name)                                                                                 \
   SDEVICE_DISPOSE_HANDLE_ARGUMENTS(handle_pointer_name)

/* property ***********************************************************************************************************/

typedef enum
{
    SDEVICE_PROPERTY_OPERATION_STATUS_OK,
    SDEVICE_PROPERTY_OPERATION_STATUS_VALIDATION_ERROR,
    SDEVICE_PROPERTY_OPERATION_STATUS_PROCESSING_ERROR
} SDevicePropertyOperationStatus;

#define SDEVICE_PROPERTY_TYPE(device_name, property_name) $##device_name##SDevice##property_name##PropertyType
#define SDEVICE_PROPERTY_TYPE_DECLARATION(device_name, property_name, type)                                            \
   typedef type SDEVICE_PROPERTY_TYPE(device_name, property_name)

/* property set *******************************************************************************************************/

#define SDEVICE_SET_PROPERTY_RETURN_VALUE SDevicePropertyOperationStatus
#define SDEVICE_SET_PROPERTY_ARGUMENTS(handle_name, value_name) (void *handle_name, const void *value_name)
#define SDEVICE_SET_PROPERTY_POINTER(pointer_name)                                                                     \
   SDEVICE_SET_PROPERTY_RETURN_VALUE (* pointer_name) SDEVICE_SET_PROPERTY_ARGUMENTS(,)
#define SDEVICE_SET_PROPERTY(device_name, property_name) $##device_name##SDevice##property_name##SetProperty
#define SDEVICE_SET_PROPERTY_DECLARATION(device_name, property_name, handle_name, value_name)                          \
   SDEVICE_SET_PROPERTY_RETURN_VALUE                                                                                   \
   SDEVICE_SET_PROPERTY(device_name, property_name)                                                                    \
   SDEVICE_SET_PROPERTY_ARGUMENTS(handle_name, value_name)

/* partial property set ***********************************************************************************************/

typedef struct
{
   const void *Data;
   size_t Offset;
   size_t Size;
} SDeviceSetPartialPropertyParameters;

#define SDEVICE_SET_PARTIAL_PROPERTY_RETURN_VALUE SDevicePropertyOperationStatus
#define SDEVICE_SET_PARTIAL_PROPERTY_ARGUMENTS(handle_name, parameters_name)                                           \
   (void *handle_name, const SDeviceSetPartialPropertyParameters *parameters_name)
#define SDEVICE_SET_PARTIAL_PROPERTY_POINTER(pointer_name)                                                             \
   SDEVICE_SET_PARTIAL_PROPERTY_RETURN_VALUE (* pointer_name) SDEVICE_SET_PARTIAL_PROPERTY_ARGUMENTS(,)
#define SDEVICE_SET_PARTIAL_PROPERTY(device_name, property_name)                                                       \
   $##device_name##SDevice##property_name##SetPartialProperty
#define SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(device_name, property_name, handle_name, parameters_name)             \
   SDEVICE_SET_PARTIAL_PROPERTY_RETURN_VALUE                                                                           \
   SDEVICE_SET_PARTIAL_PROPERTY(device_name, property_name)                                                            \
   SDEVICE_SET_PARTIAL_PROPERTY_ARGUMENTS(handle_name, parameters_name)

/* property get *******************************************************************************************************/

#define SDEVICE_GET_PROPERTY_RETURN_VALUE SDevicePropertyOperationStatus
#define SDEVICE_GET_PROPERTY_ARGUMENTS(handle_name, value_name) (void *handle_name, void *value_name)
#define SDEVICE_GET_PROPERTY_POINTER(pointer_name)                                                                     \
   SDEVICE_GET_PROPERTY_RETURN_VALUE (* pointer_name) SDEVICE_GET_PROPERTY_ARGUMENTS(,)
#define SDEVICE_GET_PROPERTY(device_name, property_name) device_name##SDevice##property_name##GetProperty
#define SDEVICE_GET_PROPERTY_DECLARATION(device_name, property_name, handle_name, value_name)                          \
   SDEVICE_GET_PROPERTY_RETURN_VALUE                                                                                   \
   SDEVICE_GET_PROPERTY(device_name, property_name)                                                                    \
   SDEVICE_GET_PROPERTY_ARGUMENTS(handle_name, value_name)

/* partial property get ***********************************************************************************************/

typedef struct
{
   void *Data;
   size_t Offset;
   size_t Size;
} SDeviceGetPartialPropertyParameters;

#define SDEVICE_GET_PARTIAL_PROPERTY_RETURN_VALUE SDevicePropertyOperationStatus
#define SDEVICE_GET_PARTIAL_PROPERTY_ARGUMENTS(handle_name, parameters_name)                                           \
   (void *handle_name, const SDeviceGetPartialPropertyParameters *parameters_name)
#define SDEVICE_GET_PARTIAL_PROPERTY_POINTER(pointer_name)                                                             \
   SDEVICE_GET_PARTIAL_PROPERTY_RETURN_VALUE (* pointer_name) SDEVICE_GET_PARTIAL_PROPERTY_ARGUMENTS(,)
#define SDEVICE_GET_PARTIAL_PROPERTY(device_name, property_name)                                                       \
   $##device_name##SDevice##property_name##GetPartialProperty
#define SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(device_name, property_name, handle_name, parameters_name)             \
   SDEVICE_GET_PARTIAL_PROPERTY_RETURN_VALUE                                                                           \
   SDEVICE_GET_PARTIAL_PROPERTY(device_name, property_name)                                                            \
   SDEVICE_GET_PARTIAL_PROPERTY_ARGUMENTS(handle_name, parameters_name)

/**********************************************************************************************************************/
