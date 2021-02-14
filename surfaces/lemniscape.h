#ifndef __PASULI_LEMNISCAPE__
#define __PASULI_LEMNISCAPE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_LEMNISCAPE != 0)
void Lemniscape(double u, double v,
				double *constants,
				PaSuLiObject *pO);
#endif

#endif