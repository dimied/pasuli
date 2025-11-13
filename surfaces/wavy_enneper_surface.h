#ifndef __PASULI_WAVY_ENNEPER_SURFACE__
#define __PASULI_WAVY_ENNEPER_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_WAVY_ENNEPER_SURFACE != 0)
void WavyEnneperSurface(pasuli_vartype u,
                        pasuli_vartype v,
                        pasuli_consttype *constants,
                        PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descWavyEnneperSurface)
#endif

#endif