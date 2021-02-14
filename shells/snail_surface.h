#ifndef __PASULI_SNAIL_SURFACE__
#define __PASULI_SNAIL_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SNAIL_SURFACE != 0)
void SnailSurface(pasuli_vartype u,
				  pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO);
#endif

#endif