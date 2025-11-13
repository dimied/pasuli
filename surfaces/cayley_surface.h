#ifndef __PASULI_CAYLEY_SURFACE__
#define __PASULI_CAYLEY_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CAYLEY_SURFACE != 0)
void CayleySurface(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descCayleySurface)
#endif
#endif