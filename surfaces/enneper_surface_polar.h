#ifndef __PASULI_ENNEPER_SURFACE_POLAR__
#define __PASULI_ENNEPER_SURFACE_POLAR__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_ENNEPER_SURFACE_POLAR != 0)
void EnneperSurfacePolar(pasuli_vartype u, pasuli_vartype v,
						 pasuli_consttype *constants,
						 PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descEnneperSurfacePolar)
#endif

#endif