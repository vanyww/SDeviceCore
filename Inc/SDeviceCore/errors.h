#pragma once

#include <stddef.h>

typedef const void * CExceptionType;

#define CEXCEPTION_NONE (NULL)
#define CEXCEPTION_T CExceptionType
#define CEXCEPTION_NO_CATCH_HANDLER(id) _SDeviceProcessUnhandledThrow(id)

#include "../../Submodules/cexception/lib/CException.h"

#ifdef __SDEVICE_USE_ASSERT
#define SDeviceAssert(expression) ((expression) ? (void)0U : _SDeviceProcessAssertFail(__FILE__, __LINE__))
#define SDeviceEvalAssert(expression) SDeviceAssert(expression)
void _SDeviceProcessAssertFail(char *file, int line);
#else
#define SDeviceAssert(expression) ((void)0U)
#define SDeviceEvalAssert(expression) expression
#endif

#ifdef __SDEVICE_USE_STATUS_LOG
#define SDeviceLogStatus(handle, status) (                                                                             \
{                                                                                                                      \
   SDeviceCommonHandle *__handle = (SDeviceCommonHandle *)(handle);                                                    \
   __handle->Header.LatestStatus = (status);                                                                           \
   _SDeviceLogStatus(__handle);                                                                                        \
})
void _SDeviceLogStatus(const void *_handle);
#else
#define SDeviceLogStatus(handle, status) ((SDeviceCommonHandle *)(handle))->Header.LatestStatus = (status)
#endif

#define SDeviceThrow(handle, exception) (                                                                              \
{                                                                                                                      \
   SDeviceCommonHandle *__handle = (SDeviceCommonHandle *)(handle);                                                    \
   __handle->Header.LatestStatus = (exception);                                                                        \
   Throw(__handle);                                                                                                    \
})
void _SDeviceProcessUnhandledThrow(CEXCEPTION_T _handle);
