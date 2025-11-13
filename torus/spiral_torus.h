#ifndef __PASULI_SPIRAL_TORUS__
#define __PASULI_SPIRAL_TORUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SPIRAL_TORUS != 0)
void SpiralTorus(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descSpiralTorus)
#endif

#endif