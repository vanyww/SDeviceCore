#pragma once

#include <stddef.h>

/* cexception *********************************************************************************************************/

typedef const void * CExceptionType;

#ifdef SDEVICE_USE_EXTERNAL_ERROR_CONFIG
#include "sdevice_error_config.h"
#endif

#define CEXCEPTION_NONE (NULL)
#define CEXCEPTION_T CExceptionType
#define CEXCEPTION_NO_CATCH_HANDLER(id) SDeviceProcessUnhandledThrow(id)

#ifdef SDEVICE_USE_EXTERNAL_ERROR_CONFIG
#include "sdevice_error_config.h"
#endif

#include "../../Submodules/cexception/lib/CException.h"

/* assertations *******************************************************************************************************/

#ifdef SDEVICE_USE_ASSERT
#ifdef SDEVICE_USE_SIMPLE_ASSERT
#define SDeviceAssert(expression) ((expression) ? (void)0U : SDeviceProcessAssertFail())
void SDeviceProcessAssertFail(void);
#else
#define SDeviceAssert(expression) ((expression) ? (void)0U : SDeviceProcessAssertFail(__FILE__, __LINE__))
void SDeviceProcessAssertFail(char *file, int line);
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
void SDeviceProcessAssertFail(char *file, int line);
#endif
#define SDeviceDebugEvalAssert(expression) SDeviceAssert(expression)
#else
#define SDeviceDebugAssert(expression) ((void)0U)
#define SDeviceDebugEvalAssert(expression) eSDeviceProcessLogStatusxpression
#endif

/* logging ************************************************************************************************************/

#ifdef SDEVICE_USE_STATUS_LOG
#define SDeviceLogStatus(handle, status) (                                                                             \
{                                                                                                                      \
   SDeviceCommonHandle *$handle = (SDeviceCommonHandle *)(handle);                                                     \
   $handle->Header.LatestStatus = (status);                                                                            \
   SDeviceProcessLogStatus($handle);                                                                                   \
})
void SDeviceProcessLogStatus(const void *_handle);
#else
#define SDeviceLogStatus(handle, status) ((SDeviceCommonHandle *)(handle))->Header.LatestStatus = (status)
#endif

/* throw **************************************************************************************************************/

#define SDeviceThrow(handle, exception) (                                                                              \
{                                                                                                                      \
   SDeviceCommonHandle *$handle = (SDeviceCommonHandle *)(handle);                                                     \
   $handle->Header.LatestStatus = (exception);                                                                         \
   Throw($handle);                                                                                                     \
})
void SDeviceProcessUnhandledThrow(CEXCEPTION_T _handle);

/**********************************************************************************************************************/
