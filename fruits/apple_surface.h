#ifndef __PASULI_APPLE_SURFACE__
#define __PASULI_APPLE_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_APPLE_SURFACE != 0)
void AppleSurface(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO);
#endif

#endif