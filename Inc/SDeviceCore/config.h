#pragma once

#include <stddef.h>
#include <stdbool.h>

#ifndef SDEVICE_CORE_USE_EXTERNAL_CONFIG
   #define SDEVICE_CORE_USE_EXTERNAL_CONFIG false
#endif

#if SDEVICE_CORE_USE_EXTERNAL_CONFIG
   #include "sdevice_core_config.h"
#endif

#ifndef SDEVICE_USE_ASSERT
   #define SDEVICE_USE_ASSERT true
#endif

#ifndef SDEVICE_USE_SIMPLE_ASSERT
   #define SDEVICE_USE_SIMPLE_ASSERT true
#endif
