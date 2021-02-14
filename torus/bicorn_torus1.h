#ifndef __PASULI_BICORN_TORUS_1__
#define __PASULI_BICORN_TORUS_1__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descBicornTorus1;

#if (USE_BICORN_TORUS_1 != 0)
void BicornTorus1(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif