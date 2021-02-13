#ifndef __PASULI_PLUECKER_CONOID__
#define __PASULI_PLUECKER_CONOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PLUECKER_CONOID != 0)
void PlueckerConoid(double u, double v,
                    double *constants, PaSuLiObject *pO);
#endif

#endif