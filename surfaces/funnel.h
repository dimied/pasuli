#ifndef __PASULI_FUNNEL__
#define __PASULI_FUNNEL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_FUNNEL != 0)
void Funnel(double u, double v,
            double *constants, PaSuLiObject *pO);
#endif

#endif