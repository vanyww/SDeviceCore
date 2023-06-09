#include "unity_fixture.h"

static void
RunAllTests (void)
{
   RUN_TEST_GROUP(Common);
}

int
main (int argc, char const *argv[])
{
   UnityMain (argc, argv, RunAllTests);
   return 0;
}
