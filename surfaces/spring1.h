#ifndef __PASULI_SPRING1__
#define __PASULI_SPRING1__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SPRING1 != 0)
void Spring1(pasuli_vartype u,
			 pasuli_vartype v,
			 pasuli_consttype *constants,
			 PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descSpring1)
#endif

#endif