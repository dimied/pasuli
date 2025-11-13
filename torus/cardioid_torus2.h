#ifndef __PASULI_CARDIOID_TORUS_2__
#define __PASULI_CARDIOID_TORUS_2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CARDIOID_TORUS_2 != 0)
void CardioidTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descCardioidTorus2)
#endif

#endif