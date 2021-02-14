#ifndef __PASULI_COSINE_WAVE__
#define __PASULI_COSINE_WAVE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_COSINE_WAVE != 0)
void CosineWave(double u, double v,
				double *constants,
				PaSuLiObject *pO);
#endif

#endif