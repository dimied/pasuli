#ifndef __PASULI_TREFOIL_KNOTS2__
#define __PASULI_TREFOIL_KNOTS2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TREFOIL_KNOTS2 != 0)
void TrefoilKnots2(pasuli_vartype u, pasuli_vartype v,
				   pasuli_consttype *constants,
				   PaSuLiObject *pO);
#endif

#endif