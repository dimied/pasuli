#ifndef __PASULI_SPRING2__
#define __PASULI_SPRING2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SPRING2 != 0)
void Spring2(pasuli_vartype u, pasuli_vartype v,
			 pasuli_consttype *constants,
			 PaSuLiObject *pO);
#endif

#endif