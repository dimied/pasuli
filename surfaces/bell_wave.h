#ifndef __PASULI_BELL_WAVE__
#define __PASULI_BELL_WAVE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BELL_WAVE != 0)
void BellWave(pasuli_vartype u, pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descBellWave)
#endif

#endif