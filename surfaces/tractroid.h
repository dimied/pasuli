#ifndef __PASULI_TRACTROID__
#define __PASULI_TRACTROID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRACTROID != 0)
void Tractroid(double u, double v,
               double *constants, PaSuLiObject *pO);
#endif

#endif