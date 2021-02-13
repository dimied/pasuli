#ifndef __PASULI_RICHMOND_SURFACE__
#define __PASULI_RICHMOND_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_RICHMOND_SURFACE != 0)
void RichmondSurface(double u, double v, 
					double* constants, PaSuLiObject* pO);
#endif

#endif