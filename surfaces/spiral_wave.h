#ifndef __PASULI_SPIRAL_WAVE__
#define __PASULI_SPIRAL_WAVE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SPIRAL_WAVE != 0)
void SpiralWave(double u, double v,
                double *constants,
                PaSuLiObject *pO);
#endif

#endif