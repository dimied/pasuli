#ifndef __PASULI_SPRING1__
#define __PASULI_SPRING1__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SPRING1 != 0)
void Spring1(double u, double v,
			 double *constants,
			 PaSuLiObject *pO);
#endif

#endif