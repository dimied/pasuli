#ifndef __PASULI_HYPERBOLIC_SPIRAL__
#define __PASULI_HYPERBOLIC_SPIRAL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HYPERBOLIC_SPIRAL != 0)
void HyperbolicSpiral(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SPIRAL != 0)
HEADER_DESC_PTR(descHyperbolicSpiral)
#endif

#endif