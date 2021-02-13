#ifndef __PASULI_KLEIN_BOTTLE_SURFACE__
#define __PASULI_KLEIN_BOTTLE_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_KLEIN_BOTTLE_SURFACE != 0)
void KleinBottleSurface(double u, double v,
                        double *constants, PaSuLiObject *pO);
#endif

#endif