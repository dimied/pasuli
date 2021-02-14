#ifndef __PASULI_SPIRAL_WAVE__
#define __PASULI_SPIRAL_WAVE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SPIRAL_WAVE != 0)
void SpiralWave(pasuli_vartype u, pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO);
#endif

#endif