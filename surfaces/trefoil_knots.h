#ifndef __PASULI_TREFOIL_KNOTS__
#define __PASULI_TREFOIL_KNOTS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TREFOIL_KNOTS != 0)
void TrefoilKnots(double u, double v,
                  double *constants,
                  PaSuLiObject *pO);
#endif

#endif