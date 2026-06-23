#include "SDeviceCore/common.h"

#include "unity_fixture.h"

TEST_GROUP(Common);

TEST_SETUP(Common) { }
TEST_TEAR_DOWN(Common) { }

TEST(Common, MIN)
{
   int min = -100;
   int max = +100;

   TEST_ASSERT_EQUAL_INT(min, MIN(min, max));
}

TEST(Common, MAX)
{
   int min = -100;
   int max = +100;

   TEST_ASSERT_EQUAL_INT(max, MAX(min, max));
}

TEST(Common, INSTANCE_OF)
{
   typedef struct
   {
      uint8_t  Unused;
      uint32_t Value;
   } TestStructure;

   TEST_ASSERT_EQUAL_size_t(sizeof(TestStructure), sizeof(*INSTANCE_OF(TestStructure)));
}

TEST(Common, SIZEOF_MEMBER)
{
   typedef int TestType;
   typedef struct
   {
      uint8_t  Unused;
      TestType TestValue;
   } TestStructure;

   TEST_ASSERT_EQUAL_size_t(sizeof(TestType), SIZEOF_MEMBER(TestStructure, TestValue));
}

TEST(Common, BIT_SIZEOF)
{
   typedef float TestType;

   TEST_ASSERT_EQUAL_size_t(sizeof(TestType) * CHAR_BIT, BIT_SIZEOF(TestType));
}

TEST(Common, BIT_SIZEOF_MEMBER)
{
   typedef float TestType;
   typedef struct
   {
      uint8_t Unused;
      TestType TestValue;
   } TestStructure;

   TEST_ASSERT_EQUAL_size_t(BIT_SIZEOF(TestType), BIT_SIZEOF_MEMBER(TestStructure, TestValue));
}

TEST(Common, LENGTHOF)
{
   size_t length = 15;
   int test_array[length];

   TEST_ASSERT_EQUAL_size_t(length, LENGTHOF(test_array));
}

TEST(Common, FIRST)
{
   int first_element = 10;
   int test_array[] = { first_element, 20, 30 };

   TEST_ASSERT_EQUAL_INT(first_element, FIRST(test_array));
}

TEST(Common, LAST)
{
   int last_element = 30;
   int test_array[] = { 10, 20, last_element };

   TEST_ASSERT_EQUAL_INT(last_element, LAST(test_array));
}

TEST(Common, SET_BITS)
{
   unsigned int test_value = 0b0000000000000;
   unsigned int bits       = 0b0000110011000;

   TEST_ASSERT_BITS_HIGH(bits, SET_BITS(test_value, bits));
}

TEST(Common, CLEAR_BITS)
{
   unsigned int test_value = 0b1111111111111;
   unsigned int bits       = 0b0000110011000;

   TEST_ASSERT_BITS_LOW(bits, CLEAR_BITS(test_value, bits));
}

TEST(Common, READ_BITS)
{
   unsigned int test_value = 0b1111001111111;
   unsigned int bits       = 0b0100110011000;
   unsigned int result     = 0b0100000011000;

   TEST_ASSERT_BITS(bits, result, READ_BITS(test_value, bits));
}

TEST(Common, WILL_ADD_INT_OVERFLOW)
{
   int min_int = INT_MIN;
   int max_int = INT_MAX;

   TEST_ASSERT_TRUE(WILL_ADD_INT_OVERFLOW(max_int, max_int, int));
   TEST_ASSERT_FALSE(WILL_ADD_INT_OVERFLOW(min_int, max_int, int));
   TEST_ASSERT_FALSE(WILL_ADD_INT_OVERFLOW(100, 200, int));
   TEST_ASSERT_FALSE(WILL_ADD_INT_OVERFLOW(-100, 200, int));
   TEST_ASSERT_FALSE(WILL_ADD_INT_OVERFLOW(100, -200, int));
   TEST_ASSERT_FALSE(WILL_ADD_INT_OVERFLOW(-100, -200, int));
}

TEST(Common, WILL_SUB_INT_OVERFLOW)
{
   int min_int = INT_MIN;
   int max_int = INT_MAX;

   TEST_ASSERT_TRUE(WILL_SUB_INT_OVERFLOW(min_int, max_int, int));
   TEST_ASSERT_FALSE(WILL_SUB_INT_OVERFLOW(max_int, max_int, int));
   TEST_ASSERT_FALSE(WILL_SUB_INT_OVERFLOW(100, 200, int));
   TEST_ASSERT_FALSE(WILL_SUB_INT_OVERFLOW(-100, 200, int));
   TEST_ASSERT_FALSE(WILL_SUB_INT_OVERFLOW(100, -200, int));
   TEST_ASSERT_FALSE(WILL_SUB_INT_OVERFLOW(-100, -200, int));
}

TEST(Common, WILL_MUL_INT_OVERFLOW)
{
   int max_int = INT_MAX;

   TEST_ASSERT_TRUE(WILL_MUL_INT_OVERFLOW(max_int, max_int, int));
   TEST_ASSERT_FALSE(WILL_MUL_INT_OVERFLOW(max_int, 0, int));
   TEST_ASSERT_FALSE(WILL_MUL_INT_OVERFLOW(100, 200, int));
   TEST_ASSERT_FALSE(WILL_MUL_INT_OVERFLOW(-100, 200, int));
   TEST_ASSERT_FALSE(WILL_MUL_INT_OVERFLOW(100, -200, int));
   TEST_ASSERT_FALSE(WILL_MUL_INT_OVERFLOW(-100, -200, int));
}

TEST(Common, ADD_INT_CHECKED)
{
   int min_int = INT_MIN;
   int max_int = INT_MAX;
   int result;

   TEST_ASSERT_FALSE(ADD_INT_CHECKED(max_int, max_int, &result));

   TEST_ASSERT_TRUE(ADD_INT_CHECKED(min_int, max_int, &result));
   TEST_ASSERT_EQUAL_INT(-1, result);

   TEST_ASSERT_TRUE(ADD_INT_CHECKED(100, 200, &result));
   TEST_ASSERT_EQUAL_INT(300, result);

   TEST_ASSERT_TRUE(ADD_INT_CHECKED(-100, 200, &result));
   TEST_ASSERT_EQUAL_INT(100, result);

   TEST_ASSERT_TRUE(ADD_INT_CHECKED(100, -200, &result));
   TEST_ASSERT_EQUAL_INT(-100, result);

   TEST_ASSERT_TRUE(ADD_INT_CHECKED(-100, -200, &result));
   TEST_ASSERT_EQUAL_INT(-300, result);
}

TEST(Common, SUB_INT_CHECKED)
{
   int min_int = INT_MIN;
   int max_int = INT_MAX;
   int result;

   TEST_ASSERT_FALSE(SUB_INT_CHECKED(min_int, max_int, &result));

   TEST_ASSERT_TRUE(SUB_INT_CHECKED(max_int, max_int, &result));
   TEST_ASSERT_EQUAL_INT(0, result);

   TEST_ASSERT_TRUE(SUB_INT_CHECKED(100, 200, &result));
   TEST_ASSERT_EQUAL_INT(-100, result);

   TEST_ASSERT_TRUE(SUB_INT_CHECKED(-100, 200, &result));
   TEST_ASSERT_EQUAL_INT(-300, result);

   TEST_ASSERT_TRUE(SUB_INT_CHECKED(100, -200, &result));
   TEST_ASSERT_EQUAL_INT(300, result);

   TEST_ASSERT_TRUE(SUB_INT_CHECKED(-100, -200, &result));
   TEST_ASSERT_EQUAL_INT(100, result);
}

TEST(Common, MUL_INT_CHECKED)
{
   int max_int = INT_MAX;
   int result;

   TEST_ASSERT_FALSE(MUL_INT_CHECKED(max_int, max_int, &result));

   TEST_ASSERT_TRUE(MUL_INT_CHECKED(max_int, 0, &result));
   TEST_ASSERT_EQUAL_INT(0, result);

   TEST_ASSERT_TRUE(MUL_INT_CHECKED(100, 200, &result));
   TEST_ASSERT_EQUAL_INT(20000, result);

   TEST_ASSERT_TRUE(MUL_INT_CHECKED(-100, 200, &result));
   TEST_ASSERT_EQUAL_INT(-20000, result);

   TEST_ASSERT_TRUE(MUL_INT_CHECKED(100, -200, &result));
   TEST_ASSERT_EQUAL_INT(-20000, result);

   TEST_ASSERT_TRUE(MUL_INT_CHECKED(-100, -200, &result));
   TEST_ASSERT_EQUAL_INT(20000, result);
}

TEST(Common, HAS_VALUE_UNSIGNED_TYPE)
{
   TEST_ASSERT_TRUE(HAS_VALUE_UNSIGNED_TYPE((unsigned int)0));
   TEST_ASSERT_FALSE(HAS_VALUE_UNSIGNED_TYPE((int)0));
}

TEST(Common, HAS_VALUE_SIGNED_TYPE)
{
   TEST_ASSERT_TRUE(HAS_VALUE_SIGNED_TYPE((int)0));
   TEST_ASSERT_FALSE(HAS_VALUE_SIGNED_TYPE((unsigned int)0));
}

TEST(Common, CEIL_UINT_DIV)
{
   TEST_ASSERT_EQUAL_UINT(3, CEIL_UINT_DIV(5u, 2u));
   TEST_ASSERT_EQUAL_UINT(2, CEIL_UINT_DIV(4u, 2u));
   TEST_ASSERT_EQUAL_UINT(5, CEIL_UINT_DIV(5u, 1u));
   TEST_ASSERT_EQUAL_UINT(1, CEIL_UINT_DIV(3u, 5u));
}

TEST(Common, SET_AS_VOLATILE)
{
   uint32_t target = 0;

   SET_AS_VOLATILE(target, 0xABCD1234);

   TEST_ASSERT_EQUAL_HEX32(0xABCD1234, target);
}

TEST(Common, GET_AS_VOLATILE)
{
   uint32_t target = 0xABCD1234;

   TEST_ASSERT_EQUAL_HEX32(0xABCD1234, GET_AS_VOLATILE(target));
}

TEST_GROUP_RUNNER(Common)
{
   RUN_TEST_CASE(Common, MIN);
   RUN_TEST_CASE(Common, MAX);
   RUN_TEST_CASE(Common, INSTANCE_OF);
   RUN_TEST_CASE(Common, SIZEOF_MEMBER);
   RUN_TEST_CASE(Common, BIT_SIZEOF);
   RUN_TEST_CASE(Common, BIT_SIZEOF_MEMBER);
   RUN_TEST_CASE(Common, LENGTHOF);
   RUN_TEST_CASE(Common, FIRST);
   RUN_TEST_CASE(Common, LAST);
   RUN_TEST_CASE(Common, SET_BITS);
   RUN_TEST_CASE(Common, CLEAR_BITS);
   RUN_TEST_CASE(Common, READ_BITS);
   RUN_TEST_CASE(Common, WILL_ADD_INT_OVERFLOW);
   RUN_TEST_CASE(Common, WILL_SUB_INT_OVERFLOW);
   RUN_TEST_CASE(Common, WILL_MUL_INT_OVERFLOW);
   RUN_TEST_CASE(Common, ADD_INT_CHECKED);
   RUN_TEST_CASE(Common, SUB_INT_CHECKED);
   RUN_TEST_CASE(Common, MUL_INT_CHECKED);
   RUN_TEST_CASE(Common, HAS_VALUE_UNSIGNED_TYPE);
   RUN_TEST_CASE(Common, HAS_VALUE_SIGNED_TYPE);
   RUN_TEST_CASE(Common, CEIL_UINT_DIV);
   RUN_TEST_CASE(Common, SET_AS_VOLATILE);
   RUN_TEST_CASE(Common, GET_AS_VOLATILE);
}
