#ifndef __PASULI_PSEUDO_CROSS_CAP__
#define __PASULI_PSEUDO_CROSS_CAP__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PSEUDO_CROSS_CAP != 0)
void PseudoCrossCap(double u, double v,
					double *constants,
					PaSuLiObject *pO);
#endif

#endif