#ifndef __PASULI_TORUS_DECLARATIONS__
#define __PASULI_TORUS_DECLARATIONS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TORUS != 0)
void Torus(pasuli_vartype u,
		   pasuli_vartype v,
		   pasuli_consttype *constants,
		   PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_TORUS != 0)
extern char *descTorus;
#endif

#endif
