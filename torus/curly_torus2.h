#ifndef __PASULI_CURLY_TORUS_2__
#define __PASULI_CURLY_TORUS_2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CURLY_TORUS_2 != 0)
void CurlyTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_TORUS != 0)
HEADER_DESC_PTR(descCurlyTorus2)
#endif

#endif