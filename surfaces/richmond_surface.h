#ifndef __PASULI_RICHMOND_SURFACE__
#define __PASULI_RICHMOND_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_RICHMOND_SURFACE != 0)
void RichmondSurface(pasuli_vartype u, pasuli_vartype v, 
					double* constants, PaSuLiObject* pO);
#endif

#endif