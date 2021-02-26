#ifndef __PASULI_EPIZYKLOID_TORUS_2__
#define __PASULI_EPIZYKLOID_TORUS_2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_EPIZYKLOID_TORUS_2 != 0)
void EpizykloidTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_TORUS != 0)
HEADER_DESC_PTR(descEpizykloidTorus2)
#endif

#endif