#include "SDeviceCore/core.h"
#include "SDeviceCore/errors.h"

bool SDeviceCompareUuids(const SDeviceUuid *uuid_0, const SDeviceUuid *uuid_1)
{
   SDeviceAssert(uuid_0 != NULL);
   SDeviceAssert(uuid_1 != NULL);

   return uuid_0->Low == uuid_1->Low &&
         uuid_0->High == uuid_1->High;
}

bool SDeviceCompareVersions(const SDeviceVersion *version_0, const SDeviceVersion *version_1)
{
   SDeviceAssert(version_0 != NULL);
   SDeviceAssert(version_1 != NULL);

   return version_0->Major == version_1->Major &&
         version_0->Minor == version_1->Minor &&
         version_0->Patch == version_1->Patch;
}

bool SDeviceCompareIdentityBlocks(const SDeviceIdentityBlock *identity_0, const SDeviceIdentityBlock *identity_1)
{
   SDeviceAssert(identity_0 != NULL);
   SDeviceAssert(identity_1 != NULL);

   return SDeviceCompareUuids(&identity_0->Uuid, &identity_1->Uuid) &&
         SDeviceCompareVersions(&identity_0->Version, &identity_1->Version);
}
