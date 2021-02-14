#ifndef __PASULI_SINE_CONE__
#define __PASULI_SINE_CONE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SINE_CONE != 0)
void SineCone(double u, double v,
			  double *constants,
			  PaSuLiObject *pO);
#endif

#endif