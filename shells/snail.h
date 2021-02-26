#ifndef __PASULI_SNAIL__
#define __PASULI_SNAIL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SNAIL != 0)
void Snail(pasuli_vartype u,
		   pasuli_vartype v,
		   pasuli_consttype *constants,
		   PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SHELLS != 0)
HEADER_DESC_PTR(descSnail)
#endif

#endif