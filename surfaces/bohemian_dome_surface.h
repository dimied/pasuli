#ifndef __PASULI_BOHEMIAN_DOME_SURFACE__
#define __PASULI_BOHEMIAN_DOME_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BOHEMIAN_DOME_SURFACE != 0)
void BohemianDomeSurface(double u, double v, 
			  double* constants, PaSuLiObject* pO);
#endif

#endif