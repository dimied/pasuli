#ifndef __PASULI_COSINE_WAVE__
#define __PASULI_COSINE_WAVE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_COSINE_WAVE != 0)
void CosineWave(pasuli_vartype u, pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descCosineWave)
#endif

#endif