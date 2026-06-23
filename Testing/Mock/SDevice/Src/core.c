#include "private.h"

#include "SDeviceCore/heap.h"
#include "SDeviceCore/assert.h"

#include <memory.h>

SDEVICE_CREATE_HANDLE_DECLARATION(Test, init, context)
{
   const ThisInitData *_init = init;

   SDeviceAssert(_init);

   ThisHandle *instance =
         SDeviceAllocateHandle(
               sizeof(*instance->Init),
               sizeof(*instance->Runtime));

   *instance->Init = *_init;

   instance->Context = context;

   instance->Runtime->SimplePropertyValue =
         _init->InitData;

   return instance;
}

SDEVICE_DISPOSE_HANDLE_DECLARATION(Test, this)
{
   SDeviceAssert(this);

   SDeviceFreeHandle(this);
}

SDEVICE_GET_SIMPLE_PROPERTY_DECLARATION(Test, SimplePropertyValue, this, value)
{
   ThisHandle *_this = this;

   SDeviceAssert(value);
   SDeviceAssert(_this);

   memcpy(value, &_this->Runtime->SimplePropertyValue, sizeof(_this->Runtime->SimplePropertyValue));

   return SDevicePropertyStatusOk;
}

SDEVICE_SET_SIMPLE_PROPERTY_DECLARATION(Test, SimplePropertyValue, this, value)
{
   ThisHandle *_this = this;

   SDeviceAssert(_this);
   SDeviceAssert(value);

   SDEVICE_PROPERTY_TYPE(Test, SimplePropertyValue) _value;
   memcpy(&_value, value, sizeof(_value));

   _this->Runtime->SimplePropertyValue = _value;

   return SDevicePropertyStatusOk;
}

SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(Test, PartialPropertyValue, this, parameters)
{
   ThisHandle *_this = this;

   SDeviceAssert(_this);
   SDeviceAssert(parameters);
   SDeviceAssert(parameters->Data);

   if(not SDeviceGetPartialPropertyParametersAreValid(parameters, sizeof(_this->Runtime->PartialPropertyValue)))
      return SDevicePropertyStatusValidationError;

   memcpy(parameters->Data, &_this->Runtime->PartialPropertyValue.Value[parameters->Offset], parameters->Size);

   return SDevicePropertyStatusOk;
}

SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(Test, PartialPropertyValue, this, parameters)
{
   ThisHandle *_this = this;

   SDeviceAssert(_this);
   SDeviceAssert(parameters);
   SDeviceAssert(parameters->Data);

   if(not SDeviceSetPartialPropertyParametersAreValid(parameters, sizeof(_this->Runtime->PartialPropertyValue)))
      return SDevicePropertyStatusValidationError;

   memcpy(&_this->Runtime->PartialPropertyValue.Value[parameters->Offset], parameters->Data, parameters->Size);

   return SDevicePropertyStatusOk;
}
