#ifndef __PASULI_BOW_CURVE__
#define __PASULI_BOW_CURVE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BOW_CURVE != 0)
void BowCurve(pasuli_vartype u, pasuli_vartype v,
              pasuli_consttype *constants,
              PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descBowCurve)
#endif

#endif