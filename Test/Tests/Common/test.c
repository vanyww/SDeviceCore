#include "test.h"

#include "SDeviceCore/common.h"

#include <stdint.h>

bool TestCommonMaxMacro(void)
{
   int min = -10, max = 10;
   return MAX(min, max) == max;
}

bool TestCommonMinMacro(void)
{
   int min = -10, max = 10;
   return MIN(min, max) == min;
}

bool TestCommonSizeOfMember(void)
{
   typedef int TestType;
   struct TestStructure { TestType TestValue; };

   return SIZEOF_MEMBER(struct TestStructure, TestValue) == sizeof(TestType);
}

bool TestCommonLengthOf(void)
{
   int TestArrayLength = 10;
   int TestArray[TestArrayLength];

   return LENGTHOF(TestArray) == TestArrayLength;
}

bool TestBitSizeof(void)
{
   uint32_t TestValue;

   return BIT_SIZEOF(TestValue) == 4 * CHAR_BIT;
}

bool TestCommonBitSizeOfMember(void)
{
   typedef int TestType;
   struct TestStructure { TestType TestValue; };

   return BIT_SIZEOF_MEMBER(struct TestStructure, TestValue) == sizeof(TestType) * CHAR_BIT;
}

