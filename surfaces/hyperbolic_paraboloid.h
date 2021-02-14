#ifndef __PASULI_HYPERBOLIC_PARABOLOID__
#define __PASULI_HYPERBOLIC_PARABOLOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HYPERBOLIC_PARABOLOID != 0)
void HyperbolicParaboloid(pasuli_vartype u, pasuli_vartype v,
						  pasuli_consttype *constants,
						  PaSuLiObject *pO);
#endif

#endif