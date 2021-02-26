#ifndef __PASULI_HORNLET_SURFACE__
#define __PASULI_HORNLET_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HORNLET_SURFACE != 0)
void HornletSurface(pasuli_vartype u,
                    pasuli_vartype v,
                    pasuli_consttype *constants,
                    PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descHornletSurface)
#endif

#endif