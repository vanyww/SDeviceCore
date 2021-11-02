#include "Tests/Common/test_common.h"
#include "Tests/SDevice/test_sdevice.h"

#include <stdio.h>
#include <string.h>

struct
{
   bool (*Function)(void);
   char *Description;
} TestFunctions[] =
{
   { TestMaxMacro, "max macro" },
   { TestMinMacro, "min macro" },
   { TestSDeviceAssert, "SDevice assert" },
   { TestSDeviceRuntimeErrorProcess, "SDevice runtime error process" },
   { TestHandleInitialization, "handle initialization" },
   { TestHandleSettingSet, "setting set" }
};

const size_t TestFunctionsCount = sizeof(TestFunctions) / sizeof(*TestFunctions);

int main(void)
{
   int maxMessageLength = 0;
   for(size_t i = 0; i < TestFunctionsCount; i++)
   {
      int length = strlen(TestFunctions[i].Description);
      if(length > maxMessageLength)
         maxMessageLength = length;
   }

   printf("start tests...\n\n");

   for(size_t i = 0; i < TestFunctionsCount; i++)
      printf("%*s - %s\n",
             -maxMessageLength, TestFunctions[i].Description, TestFunctions[i].Function() == true ? "pass" : "fail");

   printf("\nstop tests...\n");
}
