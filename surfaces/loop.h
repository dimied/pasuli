#ifndef __PASULI_LOOP__
#define __PASULI_LOOP__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_LOOP != 0)
void Loop(double u, double v,
		  double *constants,
		  PaSuLiObject *pO);
#endif

#endif