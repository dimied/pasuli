#ifndef __PASULI_HYPERBOLIC_OCTAHEDRON__
#define __PASULI_HYPERBOLIC_OCTAHEDRON__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HYPERBOLIC_OCTAHEDRON != 0)
void HyperbolicOctahedron(pasuli_vartype u, pasuli_vartype v,
						  pasuli_consttype *constants,
						  PaSuLiObject *pO);
#endif

#endif