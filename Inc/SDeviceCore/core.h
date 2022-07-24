#pragma once

#include "common.h"

#include <stdint.h>
#include <stddef.h>

#define __SDEVICE_CORE_VERSION_MAJOR 2
#define __SDEVICE_CORE_VERSION_MINOR 1
#define __SDEVICE_CORE_VERSION_PATCH 1

/* handle *************************************************************************************************************/

typedef struct
{
   void *Context;
   int32_t LatestStatus;
   uint32_t InstanceIndex;
} SDeviceHandleHeader;

typedef struct
{
   SDeviceHandleHeader Header;
   char Data[];
} SDeviceCommonHandle;

#define __SDEVICE_INIT_DATA(name) __##name##_SDeviceInitData
#define __SDEVICE_INIT_DATA_FORWARD_DECLARATION(name)                                                                  \
   typedef struct __SDEVICE_INIT_DATA(name) __SDEVICE_INIT_DATA(name)

#define __SDEVICE_RUNTIME_DATA(name) __##name##_SDeviceRuntimeData
#define __SDEVICE_RUNTIME_DATA_FORWARD_DECLARATION(name)                                                               \
   typedef struct __SDEVICE_RUNTIME_DATA(name) __SDEVICE_RUNTIME_DATA(name)

#define __SDEVICE_HANDLE(name) __##name##_SDeviceHandle
#define __SDEVICE_HANDLE_FORWARD_DECLARATION(name)                                                                     \
   typedef struct __SDEVICE_HANDLE(name) __SDEVICE_HANDLE(name)
#define __SDEVICE_HANDLE_DEFINITION(name) struct __SDEVICE_HANDLE(name)                                                \
{                                                                                                                      \
   SDeviceHandleHeader Header;                                                                                         \
   __SDEVICE_INIT_DATA(name) Init;                                                                                     \
   __SDEVICE_RUNTIME_DATA(name) Runtime;                                                                               \
}

static inline void * SDeviceGetHandleContext(const void *_handle)
{
   return ((const SDeviceCommonHandle *)_handle)->Header.Context;
}

static inline int32_t SDeviceGetHandleLatestStatus(const void *_handle)
{
   return ((const SDeviceCommonHandle *)_handle)->Header.LatestStatus;
}

static inline uint32_t SDeviceGetHandleInstanceIndex(const void *_handle)
{
   return ((const SDeviceCommonHandle *)_handle)->Header.InstanceIndex;
}

/* create handle ******************************************************************************************************/

#define __SDEVICE_CREATE_HANDLE_RETURN_VALUE void *
#define __SDEVICE_CREATE_HANDLE_ARGUMENTS(init_data_name, context_name, instance_index_name)                           \
   (void *init_data_name, void *context_name, uint32_t instance_index_name)
#define __SDEVICE_CREATE_HANDLE_POINTER(pointer_name)                                                                  \
   __SDEVICE_CREATE_HANDLE_RETURN_VALUE (* pointer_name) __SDEVICE_CREATE_HANDLE_ARGUMENTS(,,)
#define __SDEVICE_CREATE_HANDLE(name) __##name##_SDeviceCreateHandle
#define __SDEVICE_CREATE_HANDLE_DECLARATION(name, init_data_name, context_name, instance_index_name)                   \
   __SDEVICE_CREATE_HANDLE_RETURN_VALUE                                                                                \
   __SDEVICE_CREATE_HANDLE(name)                                                                                       \
   __SDEVICE_CREATE_HANDLE_ARGUMENTS(init_data_name, context_name, instance_index_name)

/* dispose handle *****************************************************************************************************/

#define __SDEVICE_DISPOSE_HANDLE_RETURN_VALUE void
#define __SDEVICE_DISPOSE_HANDLE_ARGUMENTS(handle_pointer_name) (void *handle_pointer_name)
#define __SDEVICE_DISPOSE_HANDLE_POINTER(pointer_name)                                                                 \
   __SDEVICE_DISPOSE_HANDLE_RETURN_VALUE (* pointer_name) __SDEVICE_DISPOSE_HANDLE_ARGUMENTS()
#define __SDEVICE_DISPOSE_HANDLE(name) __##name##_SDeviceDisposeHandle
#define __SDEVICE_DISPOSE_HANDLE_DECLARATION(name, handle_pointer_name)                                                \
   __SDEVICE_DISPOSE_HANDLE_RETURN_VALUE                                                                               \
   __SDEVICE_DISPOSE_HANDLE(name)                                                                                      \
   __SDEVICE_DISPOSE_HANDLE_ARGUMENTS(handle_pointer_name)

/* property ***********************************************************************************************************/

typedef enum
{
    SDEVICE_PROPERTY_OPERATION_STATUS_OK,
    SDEVICE_PROPERTY_OPERATION_STATUS_VALIDATION_ERROR,
    SDEVICE_PROPERTY_OPERATION_STATUS_PROCESSING_ERROR
} SDevicePropertyOperationStatus;

#define __SDEVICE_PROPERTY_TYPE(name, property_name) __##name##_SDevice_##property_name##_PropertyType
#define __SDEVICE_PROPERTY_TYPE_DEFINITION(name, property_name, type)                                                  \
   typedef type __SDEVICE_PROPERTY_TYPE(name, property_name)

/* property set *******************************************************************************************************/

#define __SDEVICE_SET_PROPERTY_RETURN_VALUE SDevicePropertyOperationStatus
#define __SDEVICE_SET_PROPERTY_ARGUMENTS(handle_name, value_name) (void *handle_name, const void *value_name)
#define __SDEVICE_SET_PROPERTY_POINTER(pointer_name)                                                                   \
   __SDEVICE_SET_PROPERTY_RETURN_VALUE (* pointer_name) __SDEVICE_SET_PROPERTY_ARGUMENTS(,)
#define __SDEVICE_SET_PROPERTY(name, property_name) __##name##_SDevice_##property_name##_SetProperty
#define __SDEVICE_SET_PROPERTY_DECLARATION(name, property_name, handle_name, value_name)                               \
   __SDEVICE_SET_PROPERTY_RETURN_VALUE                                                                                 \
   __SDEVICE_SET_PROPERTY(name, property_name)                                                                         \
   __SDEVICE_SET_PROPERTY_ARGUMENTS(handle_name, value_name)

/* partial property set ***********************************************************************************************/

typedef struct
{
   const void *Data;
   size_t Offset;
   size_t Size;
} SDeviceSetPartialPropertyParameters;

#define __SDEVICE_SET_PARTIAL_PROPERTY_RETURN_VALUE SDevicePropertyOperationStatus
#define __SDEVICE_SET_PARTIAL_PROPERTY_ARGUMENTS(handle_name, parameters_name)                                         \
   (void *handle_name, const SDeviceSetPartialPropertyParameters *parameters_name)
#define __SDEVICE_SET_PARTIAL_PROPERTY_POINTER(pointer_name)                                                           \
   __SDEVICE_SET_PARTIAL_PROPERTY_RETURN_VALUE (* pointer_name) __SDEVICE_SET_PARTIAL_PROPERTY_ARGUMENTS(,)
#define __SDEVICE_SET_PARTIAL_PROPERTY(name, property_name) __##name##_SDevice_##property_name##_SetPartialProperty
#define __SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(name, property_name, handle_name, parameters_name)                  \
   __SDEVICE_SET_PARTIAL_PROPERTY_RETURN_VALUE                                                                         \
   __SDEVICE_SET_PARTIAL_PROPERTY(name, property_name)                                                                 \
   __SDEVICE_SET_PARTIAL_PROPERTY_ARGUMENTS(handle_name, parameters_name)

/* property get *******************************************************************************************************/

#define __SDEVICE_GET_PROPERTY_RETURN_VALUE SDevicePropertyOperationStatus
#define __SDEVICE_GET_PROPERTY_ARGUMENTS(handle_name, value_name) (void *handle_name, void *value_name)
#define __SDEVICE_GET_PROPERTY_POINTER(pointer_name)                                                                   \
   __SDEVICE_GET_PROPERTY_RETURN_VALUE (* pointer_name) __SDEVICE_GET_PROPERTY_ARGUMENTS(,)
#define __SDEVICE_GET_PROPERTY(name, property_name) __##name##_SDevice_##property_name##_GetProperty
#define __SDEVICE_GET_PROPERTY_DECLARATION(name, property_name, handle_name, value_name)                               \
   __SDEVICE_GET_PROPERTY_RETURN_VALUE                                                                                 \
   __SDEVICE_GET_PROPERTY(name, property_name)                                                                         \
   __SDEVICE_GET_PROPERTY_ARGUMENTS(handle_name, value_name)

/* partial property get ***********************************************************************************************/

typedef struct
{
   void *Data;
   size_t Offset;
   size_t Size;
} SDeviceGetPartialPropertyParameters;

#define __SDEVICE_GET_PARTIAL_PROPERTY_RETURN_VALUE SDevicePropertyOperationStatus
#define __SDEVICE_GET_PARTIAL_PROPERTY_ARGUMENTS(handle_name, parameters_name)                                         \
   (void *handle_name, const SDeviceGetPartialPropertyParameters *parameters_name)
#define __SDEVICE_GET_PARTIAL_PROPERTY_POINTER(pointer_name)                                                           \
   __SDEVICE_GET_PARTIAL_PROPERTY_RETURN_VALUE (* pointer_name) __SDEVICE_GET_PARTIAL_PROPERTY_ARGUMENTS(,)
#define __SDEVICE_GET_PARTIAL_PROPERTY(name, property_name) __##name##_SDevice_##property_name##_GetPartialProperty
#define __SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(name, property_name, handle_name, parameters_name)                  \
   __SDEVICE_GET_PARTIAL_PROPERTY_RETURN_VALUE                                                                         \
   __SDEVICE_GET_PARTIAL_PROPERTY(name, property_name)                                                                 \
   __SDEVICE_GET_PARTIAL_PROPERTY_ARGUMENTS(handle_name, parameters_name)

/**********************************************************************************************************************/
