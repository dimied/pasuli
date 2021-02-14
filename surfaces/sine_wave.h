#ifndef __PASULI_SINE_WAVE__
#define __PASULI_SINE_WAVE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SINE_WAVE != 0)
void SineWave(double u, double v,
              double *constants,
              PaSuLiObject *pO);
#endif

#endif