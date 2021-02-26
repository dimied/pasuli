#ifndef __PASULI_TWISTED_EIGHT_TORUS__
#define __PASULI_TWISTED_EIGHT_TORUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TWISTED_EIGHT_TORUS != 0)
void TwistedEightTorus(pasuli_vartype u,
                       pasuli_vartype v,
                       pasuli_consttype *constants,
                       PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descTwistedEightTorus)
#endif

#endif