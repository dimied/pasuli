#ifndef __PASULI_BOYS_SURFACE__
#define __PASULI_BOYS_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BOYS_SURFACE != 0)
void BoysSurface(double u, double v,
                 double *constants, PaSuLiObject *pO);
#endif

#endif