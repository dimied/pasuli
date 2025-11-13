#ifndef __PASULI_EGG__
#define __PASULI_EGG__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_EGG != 0)
void Egg(pasuli_vartype u, pasuli_vartype v,
		 pasuli_consttype *constants,
		 PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descEgg)
#endif

#endif