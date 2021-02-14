#ifndef __PASULI_CASSINIAN_OVAL_TORUS_2__
#define __PASULI_CASSINIAN_OVAL_TORUS_2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descCassinianOvalTorus2;

#if (USE_CASSINIAN_OVAL_TORUS_2 != 0)
void CassinianOvalTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif