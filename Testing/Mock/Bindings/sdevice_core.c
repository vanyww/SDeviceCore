#include "sdevice_core.h"

#include "unity_fixture.h"

#include <stdlib.h>

#define ASSERT_FAIL_FORMAT "Assertion failure: file (%s) line (%d)."

static AssertFailHandler assert_fail_handler;

void * SDeviceAllocateMemory(size_t memory_size)
{
   return malloc(memory_size);
}

void SDeviceFreeMemory(void *memory)
{
   free(memory);
}

void * SDeviceAllocateHandle(
      size_t init_memory_size,
      size_t runtime_memory_size)
{
   SDeviceCommonHandle *handle =
         SDeviceAllocateMemory(
               sizeof(*handle));

   handle->Init =
         SDeviceAllocateMemory(
               init_memory_size);

   handle->Runtime =
         SDeviceAllocateMemory(
               runtime_memory_size);

   return handle;
}

void SDeviceFreeHandle(void *handle)
{
   SDeviceCommonHandle *_handle = handle;

   SDeviceFreeMemory(_handle->Runtime);
   SDeviceFreeMemory(_handle->Init);
   SDeviceFreeMemory(_handle);
}

void SetAssertFailHandler(AssertFailHandler handler)
{
   assert_fail_handler = handler;
}

void SDeviceProcessAssertFail(char *file, int line)
{
   if(assert_fail_handler)
   {
      assert_fail_handler();
   }
   else
   {
      char failure_message[snprintf(NULL, 0, ASSERT_FAIL_FORMAT, file, line) + 1];
      sprintf(failure_message, ASSERT_FAIL_FORMAT, file, line);

      TEST_FAIL_MESSAGE(failure_message);
   }
}
