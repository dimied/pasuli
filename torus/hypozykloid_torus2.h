#ifndef __PASULI_HYPOZYKLOID_TORUS_2__
#define __PASULI_HYPOZYKLOID_TORUS_2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HYPOZYKLOID_TORUS_2 != 0)
void HypozykloidTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_TORUS != 0)
HEADER_DESC_PTR(descHypozykloidTorus2)
#endif

#endif