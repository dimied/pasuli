#ifndef __PASULI_EPIZYKLOID_TORUS_1__
#define __PASULI_EPIZYKLOID_TORUS_1__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descEpizykloidTorus1;

#if (USE_EPIZYKLOID_TORUS_1 != 0)
void EpizykloidTorus1(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif