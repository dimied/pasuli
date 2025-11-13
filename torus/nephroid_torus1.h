#ifndef __PASULI_NEPHROID_TORUS_1__
#define __PASULI_NEPHROID_TORUS_1__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_NEPHROID_TORUS_1 != 0)
void NephroidTorus1(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_TORUS != 0)
HEADER_DESC_PTR(descNephroidTorus1)
#endif

#endif