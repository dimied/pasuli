#ifndef __PASULI_SINE_SURFACE__
#define __PASULI_SINE_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SINE_SURFACE != 0)
void SineSurface(double u, double v,
                 double *constants, PaSuLiObject *pO);
#endif

#endif