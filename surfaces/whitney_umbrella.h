#ifndef __PASULI_WHITNEY_UMBRELLA__
#define __PASULI_WHITNEY_UMBRELLA__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_WHITNEY_UMBRELLA != 0)
void WhitneyUmbrella(double u, double v,
                     double *constants, PaSuLiObject *pO);
#endif

#endif