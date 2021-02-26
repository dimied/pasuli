#ifndef __PASULI_BOURS_MINIMAL_SURFACE__
#define __PASULI_BOURS_MINIMAL_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BOURS_MINIMAL_SURFACE != 0)
void BoursMinimalSurface(pasuli_vartype u, pasuli_vartype v,
               pasuli_consttype *constants,
               PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descBoursMinimalSurface)
#endif

#endif