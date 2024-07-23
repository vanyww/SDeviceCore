#include "SDeviceCore/core.h"
#include "SDeviceCore/errors.h"

bool SDeviceCompareUuids(const SDeviceUuid *uuid$0, const SDeviceUuid *uuid$1)
{
   SDeviceAssert(uuid$0);
   SDeviceAssert(uuid$1);

   return uuid$0->Low == uuid$1->Low &&
         uuid$0->High == uuid$1->High;
}

bool SDeviceCompareVersions(const SDeviceVersion *version$0, const SDeviceVersion *version$1)
{
   SDeviceAssert(version$0);
   SDeviceAssert(version$1);

   return version$0->Major == version$1->Major &&
         version$0->Minor == version$1->Minor &&
         version$0->Patch == version$1->Patch;
}

bool SDeviceCompareIdentityBlocks(const SDeviceIdentityBlock *identity$0, const SDeviceIdentityBlock *identity$1)
{
   SDeviceAssert(identity$0);
   SDeviceAssert(identity$1);

   return SDeviceCompareUuids(&identity$0->Uuid, &identity$1->Uuid) &&
         SDeviceCompareVersions(&identity$0->Version, &identity$1->Version);
}
