#ifndef __PASULI_TRIAXIAL_HEXATORUS__
#define __PASULI_TRIAXIAL_HEXATORUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRIAXIAL_HEXATORUS != 0)
void TriaxialHexatorus(pasuli_vartype u, pasuli_vartype v,
                       pasuli_consttype *constants,
                       PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descTriaxialHexatorus)
#endif

#endif