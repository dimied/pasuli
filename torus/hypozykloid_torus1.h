#ifndef __PASULI_HYPOZYKLOID_TORUS_1__
#define __PASULI_HYPOZYKLOID_TORUS_1__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descHypozykloidTorus1;

#if (USE_HYPOZYKLOID_TORUS_1 != 0)
void HypozykloidTorus1(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif