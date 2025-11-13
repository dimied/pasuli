#ifndef __PASULI_ENNEPER_SURFACE2__
#define __PASULI_ENNEPER_SURFACE2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_ENNEPER_SURFACE2 != 0)
void EnneperSurface2(pasuli_vartype u,
                     pasuli_vartype v,
                     pasuli_consttype *constants,
                     PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descEnneperSurface2)
#endif

#endif