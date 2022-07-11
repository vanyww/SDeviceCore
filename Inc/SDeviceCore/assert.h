#pragma once

#ifdef __SDEVICE_ASSERT
#define SDeviceAssert(expression) ((expression) ? (void)0U : SDeviceAssertFailed(__FILE__, __LINE__))
#define SDeviceEvalAssert(expression) SDeviceAssert(expression)
void SDeviceAssertFailed(char *, int);
#else
#define SDeviceAssert(expression) ((void)0U)
#define SDeviceEvalAssert(expression) expression
#endif

#ifdef __SDEVICE_RUNTIME_ERROR
#define SDeviceRuntimeErrorRaised(handle, error) (                                                                     \
{                                                                                                                      \
   __typeof__(handle) __handle = (handle);                                                                             \
   ((SDeviceCommonHandle *)__handle)->Header.LastError = error;                                                        \
   SDeviceProcessRuntimeError(__handle);                                                                               \
})
void SDeviceProcessRuntimeError(void *);
#else
#define SDeviceRuntimeErrorRaised(handle, error) ((SDeviceCommonHandle *)(handle))->Header.LastError = error
#endif
