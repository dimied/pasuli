#ifndef __PASULI_SINE_CONE__
#define __PASULI_SINE_CONE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SINE_CONE != 0)
void SineCone(pasuli_vartype u, pasuli_vartype v,
			  pasuli_consttype *constants,
			  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descSineCone)
#endif

#endif