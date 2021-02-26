#ifndef __PASULI_TRIPLE_CORK_SCREW3__
#define __PASULI_TRIPLE_CORK_SCREW3__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRIPLE_CORK_SCREW3 != 0)
void TripleCorkScrew3(pasuli_vartype u, pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descTripleCorkScrew3)
#endif

#endif