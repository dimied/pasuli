#ifndef __PASULI_STILETTO_SURFACE__
#define __PASULI_STILETTO_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_STILETTO_SURFACE != 0)
void StilettoSurface(double u, double v,
					 double *constants,
					 PaSuLiObject *pO);
#endif

#endif