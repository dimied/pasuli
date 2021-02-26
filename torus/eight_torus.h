#ifndef __PASULI_EIGHT_TORUS__
#define __PASULI_EIGHT_TORUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_EIGHT_TORUS != 0)
void EightTorus(pasuli_vartype u,
				pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_TORUS != 0)
HEADER_DESC_PTR(descEightTorus)
#endif

#endif