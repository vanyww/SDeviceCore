#include "unity_fixture.h"

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
}

TEST_GROUP_RUNNER(SDeviceCore)
{
   RUN_TEST_CASE(SDeviceCore, HandleInitialization);
   RUN_TEST_CASE(SDeviceCore, HandleProperty);
   RUN_TEST_CASE(SDeviceCore, HandlePartialProperty);
}

TEST_GROUP_RUNNER(Weak)
{
   RUN_TEST_CASE(Weak, SDeviceAssert);
   RUN_TEST_CASE(Weak, SDeviceHandledThrow);
   RUN_TEST_CASE(Weak, SDeviceUnhandledThrow);
   RUN_TEST_CASE(Weak, SDeviceLogStatus);
}
