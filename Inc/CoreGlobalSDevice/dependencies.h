/**
 * @file CoreGlobalSDevice/dependencies.h
 * @brief Зависимости глобального модуля.
 * @details Включения зависимостей глобального модуля и проверка их версий.
 */

#pragma once

#include "SDeviceCore/core.h"

#if (SDEVICE_CORE_VERSION_MAJOR != 8) || (SDEVICE_CORE_VERSION_MINOR < 0)
   #error SDevice core version is incorrect.
#endif
