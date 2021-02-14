#ifndef __PASULI_BOHEMIAN_DOME_SURFACE__
#define __PASULI_BOHEMIAN_DOME_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BOHEMIAN_DOME_SURFACE != 0)
void BohemianDomeSurface(pasuli_vartype u, pasuli_vartype v, 
			  double* constants, PaSuLiObject* pO);
#endif

#endif