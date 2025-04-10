#include "SDeviceCore/core.h"
#include "SDeviceCore/errors.h"

bool SDeviceCompareUuids(const SDeviceUuid *uuid_0, const SDeviceUuid *uuid_1)
{
   SDeviceAssert(uuid_0);
   SDeviceAssert(uuid_1);

   return uuid_0->Low == uuid_1->Low &&
         uuid_0->High == uuid_1->High;
}

bool SDeviceCompareVersions(const SDeviceVersion *version_0, const SDeviceVersion *version_1)
{
   SDeviceAssert(version_0);
   SDeviceAssert(version_1);

   return version_0->Major == version_1->Major &&
         version_0->Minor == version_1->Minor &&
         version_0->Patch == version_1->Patch;
}
