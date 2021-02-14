#ifndef __PASULI_BOW_CURVE__
#define __PASULI_BOW_CURVE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BOW_CURVE != 0)
void BowCurve(double u, double v,
              double *constants,
              PaSuLiObject *pO);
#endif

#endif