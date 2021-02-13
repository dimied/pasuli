#ifndef __PASULI_JET_SURFACE__
#define __PASULI_JET_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_JET_SURFACE != 0)
void JetSurface(double u, double v,
                double *constants,
                PaSuLiObject *pO);
#endif

#endif