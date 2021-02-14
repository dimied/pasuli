#ifndef __PASULI_SPIRAL_TORUS__
#define __PASULI_SPIRAL_TORUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descSpiralTorus;

#if (USE_SPIRAL_TORUS != 0)
void SpiralTorus(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif