#ifndef __PASULI_SHOE_SURFACE__
#define __PASULI_SHOE_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SHOE_SURFACE != 0)
void ShoeSurface(double u, double v,
                 double *constants, PaSuLiObject *pO);
#endif

#endif