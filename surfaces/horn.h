#ifndef __PASULI_HORN__
#define __PASULI_HORN__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HORN != 0)
void Horn(pasuli_vartype u, pasuli_vartype v,
		  pasuli_consttype *constants,
		  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descHorn)
#endif

#endif