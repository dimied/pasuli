#ifndef __PASULI_TRANGULOID_TREFOIL__
#define __PASULI_TRANGULOID_TREFOIL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRANGULOID_TREFOIL != 0)
void TranguloidTrefoil(double u, double v,
					   double *constants,
					   PaSuLiObject *pO);
#endif

#endif