#ifndef __PASULI_KAPPA_SURFACE__
#define __PASULI_KAPPA_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_KAPPA_SURFACE != 0)
void KappaSurface(double u, double v,
					  double *constants,
					  PaSuLiObject *pO);
#endif

#endif