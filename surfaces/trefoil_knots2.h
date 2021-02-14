#ifndef __PASULI_TREFOIL_KNOTS2__
#define __PASULI_TREFOIL_KNOTS2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TREFOIL_KNOTS2 != 0)
void TrefoilKnots2(double u, double v,
				   double *constants,
				   PaSuLiObject *pO);
#endif

#endif