#pragma once

#include <stddef.h>

typedef const void * CExceptionType;
void _SDeviceProcessUnhandledThrow(const void *);

#define CEXCEPTION_NONE (NULL)
#define CEXCEPTION_T CExceptionType
#define CEXCEPTION_NO_CATCH_HANDLER(id) _SDeviceProcessUnhandledThrow(id)
