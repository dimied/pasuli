#ifndef __PASULI_KIDNEY_SURFACE__
#define __PASULI_KIDNEY_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_KIDNEY_SURFACE != 0)
void KidneySurface(pasuli_vartype u, pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO);
#endif

#endif