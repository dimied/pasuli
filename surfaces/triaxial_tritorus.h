#ifndef __PASULI_TRIAXIAL_TRITORUS__
#define __PASULI_TRIAXIAL_TRITORUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRIAXIAL_TRITORUS != 0)
void TriaxialTritorus(double u, double v,
					  double *constants,
					  PaSuLiObject *pO);
#endif

#endif