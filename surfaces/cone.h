#ifndef __PASULI_CONE__
#define __PASULI_CONE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CONE != 0)
void Cone(double u, double v,
		  double *constants,
		  PaSuLiObject *pO);
#endif

#endif