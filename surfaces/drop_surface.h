#ifndef __PASULI_DROP_SURFACE__
#define __PASULI_DROP_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_DROP_SURFACE != 0)
void DropSurface(double u, double v,
				 double *constants,
				 PaSuLiObject *pO);
#endif

#endif