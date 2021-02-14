#ifndef __PASULI_FACING_SNAIL__
#define __PASULI_FACING_SNAIL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_FACING_SNAIL != 0)
void FacingSnail(double u, double v,
				 double *constants,
				 PaSuLiObject *pO);
#endif

#endif