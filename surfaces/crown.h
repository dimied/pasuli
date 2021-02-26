#ifndef __PASULI_CROWN__
#define __PASULI_CROWN__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CROWN != 0)
void Crown(pasuli_vartype u, pasuli_vartype v,
		   pasuli_consttype *constants,
		   PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descCrown)
#endif

#endif