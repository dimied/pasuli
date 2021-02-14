#ifndef __PASULI_CRESENT__
#define __PASULI_CRESENT__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CRESENT != 0)
void Cresent(double u, double v,
             double *constants,
             PaSuLiObject *pO);
#endif

#endif