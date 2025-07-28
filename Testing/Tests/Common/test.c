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
   int testValue = 0b0000000000000;
   int bits      = 0b0000110011000;

   TEST_ASSERT_BITS_HIGH(bits, SET_BITS(testValue, bits));
}

TEST(Common, CLEAR_BITS)
{
   int testValue = 0b1111111111111;
   int bits      = 0b0000110011000;

   TEST_ASSERT_BITS_LOW(bits, CLEAR_BITS(testValue, bits));
}

TEST(Common, READ_BITS)
{
   int testValue = 0b1111001111111;
   int bits      = 0b0100110011000;
   int result    = 0b0100000011000;

   TEST_ASSERT_BITS(bits, result, READ_BITS(testValue, bits));
}

TEST(Common, WILL_ADD_INT_OVERFLOW)
{
   int minInt = INT_MIN;
   int maxInt = INT_MAX;

   TEST_ASSERT(WILL_ADD_INT_OVERFLOW(maxInt, maxInt, int));
   TEST_ASSERT(!WILL_ADD_INT_OVERFLOW(minInt, maxInt, int));
}

TEST(Common, WILL_SUB_INT_OVERFLOW)
{
   int minInt = INT_MIN;
   int maxInt = INT_MAX;

   TEST_ASSERT(WILL_SUB_INT_OVERFLOW(minInt, maxInt, int));
   TEST_ASSERT(!WILL_SUB_INT_OVERFLOW(maxInt, maxInt, int));
}

TEST(Common, WILL_MUL_INT_OVERFLOW)
{
   int maxInt = INT_MAX;

   TEST_ASSERT(WILL_MUL_INT_OVERFLOW(maxInt, maxInt, int));
   TEST_ASSERT(!WILL_SUB_INT_OVERFLOW(maxInt, 0, int));
}

TEST(Common, ADD_INT_CHECKED)
{
   int minInt = INT_MIN;
   int maxInt = INT_MAX;
   int result;

   TEST_ASSERT(ADD_INT_CHECKED(maxInt, minInt, &result));
   TEST_ASSERT_EQUAL(-1, result);
   TEST_ASSERT(!ADD_INT_CHECKED(maxInt, maxInt, &result));
}

TEST(Common, SUB_INT_CHECKED)
{
   int minInt = INT_MIN;
   int maxInt = INT_MAX;
   int result;

   TEST_ASSERT(SUB_INT_CHECKED(maxInt, maxInt, &result));
   TEST_ASSERT_EQUAL(0, result);
   TEST_ASSERT(!SUB_INT_CHECKED(minInt, maxInt, &result));
}

TEST(Common, MUL_INT_CHECKED)
{
   int maxInt = INT_MAX;
   int result;

   TEST_ASSERT(MUL_INT_CHECKED(maxInt, 0, &result));
   TEST_ASSERT_EQUAL(0, result);
   TEST_ASSERT(!MUL_INT_CHECKED(maxInt, maxInt, &result));
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
   RUN_TEST_CASE(Common, WILL_ADD_INT_OVERFLOW);
   RUN_TEST_CASE(Common, WILL_SUB_INT_OVERFLOW);
   RUN_TEST_CASE(Common, WILL_MUL_INT_OVERFLOW);
   RUN_TEST_CASE(Common, ADD_INT_CHECKED);
   RUN_TEST_CASE(Common, SUB_INT_CHECKED);
   RUN_TEST_CASE(Common, MUL_INT_CHECKED);
   RUN_TEST_CASE(Common, HAS_VALUE_UNSIGNED_TYPE);
   RUN_TEST_CASE(Common, HAS_VALUE_SIGNED_TYPE);
   RUN_TEST_CASE(Common, CEIL_UINT_DIV);
}
