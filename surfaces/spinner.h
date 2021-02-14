#ifndef __PASULI_SPINNER__
#define __PASULI_SPINNER__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SPINNER != 0)
void Spinner(double u, double v,
             double *constants,
             PaSuLiObject *pO);
#endif

#endif