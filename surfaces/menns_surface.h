#ifndef __PASULI_MENNS_SURFACE__
#define __PASULI_MENNS_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_MENNS_SURFACE != 0)
void MennsSurface(double u, double v,
				  double *constants,
				  PaSuLiObject *pO);
#endif

#endif