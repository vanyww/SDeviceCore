#pragma once

#include <stddef.h>
#include <stdbool.h>

#ifndef SDEVICE_CORE_USE_EXTERNAL_CONFIG
   #define SDEVICE_CORE_USE_EXTERNAL_CONFIG false
#endif /* SDEVICE_CORE_USE_EXTERNAL_CONFIG */

#if SDEVICE_CORE_USE_EXTERNAL_CONFIG
   #include "sdevice_core_config.h"
#endif /* SDEVICE_CORE_USE_EXTERNAL_CONFIG */

#ifndef SDEVICE_USE_ASSERT
   #define SDEVICE_USE_ASSERT true
#endif /* SDEVICE_USE_ASSERT */

#ifndef SDEVICE_USE_SIMPLE_ASSERT
   #define SDEVICE_USE_SIMPLE_ASSERT true
#endif /* SDEVICE_USE_SIMPLE_ASSERT */
