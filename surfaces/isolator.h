#ifndef __PASULI_ISOLATOR__
#define __PASULI_ISOLATOR__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_ISOLATOR != 0)
void Isolator(double u, double v,
			  double *constants,
			  PaSuLiObject *pO);
#endif

#endif