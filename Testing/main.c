#include "unity_fixture.h"

static void RunAllTests(void)
{
   RUN_TEST_GROUP(Common);
   RUN_TEST_GROUP(SDeviceCore_A);
   RUN_TEST_GROUP(SDeviceCore_B);
   RUN_TEST_GROUP(Assert);
}

int main(int argc, char const *argv[])
{
   UnityMain(argc, argv, RunAllTests);
   return 0;
}
