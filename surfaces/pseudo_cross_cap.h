#ifndef __PASULI_PSEUDO_CROSS_CAP__
#define __PASULI_PSEUDO_CROSS_CAP__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PSEUDO_CROSS_CAP != 0)
void PseudoCrossCap(pasuli_vartype u, pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descPseudoCrossCap)
#endif

#endif