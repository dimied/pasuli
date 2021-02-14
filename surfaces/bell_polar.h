#ifndef __PASULI_BELL_POLAR__
#define __PASULI_BELL_POLAR__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BELL_POLAR != 0)
void BellPolar(double u, double v,
               double *constants,
               PaSuLiObject *pO);
#endif

#endif