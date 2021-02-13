#ifndef __PASULI_PARABOLOID__
#define __PASULI_PARABOLOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PARABOLOID != 0)
void Paraboloid(double u, double v,
                double *constants, PaSuLiObject *pO);
#endif

#endif