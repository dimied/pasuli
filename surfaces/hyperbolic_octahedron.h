#ifndef __PASULI_HYPERBOLIC_OCTAHEDRON__
#define __PASULI_HYPERBOLIC_OCTAHEDRON__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HYPERBOLIC_OCTAHEDRON != 0)
void HyperbolicOctahedron(double u, double v,
						  double *constants,
						  PaSuLiObject *pO);
#endif

#endif