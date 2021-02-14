#ifndef __PASULI_BELL_WAVE__
#define __PASULI_BELL_WAVE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BELL_WAVE != 0)
void BellWave(pasuli_vartype u, pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO);
#endif

#endif