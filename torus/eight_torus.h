#ifndef __PASULI_EIGHT_TORUS__
#define __PASULI_EIGHT_TORUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descEightTorus;

#if (USE_EIGHT_TORUS != 0)
void EightTorus(pasuli_vartype u,
				pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO);
#endif

#endif