#ifndef __PASULI_BICORN_SURFACE__
#define __PASULI_BICORN_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BICORN_SURFACE != 0)
void BicornSurface(double u, double v,
                   double *constants,
                   PaSuLiObject *pO);
#endif

#endif