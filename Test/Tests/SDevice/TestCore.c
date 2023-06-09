#include "TestCore.h"
#include "SDeviceCore/core.h"
#include "SDeviceCore/heap.h"
#include <memory.h>
#include "SDeviceCore/errors.h"

SDEVICE_RUNTIME_DATA_FORWARD_DECLARATION(TestDevice);
SDEVICE_RUNTIME_DATA_DECLARATION(TestDevice)
{
   SDEVICE_PROPERTY_TYPE(TestDevice,PropertyValue) testDeviceData;
};

SDEVICE_HANDLE_DECLARATION(TestDevice);
SDEVICE_INTERNAL_ALIASES_DECLARATION(TestDevice);
SDEVICE_STRING_NAME_DEFINITION(TestDevice);


SDEVICE_CREATE_HANDLE_DECLARATION(TestDevice, _init, _owner, _id,_context)
{
    SDeviceAssert(_init!= NULL);
    const ThisInitData* init = (ThisInitData*)_init;

    ThisHandle *handle = SDeviceMalloc(sizeof(ThisHandle));
    SDeviceAssert(handle!= NULL);

    handle->Header = (SDeviceHandleHeader)
    {
        .Context = _context,
        .OwnerHandle = _owner,
        .LatestStatus = TEST_DEVICE_STATUS_OK,
        .SDeviceStringName = SDEVICE_STRING_NAME(TestDevice),
        .Identifier = _id
    };

    handle->Init = *init;
    
    handle->Runtime = (ThisRuntimeData)
    {
        .testDeviceData = init->testDeviceData
    };

    return handle;
}

SDEVICE_DISPOSE_HANDLE_DECLARATION(TestDevice, _handlePtr)
{
    SDeviceAssert(_handlePtr!= NULL);
    ThisHandle **handlePtr = _handlePtr;
    
    SDeviceFree(*handlePtr);
    *handlePtr = NULL;
}

SDEVICE_GET_PROPERTY_DECLARATION(TestDevice, PropertyValue, _handle, _value)
{
    SDeviceAssert(_handle!= NULL);
    SDeviceAssert(_value!= NULL);

    ThisHandle *handle = _handle;

    memcpy(_value, &handle->Runtime.testDeviceData, sizeof(handle->Runtime.testDeviceData));

    return SDEVICE_PROPERTY_OPERATION_STATUS_OK;
}

SDEVICE_SET_PROPERTY_DECLARATION(TestDevice, PropertyValue, _handle, _value)
{
    SDeviceAssert(_handle!= NULL);
    SDeviceAssert(_value!= NULL);

    ThisHandle *handle = _handle;

    memcpy(&handle->Runtime.testDeviceData, _value, sizeof(handle->Runtime.testDeviceData));

    return SDEVICE_PROPERTY_OPERATION_STATUS_OK;
}   

SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(TestDevice, partialPropertyValue, _handle, _parameters)
{
    SDeviceAssert(_handle!= NULL);
    SDeviceAssert(_parameters!= NULL);
    SDeviceAssert(_parameters->Data!= NULL);

    ThisHandle *handle = _handle;

    if (_parameters->Size > sizeof(SDEVICE_PROPERTY_TYPE(TestDevice, PropertyValue)) || 
            _parameters->Offset > sizeof(SDEVICE_PROPERTY_TYPE(TestDevice, PropertyValue)) - _parameters->Size)
    {
        return SDEVICE_PROPERTY_OPERATION_STATUS_VALIDATION_ERROR;
    }
    
    memcpy(_parameters->Data, &((char *)&handle->Runtime.testDeviceData)[_parameters->Offset], _parameters->Size);
    
    return SDEVICE_PROPERTY_OPERATION_STATUS_OK;
}

SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(TestDevice, partialPropertyValue, _handle, _parameters)
{
    SDeviceAssert(_handle!= NULL);
    SDeviceAssert(_parameters!= NULL);
    SDeviceAssert(_parameters->Data!= NULL);

    ThisHandle *handle = _handle;

    if (_parameters->Size > sizeof(SDEVICE_PROPERTY_TYPE(TestDevice, PropertyValue)) || 
            _parameters->Offset > sizeof(SDEVICE_PROPERTY_TYPE(TestDevice, PropertyValue)) - _parameters->Size)
    {
        return SDEVICE_PROPERTY_OPERATION_STATUS_VALIDATION_ERROR;
    }
    
    memcpy(&((char *)&handle->Runtime.testDeviceData)[_parameters->Offset], _parameters->Data, _parameters->Size);
    
    return SDEVICE_PROPERTY_OPERATION_STATUS_OK;
}
