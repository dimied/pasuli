#ifndef __PASULI_HENNEBERGS_SURFACE__
#define __PASULI_HENNEBERGS_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HENNEBERGS_SURFACE != 0)
void HennebergsSurface(double u, double v,
                       double *constants,
                       PaSuLiObject *pO);
#endif

#endif