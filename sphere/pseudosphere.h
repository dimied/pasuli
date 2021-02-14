#ifndef __PASULI_PSEUDOSPHERE__
#define __PASULI_PSEUDOSPHERE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PSEUDOSPHERE != 0)
void PseudoSphere(pasuli_vartype u,
			   pasuli_vartype v,
			   pasuli_consttype *constants,
			   PaSuLiObject *pO);
#endif

#endif