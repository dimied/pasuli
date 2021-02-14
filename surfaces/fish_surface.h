#ifndef __PASULI_FISH_SURFACE__
#define __PASULI_FISH_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_FISH_SURFACE != 0)
void FishSurface(pasuli_vartype u, pasuli_vartype v,
				 pasuli_consttype *constants,
				 PaSuLiObject *pO);
#endif

#endif