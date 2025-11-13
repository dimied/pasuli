#ifndef __PASULI_TRIAXIAL_TEARDROP__
#define __PASULI_TRIAXIAL_TEARDROP__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRIAXIAL_TEARDROP != 0)
void TriaxialTeardrop(pasuli_vartype u, pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descTriaxialTeardrop)
#endif

#endif