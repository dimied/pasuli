#ifndef __PASULI_TRIPLE_CORK_SCREW2__
#define __PASULI_TRIPLE_CORK_SCREW2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRIPLE_CORK_SCREW2 != 0)
void TripleCorkScrew2(pasuli_vartype u, pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descTripleCorkScrew2)
#endif

#endif