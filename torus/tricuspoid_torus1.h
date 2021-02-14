#ifndef __PASULI_TRICUSPOID_TORUS_1__
#define __PASULI_TRICUSPOID_TORUS_1__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descTricuspoidTorus1;

#if (USE_TRICUSPOID_TORUS_1 != 0)
void TricuspoidTorus1(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO);
#endif

#endif