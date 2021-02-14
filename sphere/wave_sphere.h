#ifndef __PASULI_WAVE_SPHERE__
#define __PASULI_WAVE_SPHERE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_WAVE_SPHERE != 0)
void WaveSphere(pasuli_vartype u,
			   pasuli_vartype v,
			   pasuli_consttype *constants,
			   PaSuLiObject *pO);
#endif

#endif
