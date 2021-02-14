#ifndef __PASULI_BONAN_JEENER_KLEIN_SURFACE__
#define __PASULI_BONAN_JEENER_KLEIN_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BONAN_JEENER_KLEIN_SURFACE != 0)
void BonanJeenerKleinSurface(double u, double v,
							 double *constants,
							 PaSuLiObject *pO);
#endif

#endif