#ifndef __PASULI_BRAIDED_TORUS__
#define __PASULI_BRAIDED_TORUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BRAIDED_TORUS != 0)
void BraidedTorus(pasuli_vartype u,
				  pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_TORUS != 0)
HEADER_DESC_PTR(descBraidedTorus)
#endif

#endif