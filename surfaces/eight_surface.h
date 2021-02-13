#ifndef __PASULI_EIGHT_SURFACE__
#define __PASULI_EIGHT_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_EIGHT_SURFACE != 0)
void EightSurface(double u, double v,
                  double *constants,
                  PaSuLiObject *pO);
#endif

#endif