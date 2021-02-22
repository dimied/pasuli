#ifndef __PASULI_NEPHROID_TORUS_2__
#define __PASULI_NEPHROID_TORUS_2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descNephroidTorus2;

#if (USE_NEPHROID_TORUS_2 != 0)
void NephroidTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif