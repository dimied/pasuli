#ifndef __PASULI_TRASHCAN__
#define __PASULI_TRASHCAN__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRASHCAN != 0)
void Trashcan(double u, double v,
			  double *constants,
			  PaSuLiObject *pO);
#endif

#endif