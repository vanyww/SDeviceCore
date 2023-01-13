#pragma once

#include <stddef.h>

/* cexception *********************************************************************************************************/

typedef const void * CExceptionType;

#define CEXCEPTION_NONE (NULL)
#define CEXCEPTION_T CExceptionType
#define CEXCEPTION_NO_CATCH_HANDLER(id) _SDeviceProcessUnhandledThrow(id)

#include "../../Submodules/cexception/lib/CException.h"

/* assertations *******************************************************************************************************/

#ifdef __SDEVICE_USE_ASSERT
#ifdef __SDEVICE_USE_SIMPLE_ASSERT
#define SDeviceAssert(expression) ((expression) ? (void)0U : _SDeviceProcessAssertFail())
void _SDeviceProcessAssertFail(void);
#else
#define SDeviceAssert(expression) ((expression) ? (void)0U : _SDeviceProcessAssertFail(__FILE__, __LINE__))
void _SDeviceProcessAssertFail(char *file, int line);
#endif
#define SDeviceEvalAssert(expression) SDeviceAssert(expression)
#else
#define SDeviceAssert(expression) ((void)0U)
#define SDeviceEvalAssert(expression) expression
#endif

#ifdef __SDEVICE_USE_DEBUG_ASSERT
#ifdef __SDEVICE_USE_SIMPLE_ASSERT
#define SDeviceDebugAssert(expression) ((expression) ? (void)0U : _SDeviceProcessAssertFail())
void _SDeviceProcessAssertFail(void);
#else
#define SDeviceDebugAssert(expression) ((expression) ? (void)0U : _SDeviceProcessAssertFail(__FILE__, __LINE__))
void _SDeviceProcessAssertFail(char *file, int line);
#endif
#define SDeviceDebugEvalAssert(expression) SDeviceAssert(expression)
#else
#define SDeviceDebugAssert(expression) ((void)0U)
#define SDeviceDebugEvalAssert(expression) expression
#endif

/* logging ************************************************************************************************************/

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

/* throw **************************************************************************************************************/

#define SDeviceThrow(handle, exception) (                                                                              \
{                                                                                                                      \
   SDeviceCommonHandle *__handle = (SDeviceCommonHandle *)(handle);                                                    \
   __handle->Header.LatestStatus = (exception);                                                                        \
   Throw(__handle);                                                                                                    \
})
void _SDeviceProcessUnhandledThrow(CEXCEPTION_T _handle);

/**********************************************************************************************************************/
