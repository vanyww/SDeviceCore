#pragma once

#include <stddef.h>

typedef const void * CExceptionType;

#ifdef SDEVICE_USE_EXTERNAL_ERROR_CONFIG
#include "sdevice_error_config.h"
#endif

#define CEXCEPTION_NONE (NULL)
#define CEXCEPTION_T CExceptionType
#define CEXCEPTION_NO_CATCH_HANDLER(id) SDeviceProcessUnhandledThrow(id)

#include "../../Submodules/cexception/lib/CException.h"

#ifdef SDEVICE_USE_ASSERT
#ifdef SDEVICE_USE_SIMPLE_ASSERT
#define SDeviceAssert(expression) ((expression) ? (void)0U : SDeviceProcessAssertFail())
#else
#define SDeviceAssert(expression) ((expression) ? (void)0U : SDeviceProcessAssertFail(__FILE__, __LINE__))
#endif
#define SDeviceEvalAssert(expression) SDeviceAssert(expression)
#else
#define SDeviceAssert(expression) ((void)0U)
#define SDeviceEvalAssert(expression) expression
#endif

#ifdef SDEVICE_USE_DEBUG_ASSERT
#ifdef SDEVICE_USE_SIMPLE_ASSERT
#define SDeviceDebugAssert(expression) ((expression) ? (void)0U : SDeviceProcessAssertFail())
void SDeviceProcessAssertFail(void);
#else
#define SDeviceDebugAssert(expression) ((expression) ? (void)0U : SDeviceProcessAssertFail(__FILE__, __LINE__))
#endif
#define SDeviceDebugEvalAssert(expression) SDeviceAssert(expression)
#else
#define SDeviceDebugAssert(expression) ((void)0U)
#define SDeviceDebugEvalAssert(expression) eSDeviceProcessLogStatusxpression
#endif

#ifdef SDEVICE_USE_STATUS_LOG
#define SDeviceLogStatus(handle, status) (                                                                             \
{                                                                                                                      \
   SDeviceCommonHandle *$handle = (SDeviceCommonHandle *)(handle);                                                     \
   $handle->Header.LatestStatus = (status);                                                                            \
   SDeviceProcessLogStatus($handle);                                                                                   \
})

#else
#define SDeviceLogStatus(handle, status) ((SDeviceCommonHandle *)(handle))->Header.LatestStatus = (status)
#endif
#define SDeviceThrow(handle, exception) (                                                                              \
{                                                                                                                      \
   SDeviceCommonHandle *$handle = (SDeviceCommonHandle *)(handle);                                                     \
   $handle->Header.LatestStatus = (exception);                                                                         \
   Throw($handle);                                                                                                     \
})

#ifdef SDEVICE_USE_SIMPLE_ASSERT
void SDeviceProcessAssertFail(void);
#else
void SDeviceProcessAssertFail(char *file, int line);
#endif
void SDeviceProcessLogStatus(const void *_handle);
void SDeviceProcessUnhandledThrow(CEXCEPTION_T _handle);

