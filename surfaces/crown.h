#ifndef __PASULI_CROWN__
#define __PASULI_CROWN__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CROWN != 0)
void Crown(double u, double v,
		   double *constants,
		   PaSuLiObject *pO);
#endif

#endif