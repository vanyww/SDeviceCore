#include "unity.h"

#include "SDeviceCore/common.h"

#include <stdbool.h>

void setUp(void) { }
void tearDown(void) { }

void test_MaxMacro(void)
{
   uint32_t fvalue = 0, svalue = UINT32_MAX;
   TEST_ASSERT_EQUAL_UINT32(__MAX(fvalue, svalue), svalue);
}

void test_MinMacro(void)
{
   uint32_t fvalue = 0, svalue = UINT32_MAX;
   TEST_ASSERT_EQUAL_UINT32(__MIN(fvalue, svalue), fvalue);
}

bool wasSDeviceAssertFailedCalled;

void test_SDeviceAssertMacroPass(void)
{
   wasSDeviceAssertFailedCalled = false;
   SDeviceAssert(true);
   TEST_ASSERT_FALSE(wasSDeviceAssertFailedCalled);
}

void test_SDeviceAssertMacroFail(void)
{
   wasSDeviceAssertFailedCalled = false;
   SDeviceAssert(false);
   TEST_ASSERT_TRUE(wasSDeviceAssertFailedCalled);
}

void SDeviceAssertFailed(char *file, int line)
{
   wasSDeviceAssertFailedCalled = true;
}
