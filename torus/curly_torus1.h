#ifndef __PASULI_CURLY_TORUS_1__
#define __PASULI_CURLY_TORUS_1__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CURLY_TORUS_1 != 0)
void CurlyTorus1(pasuli_vartype u,
                 pasuli_vartype v,
                 pasuli_consttype *constants,
                 PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descCurlyTorus1)
#endif

#endif