#ifndef __PASULI_HORN__
#define __PASULI_HORN__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HORN != 0)
void Horn(double u, double v,
		  double *constants,
		  PaSuLiObject *pO);
#endif

#endif