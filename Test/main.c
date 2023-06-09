#include "unity_fixture.h"

static void
RunAllTests (void)
{
   RUN_TEST_GROUP(Common);
   RUN_TEST_GROUP(Weak);
}

int
main (int argc, char const *argv[])
{
   UnityMain (argc, argv, RunAllTests);
   return 0;
}
