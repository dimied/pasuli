#ifndef __PASULI_GUIMARD_SURFACE__
#define __PASULI_GUIMARD_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_GUIMARD_SURFACE != 0)
void GuimardSurface(double u, double v,
					double *constants,
					PaSuLiObject *pO);
#endif

#endif