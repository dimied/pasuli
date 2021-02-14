#ifndef __PASULI_KUENS_SURFACE__
#define __PASULI_KUENS_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_KUENS_SURFACE != 0)
void KuensSurface(double u, double v,
				  double *constants,
				  PaSuLiObject *pO);
#endif

#endif