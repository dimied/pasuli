#ifndef __PASULI_VERRILL_SURFACE__
#define __PASULI_VERRILL_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_VERRILL_SURFACE != 0)
void VerrillSurface(double u, double v,
					double *constants,
					PaSuLiObject *pO);
#endif

#endif