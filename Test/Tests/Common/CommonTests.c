#include "unity_fixture.h"
#include "SDeviceCore/common.h"

TEST_GROUP(Common);

TEST_SETUP(Common)
{
}
TEST_TEAR_DOWN(Common)
{
}

TEST(Common,MIN)
{
   int min = -100;
   int max = 1000;

   TEST_ASSERT_EQUAL(min, MIN(min, max));
}

TEST(Common, MAX)
{
   int min = -100;
   int max = 1000;

   TEST_ASSERT_EQUAL(max, MAX(min, max));
}

TEST(Common, SIZEOF_MEMBER)
{
   typedef int TestType;
   typedef struct
   {
      TestType testValue;
   } TestStructure;

   TEST_ASSERT_EQUAL(sizeof(TestType), SIZEOF_MEMBER(TestStructure, testValue));
}

TEST(Common, BIT_SIZEOF)
{
   typedef float TestType;
   int bit_size = 4 * CHAR_BIT;

   TEST_ASSERT_EQUAL(bit_size, BIT_SIZEOF(TestType));
}

TEST(Common, BIT_SIZEOF_MEMBER)
{
   typedef float TestType;
   typedef struct
   {
      TestType testValue;
   } TestStructure;
   int bit_size = 4 * CHAR_BIT;

   TEST_ASSERT_EQUAL(bit_size, BIT_SIZEOF_MEMBER(TestStructure,testValue));
}

TEST(Common, LENGTHOF)
{
   int length = 15;
   int testArray[length];

   TEST_ASSERT_EQUAL(length, LENGTHOF(testArray));
}

TEST(Common,SET_BITS)
{
   int testValue =   0b1111001100111;
   int bits =        0b0000110011000;
   int resultValue = 0b1111111111111;

   TEST_ASSERT_EQUAL(resultValue, SET_BITS(testValue, bits));
}

TEST(Common,CLEAR_BITS)
{
   int testValue =   0b1111111111111;
   int bits =        0b0000110011000;
   int resultValue = 0b1111001100111;

   TEST_ASSERT_EQUAL(resultValue, CLEAR_BITS(testValue,bits));
}

TEST(Common,READ_BITS)
{
   int testValue =   0b1111001111111;
   int bits =        0b0100110011000;
   int resultValue = 0b0100000011000;

   TEST_ASSERT_EQUAL(resultValue, READ_BITS(testValue, bits));
}
