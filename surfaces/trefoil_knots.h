#ifndef __PASULI_TREFOIL_KNOTS__
#define __PASULI_TREFOIL_KNOTS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TREFOIL_KNOTS != 0)
void TrefoilKnots(pasuli_vartype u, pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descTrefoilKnots)
#endif

#endif