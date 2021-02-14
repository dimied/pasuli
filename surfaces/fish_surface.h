#ifndef __PASULI_FISH_SURFACE__
#define __PASULI_FISH_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_FISH_SURFACE != 0)
void FishSurface(double u, double v,
				 double *constants,
				 PaSuLiObject *pO);
#endif

#endif