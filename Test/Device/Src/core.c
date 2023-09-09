#include "private.h"

#include <memory.h>

SDEVICE_IDENTITY_BLOCK_DEFINITION(TestDevice,
                                  ((const SDeviceUuid)
                                  {
                                     .High = TEST_DEVICE_SDEVICE_UUID_HIGH,
                                     .Low  = TEST_DEVICE_SDEVICE_UUID_LOW
                                  }),
                                  ((const SDeviceVersion)
                                  {
                                     .Major = TEST_DEVICE_SDEVICE_VERSION_MAJOR,
                                     .Minor = TEST_DEVICE_SDEVICE_VERSION_MINOR,
                                     .Patch = TEST_DEVICE_SDEVICE_VERSION_PATCH
                                  }));

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
        .IdentityBlock = &SDEVICE_IDENTITY_BLOCK(TestDevice),
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

    return SDEVICE_PROPERTY_STATUS_OK;
}

SDEVICE_SET_PROPERTY_DECLARATION(TestDevice, PropertyValue, _handle, _value)
{
    SDeviceAssert(_handle!= NULL);
    SDeviceAssert(_value!= NULL);

    ThisHandle *handle = _handle;

    memcpy(&handle->Runtime.testDeviceData, _value, sizeof(handle->Runtime.testDeviceData));

    return SDEVICE_PROPERTY_STATUS_OK;
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
        return SDEVICE_PROPERTY_STATUS_VALIDATION_ERROR;
    }

    memcpy(_parameters->Data, &((char *)&handle->Runtime.testDeviceData)[_parameters->Offset], _parameters->Size);

    return SDEVICE_PROPERTY_STATUS_OK;
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
        return SDEVICE_PROPERTY_STATUS_VALIDATION_ERROR;
    }

    memcpy(&((char *)&handle->Runtime.testDeviceData)[_parameters->Offset], _parameters->Data, _parameters->Size);

    return SDEVICE_PROPERTY_STATUS_OK;
}
