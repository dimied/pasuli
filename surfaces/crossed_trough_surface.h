#ifndef __PASULI_CROSSED_TROUGH_SURFACE__
#define __PASULI_CROSSED_TROUGH_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CROSSED_TROUGH_SURFACE != 0)
void CrossedTroughSurface(pasuli_vartype u,
                          pasuli_vartype v,
                          pasuli_consttype *constants,
                          PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descCrossedTroughSurface)
#endif

#endif