#include "test.h"

#include "SDeviceCore/common.h"

bool TestCommonMaxMacro(void)
{
   int min = -10, max = 10;
   return __MAX(min, max) == max;
}

bool TestCommonMinMacro(void)
{
   int min = -10, max = 10;
   return __MIN(min, max) == min;
}

bool TestCommonSizeOfMember(void)
{
   typedef int TestType;
   struct TestStructure { TestType TestValue; };

   return __SIZEOF_MEMBER(struct TestStructure, TestValue) == sizeof(TestType);
}

bool TestCommonLengthOf(void)
{
   int TestArrayLength = 10;
   int TestArray[TestArrayLength];

   return __LENGTHOF(TestArray) == TestArrayLength;
}

