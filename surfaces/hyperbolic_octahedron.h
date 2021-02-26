#ifndef __PASULI_HYPERBOLIC_OCTAHEDRON__
#define __PASULI_HYPERBOLIC_OCTAHEDRON__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HYPERBOLIC_OCTAHEDRON != 0)
void HyperbolicOctahedron(pasuli_vartype u, pasuli_vartype v,
						  pasuli_consttype *constants,
						  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descHyperbolicOctahedron)
#endif

#endif