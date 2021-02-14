#ifndef __PASULI_ENNEPER_SURFACE_POLAR__
#define __PASULI_ENNEPER_SURFACE_POLAR__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_ENNEPER_SURFACE_POLAR != 0)
void EnneperSurfacePolar(double u, double v,
						 double *constants,
						 PaSuLiObject *pO);
#endif

#endif