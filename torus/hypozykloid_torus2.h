#ifndef __PASULI_HYPOZYKLOID_TORUS_2__
#define __PASULI_HYPOZYKLOID_TORUS_2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descHypozykloidTorus2;

#if (USE_HYPOZYKLOID_TORUS_2 != 0)
void HypozykloidTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif