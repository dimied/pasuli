#ifndef __PASULI_FRESNEL__
#define __PASULI_FRESNEL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_FRESNEL != 0)
void Fresnel(double u, double v,
             double *constants,
             PaSuLiObject *pO);
#endif

#endif