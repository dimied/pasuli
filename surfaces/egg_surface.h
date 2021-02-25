#ifndef __PASULI_EGG_SURFACE__
#define __PASULI_EGG_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_EGG_SURFACE != 0)
void EggSurface(pasuli_vartype u,
                pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO);
#endif

#endif