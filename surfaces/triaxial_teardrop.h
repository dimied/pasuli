#ifndef __PASULI_TRIAXIAL_TEARDROP__
#define __PASULI_TRIAXIAL_TEARDROP__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRIAXIAL_TEARDROP != 0)
void TriaxialTeardrop(double u, double v,
					  double *constants,
					  PaSuLiObject *pO);
#endif

#endif