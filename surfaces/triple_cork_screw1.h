#ifndef __PASULI_TRIPLE_CORK_SCREW1__
#define __PASULI_TRIPLE_CORK_SCREW1__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRIPLE_CORK_SCREW1 != 0)
void TripleCorkScrew1(pasuli_vartype u, pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descTripleCorkScrew1)
#endif

#endif