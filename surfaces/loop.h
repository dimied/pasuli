#ifndef __PASULI_LOOP__
#define __PASULI_LOOP__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_LOOP != 0)
void Loop(pasuli_vartype u, pasuli_vartype v,
		  pasuli_consttype *constants,
		  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descLoop)
#endif

#endif