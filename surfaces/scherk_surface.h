#ifndef __PASULI_SCHERK_SURFACE__
#define __PASULI_SCHERK_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SCHERK_SURFACE != 0)
void ScherkSurface(double u, double v,
                   double *constants,
                   PaSuLiObject *pO);
#endif

#endif