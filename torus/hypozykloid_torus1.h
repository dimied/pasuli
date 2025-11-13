#ifndef __PASULI_HYPOZYKLOID_TORUS_1__
#define __PASULI_HYPOZYKLOID_TORUS_1__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HYPOZYKLOID_TORUS_1 != 0)
void HypozykloidTorus1(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_TORUS != 0)
HEADER_DESC_PTR(descHypozykloidTorus1)
#endif

#endif