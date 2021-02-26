#ifndef __PASULI_FACING_SNAIL__
#define __PASULI_FACING_SNAIL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_FACING_SNAIL != 0)
void FacingSnail(pasuli_vartype u, pasuli_vartype v,
				 pasuli_consttype *constants,
				 PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descFacingSnail)
#endif

#endif