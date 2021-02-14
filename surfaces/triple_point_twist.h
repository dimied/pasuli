#ifndef __PASULI_TRIPLE_POINT_TWIST__
#define __PASULI_TRIPLE_POINT_TWIST__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRIPLE_POINT_TWIST != 0)
void TriplePointTwist(pasuli_vartype u, pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO);
#endif

#endif