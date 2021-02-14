#ifndef __PASULI_EPIZYKLOID_TORUS_2__
#define __PASULI_EPIZYKLOID_TORUS_2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descEpizykloidTorus2;

#if (USE_EPIZYKLOID_TORUS_2 != 0)
void EpizykloidTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif