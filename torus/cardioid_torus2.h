#ifndef __PASULI_CARDIOID_TORUS_2__
#define __PASULI_CARDIOID_TORUS_2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descCardioidTorus2;

#if (USE_CARDIOID_TORUS_2 != 0)
void CardioidTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif