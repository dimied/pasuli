#ifndef __PASULI_SWALLOW_SURFACE__
#define __PASULI_SWALLOW_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SWALLOW_SURFACE != 0)
void SwallowSurface(pasuli_vartype u, pasuli_vartype v,
                    pasuli_consttype *constants,
                    PaSuLiObject *pO);
#endif

#endif