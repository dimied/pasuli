#ifndef __PASULI_HYPERBOLIC_PARABOLOID__
#define __PASULI_HYPERBOLIC_PARABOLOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HYPERBOLIC_PARABOLOID != 0)
void HyperbolicParaboloid(double u, double v,
						  double *constants,
						  PaSuLiObject *pO);
#endif

#endif