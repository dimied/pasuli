#ifndef __PASULI_PEANO_SURFACE__
#define __PASULI_PEANO_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PEANO_SURFACE != 0)
void PeanoSurface(pasuli_vartype u, 
                pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO);
#endif

#endif