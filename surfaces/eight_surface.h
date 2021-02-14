#ifndef __PASULI_EIGHT_SURFACE__
#define __PASULI_EIGHT_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_EIGHT_SURFACE != 0)
void EightSurface(pasuli_vartype u, pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO);
#endif

#endif