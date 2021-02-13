#ifndef __PASULI_CATENOID__
#define __PASULI_CATENOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CATENOID != 0)
void Catenoid(double u, double v,
              double *constants, PaSuLiObject *pO);
#endif

#endif