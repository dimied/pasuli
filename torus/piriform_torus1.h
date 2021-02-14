#ifndef __PASULI_PIRIFORM_TORUS_1__
#define __PASULI_PIRIFORM_TORUS_1__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descPiriformTorus1;

#if (USE_PIRIFORM_TORUS_1 != 0)
void PiriformTorus1(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif