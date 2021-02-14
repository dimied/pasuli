#ifndef __PASULI_PISOT_TRIAXIAL__
#define __PASULI_PISOT_TRIAXIAL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PISOT_TRIAXIAL != 0)
void PisotTriaxial(double u, double v,
                   double *constants,
                   PaSuLiObject *pO);
#endif

#endif