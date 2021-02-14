#ifndef __PASULI_CURLY_TORUS_2__
#define __PASULI_CURLY_TORUS_2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descCurlyTorus2;

#if (USE_CURLY_TORUS_2 != 0)
void CurlyTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif