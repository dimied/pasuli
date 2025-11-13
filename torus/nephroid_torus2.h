#ifndef __PASULI_NEPHROID_TORUS_2__
#define __PASULI_NEPHROID_TORUS_2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_NEPHROID_TORUS_2 != 0)
void NephroidTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_TORUS != 0)
HEADER_DESC_PTR(descNephroidTorus2)
#endif

#endif