#ifndef __PASULI_KAPPA_SURFACE__
#define __PASULI_KAPPA_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_KAPPA_SURFACE != 0)
void KappaSurface(pasuli_vartype u, pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO);
#endif

#endif