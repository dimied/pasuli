#ifndef __PASULI_TRIAXIAL_HEXATORUS__
#define __PASULI_TRIAXIAL_HEXATORUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRIAXIAL_HEXATORUS != 0)
void TriaxialHexatorus(double u, double v,
                       double *constants,
                       PaSuLiObject *pO);
#endif

#endif