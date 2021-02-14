#ifndef __PASULI_SINE_WAVE__
#define __PASULI_SINE_WAVE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SINE_WAVE != 0)
void SineWave(pasuli_vartype u, pasuli_vartype v,
              pasuli_consttype *constants,
              PaSuLiObject *pO);
#endif

#endif