#ifndef __PASULI_SIEVERT_SURFACE__
#define __PASULI_SIEVERT_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SIEVERT_SURFACE != 0)
void SievertSurface(double u, double v,
                    double *constants,
                    PaSuLiObject *pO);
#endif

#endif