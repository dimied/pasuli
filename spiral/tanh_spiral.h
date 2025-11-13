#ifndef __PASULI_TANH_SPIRAL__
#define __PASULI_TANH_SPIRAL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TANH_SPIRAL != 0)
void TanhSpiral(pasuli_vartype u,
				pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SPIRAL != 0)
HEADER_DESC_PTR(descTanhSpiral)
#endif

#endif