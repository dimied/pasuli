#ifndef __PASULI_TOOTH_SURFACE__
#define __PASULI_TOOTH_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TOOTH_SURFACE != 0)
void ToothSurface(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO);
#endif

#endif