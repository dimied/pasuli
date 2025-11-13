#ifndef __PASULI_TRIPLE_POINT_TWIST__
#define __PASULI_TRIPLE_POINT_TWIST__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRIPLE_POINT_TWIST != 0)
void TriplePointTwist(pasuli_vartype u, pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descTriplePointTwist)
#endif

#endif