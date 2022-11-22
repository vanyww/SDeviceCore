#include "SDeviceCore/common.h"
#include "Tests/Common/test.h"
#include "Tests/SDevice/test.h"

#include <stdio.h>
#include <string.h>

struct
{
   bool (*Function)(void);
   char *Description;
} TestFunctions[] =
{
   { TestCommonMaxMacro, "max macro" },
   { TestCommonMinMacro, "min macro" },
   { TestCommonSizeOfMember, "sizeofmember macro" },
   { TestCommonLengthOf, "lengthof macro" },
   { TestBitSizeof, "bit sizeof macro" },
   { TestCommonBitSizeOfMember, "bitsizeofmember macro" },


   { TestSDeviceHandleInitialization, "sdevice handle initialization" },
   { TestSDeviceHandleProperty, "sdevice handle property" },
   { TestSDeviceHandlePartialProperty, "sdevice handle partial property" },

   { TestSDeviceHandledThrow, "sdevice handled throw" },
   { TestSDeviceUnhandledThrow, "sdevice unhandled throw" },
   { TestSDeviceLogStatus, "sdevice log status" },
   { TestSDeviceAssert, "sdevice assert" },
};

const size_t TestFunctionsCount = __LENGTHOF(TestFunctions);

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
