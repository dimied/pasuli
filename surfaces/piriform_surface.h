#ifndef __PASULI_PIRIFORM_SURFACE__
#define __PASULI_PIRIFORM_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PIRIFORM_SURFACE != 0)
void PiriformSurface(double u, double v,
					  double *constants,
					  PaSuLiObject *pO);
#endif

#endif