#ifndef __PASULI_KUENS_SURFACE__
#define __PASULI_KUENS_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_KUENS_SURFACE != 0)
void KuensSurface(pasuli_vartype u, pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO);
#endif

#endif