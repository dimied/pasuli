#ifndef __PASULI_CUSTOM_COFIGURATION__
#define __PASULI_CUSTOM_COFIGURATION__
// For custom configuration
// E.g. disabling surfaces you don't need

// Disables all surfaces
#include "pasuli_conf/pasuli_cfg_no_use.h"

#undef USE_TORUS

#define USE_TORUS 1

#define USE_TORUS_MESH 1

#define USE_TORUS_SAMPLE 1

#ifdef USE_ANTISYMMETRIC_TORUS
#undef USE_ANTISYMMETRIC_TORUS
#endif

#define USE_ANTISYMMETRIC_TORUS 1
#define USE_ANTISYMMETRIC_TORUS_ARR 1

#endif