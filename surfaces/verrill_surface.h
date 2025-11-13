#ifndef __PASULI_VERRILL_SURFACE__
#define __PASULI_VERRILL_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_VERRILL_SURFACE != 0)
void VerrillSurface(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descVerrillSurface)
#endif

#endif