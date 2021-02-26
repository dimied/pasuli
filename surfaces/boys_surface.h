#ifndef __PASULI_BOYS_SURFACE__
#define __PASULI_BOYS_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BOYS_SURFACE != 0)
void BoysSurface(pasuli_vartype u, pasuli_vartype v,
                 pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descBoysSurface)
#endif

#endif