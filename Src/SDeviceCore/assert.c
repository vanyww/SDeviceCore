#include "SDeviceCore/assert.h"
#include "SDeviceCore/common.h"

__attribute__((weak))
#if SDEVICE_USE_SIMPLE_ASSERT
void SDeviceProcessAssertFail(void)
#else /* SDEVICE_USE_SIMPLE_ASSERT */
void SDeviceProcessAssertFail(char *file, int line)
#endif /* SDEVICE_USE_SIMPLE_ASSERT */
{
#if not SDEVICE_USE_SIMPLE_ASSERT
   UNUSED_PARAMETER(file);
   UNUSED_PARAMETER(line);
#endif /* not SDEVICE_USE_SIMPLE_ASSERT */

   for(;;);
}
