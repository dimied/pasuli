#ifndef __PASULI_CONE__
#define __PASULI_CONE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CONE != 0)
void Cone(pasuli_vartype u, pasuli_vartype v,
		  pasuli_consttype *constants,
		  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descCone)
#endif

#endif