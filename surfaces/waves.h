#ifndef __PASULI_WAVES__
#define __PASULI_WAVES__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_WAVES != 0)
void Waves(double u, double v,
           double *constants,
           PaSuLiObject *pO);
#endif

#endif