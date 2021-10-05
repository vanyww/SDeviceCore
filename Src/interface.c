#include "../Inc/SDeviceCore/interface.h"

__attribute__((weak)) void SDeviceAssertFailed(char *file, int line)
{
   for(;;) { }
}
