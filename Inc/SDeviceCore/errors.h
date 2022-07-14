#pragma once

#include <stddef.h>

#define CEXCEPTION_NONE (NULL)
#define CEXCEPTION_T const void *
#define CEXCEPTION_NO_CATCH_HANDLER(id) _SDeviceProcessUnhandledThrow(id)

#include "../../Submodules/cexception/lib/CException.h"

#ifdef __SDEVICE_USE_ASSERT
#define SDeviceAssert(expression) ((expression) ? (void)0U : _SDeviceProcessAssertFail(__FILE__, __LINE__))
#define SDeviceEvalAssert(expression) SDeviceAssert(expression)
void _SDeviceProcessAssertFail(char *, int);
#else
#define SDeviceAssert(expression) ((void)0U)
#define SDeviceEvalAssert(expression) expression
#endif

#ifdef __SDEVICE_USE_THROW
#define SDeviceThrow(handle, status) (                                                                                 \
{                                                                                                                      \
   const void *__handle = (handle);                                                                                    \
   ((SDeviceCommonHandle *)__handle)->Header.LatestStatus = status;                                                    \
   Throw(__handle);                                                                                                    \
})
void _SDeviceProcessUnhandledThrow(const void *);
#else
#define SDeviceThrow(handle, error) ((SDeviceCommonHandle *)(handle))->Header.LastError = error
#endif

#ifdef __SDEVICE_USE_STATUS_LOG
#define SDeviceLogStatus(handle, status) (                                                                             \
{                                                                                                                      \
   const void *__handle = (handle);                                                                                    \
   ((SDeviceCommonHandle *)__handle)->Header.LatestStatus = status;                                                    \
   _SDeviceLogStatus(__handle);                                                                                        \
})
void _SDeviceLogStatus(const void *);
#else
#define SDeviceLogStatus(handle, status) ((SDeviceCommonHandle *)(handle))->Header.LastError = error
#endif

