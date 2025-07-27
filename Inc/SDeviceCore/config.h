#pragma once

#include <stddef.h>
#include <stdbool.h>

#if !defined(SDEVICE_CORE_USE_EXTERNAL_CONFIG) || defined(DOXYGEN)
   #define SDEVICE_CORE_USE_EXTERNAL_CONFIG false
#endif

#if SDEVICE_CORE_USE_EXTERNAL_CONFIG
   #include "sdevice_core_config.h"
#endif

#if !defined(SDEVICE_USE_ASSERT) || defined(DOXYGEN)
   #define SDEVICE_USE_ASSERT true
#endif

#if !defined(SDEVICE_USE_SIMPLE_ASSERT) || defined(DOXYGEN)
   #define SDEVICE_USE_SIMPLE_ASSERT true
#endif
