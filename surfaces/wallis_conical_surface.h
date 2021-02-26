#ifndef __PASULI_WALLIS_CONICAL_SURFACE__
#define __PASULI_WALLIS_CONICAL_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_WALLIS_CONICAL_SURFACE != 0)
void WallisConicalSurface(pasuli_vartype u, pasuli_vartype v,
                          pasuli_consttype *constants,
                          PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descWallisConicalSurface)
#endif

#endif