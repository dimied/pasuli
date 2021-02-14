#ifndef __PASULI_EGG__
#define __PASULI_EGG__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_EGG != 0)
void Egg(double u, double v,
		 double *constants,
		 PaSuLiObject *pO);
#endif

#endif