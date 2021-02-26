#ifndef __PASULI_EPITROCHOIDAL_SURFACE__
#define __PASULI_EPITROCHOIDAL_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_EPITROCHOIDAL_SURFACE != 0)
void EpitrochoidalSurface(pasuli_vartype u,
                          pasuli_vartype v,
                          pasuli_consttype *constants,
                          PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descEpitrochoidalSurface)
#endif

#endif