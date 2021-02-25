#ifndef __PASULI_PLANAR_ENNEPER_SURFACE__
#define __PASULI_PLANAR_ENNEPER_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PLANAR_ENNEPER_SURFACE != 0)
void PlanarEnneperSurface(pasuli_vartype u,
                          pasuli_vartype v,
                          pasuli_consttype *constants,
                          PaSuLiObject *pO);
#endif

#endif