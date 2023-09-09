#include "SDeviceCore/common.h"

#include "unity_fixture.h"

TEST_GROUP(Common);

TEST_SETUP(Common) { }
TEST_TEAR_DOWN(Common) { }

TEST(Common, MIN)
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
      uint8_t  Unused;
      TestType TestValue;
   } TestStructure;

   TEST_ASSERT_EQUAL(sizeof(TestType), SIZEOF_MEMBER(TestStructure, TestValue));
}

TEST(Common, BIT_SIZEOF)
{
   typedef float TestType;

   int bit_size = sizeof(TestType) * CHAR_BIT;

   TEST_ASSERT_EQUAL(bit_size, BIT_SIZEOF(TestType));
}

TEST(Common, BIT_SIZEOF_MEMBER)
{
   typedef float TestType;
   typedef struct
   {  
      uint8_t Unused;
      TestType TestValue;
   } TestStructure;

   int bit_size = BIT_SIZEOF(TestType);

   TEST_ASSERT_EQUAL(bit_size, BIT_SIZEOF_MEMBER(TestStructure, TestValue));
}

TEST(Common, LENGTHOF)
{
   const int length = 15;
   int testArray[length];

   TEST_ASSERT_EQUAL(length, LENGTHOF(testArray));
}

TEST(Common, SET_BITS)
{
   int testValue   = 0b1111001100111;
   int bits        = 0b0000110011000;
   int resultValue = 0b1111111111111;

   TEST_ASSERT_EQUAL(resultValue, SET_BITS(testValue, bits));
}

TEST(Common, CLEAR_BITS)
{
   int testValue   = 0b1111111111111;
   int bits        = 0b0000110011000;
   int resultValue = 0b1111001100111;

   TEST_ASSERT_EQUAL(resultValue, CLEAR_BITS(testValue,bits));
}

TEST(Common, READ_BITS)
{
   int testValue   = 0b1111001111111;
   int bits        = 0b0100110011000;
   int resultValue = 0b0100000011000;

   TEST_ASSERT_EQUAL(resultValue, READ_BITS(testValue, bits));
}

TEST(Common, WILL_INT_ADD_OVERFLOW)
{
   int minInt = INT_MIN;
   int maxInt = INT_MAX;

   TEST_ASSERT(WILL_INT_ADD_OVERFLOW(maxInt, maxInt));
   TEST_ASSERT(!WILL_INT_ADD_OVERFLOW(minInt, maxInt));
}

TEST(Common, WILL_INT_SUB_OVERFLOW)
{
   int minInt = INT_MIN;
   int maxInt = INT_MAX;

   TEST_ASSERT(WILL_INT_SUB_OVERFLOW(minInt, maxInt));
   TEST_ASSERT(!WILL_INT_SUB_OVERFLOW(maxInt, maxInt));
}

TEST(Common, WILL_INT_MUL_OVERFLOW)
{
   int maxInt = INT_MAX;

   TEST_ASSERT(WILL_INT_MUL_OVERFLOW(maxInt, maxInt));
   TEST_ASSERT(!WILL_INT_SUB_OVERFLOW(maxInt, 0));
}

TEST(Common, TRY_ADD_INT_CHECKED)
{
   int minInt = INT_MIN;
   int maxInt = INT_MAX;
   int result;

   TEST_ASSERT(TRY_ADD_INT_CHECKED(maxInt, minInt, &result));
   TEST_ASSERT_EQUAL(-1, result);
   TEST_ASSERT(!TRY_ADD_INT_CHECKED(maxInt, maxInt, &result));
}

TEST(Common, TRY_SUB_INT_CHECKED)
{
   int minInt = INT_MIN;
   int maxInt = INT_MAX;
   int result;

   TEST_ASSERT(TRY_SUB_INT_CHECKED(maxInt, maxInt, &result));
   TEST_ASSERT_EQUAL(0, result);
   TEST_ASSERT(!TRY_SUB_INT_CHECKED(minInt, maxInt, &result));
}

TEST(Common, TRY_MUL_INT_CHECKED)
{
   int maxInt = INT_MAX;
   int result;

   TEST_ASSERT(TRY_MUL_INT_CHECKED(maxInt, 0, &result));
   TEST_ASSERT_EQUAL(0, result);
   TEST_ASSERT(!TRY_MUL_INT_CHECKED(maxInt, maxInt, &result));
}

TEST(Common, HAS_VALUE_UNSIGNED_TYPE)
{
   int signedIntValue = 0;
   unsigned int unsignedIntValue = 0;

   TEST_ASSERT(HAS_VALUE_UNSIGNED_TYPE(unsignedIntValue));
   TEST_ASSERT(!HAS_VALUE_UNSIGNED_TYPE(signedIntValue));
}

TEST(Common, HAS_VALUE_SIGNED_TYPE)
{
   int signedIntValue = 0;
   unsigned int unsignedIntValue = 0;

   TEST_ASSERT(HAS_VALUE_SIGNED_TYPE(signedIntValue));
   TEST_ASSERT(!HAS_VALUE_SIGNED_TYPE(unsignedIntValue));
}

TEST(Common, CEIL_UINT_DIV)
{
   unsigned int divisor = 2;
   unsigned int divident = 5;

   TEST_ASSERT_EQUAL(3, CEIL_UINT_DIV(divident, divisor));

   divisor = divident;
   TEST_ASSERT_EQUAL(1, CEIL_UINT_DIV(divident, divisor));
}

TEST_GROUP_RUNNER(Common)
{
   RUN_TEST_CASE(Common, MIN);
   RUN_TEST_CASE(Common, MAX);
   RUN_TEST_CASE(Common, SIZEOF_MEMBER);
   RUN_TEST_CASE(Common, BIT_SIZEOF);
   RUN_TEST_CASE(Common, BIT_SIZEOF_MEMBER);
   RUN_TEST_CASE(Common, LENGTHOF);
   RUN_TEST_CASE(Common, CLEAR_BITS);
   RUN_TEST_CASE(Common, READ_BITS);
   RUN_TEST_CASE(Common, SET_BITS);
   RUN_TEST_CASE(Common, WILL_INT_ADD_OVERFLOW);
   RUN_TEST_CASE(Common, WILL_INT_SUB_OVERFLOW);
   RUN_TEST_CASE(Common, WILL_INT_MUL_OVERFLOW);
   RUN_TEST_CASE(Common, TRY_ADD_INT_CHECKED);
   RUN_TEST_CASE(Common, TRY_SUB_INT_CHECKED);
   RUN_TEST_CASE(Common, TRY_MUL_INT_CHECKED);
   RUN_TEST_CASE(Common, HAS_VALUE_UNSIGNED_TYPE);
   RUN_TEST_CASE(Common, HAS_VALUE_SIGNED_TYPE);
   RUN_TEST_CASE(Common, CEIL_UINT_DIV);
}
