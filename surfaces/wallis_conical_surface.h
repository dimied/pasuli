#ifndef __PASULI_WALLIS_CONICAL_SURFACE__
#define __PASULI_WALLIS_CONICAL_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_WALLIS_CONICAL_SURFACE != 0)
void WallisConicalSurface(double u, double v,
                          double *constants,
                          PaSuLiObject *pO);
#endif

#endif