#ifndef __PASULI_TRICUSPOID_TORUS_2__
#define __PASULI_TRICUSPOID_TORUS_2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descTricuspoidTorus2;

#if (USE_TRICUSPOID_TORUS_2 != 0)
void TricuspoidTorus2(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO);
#endif

#endif