#ifndef __PASULI_DOUBLE_SPHERE__
#define __PASULI_DOUBLE_SPHERE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_DOUBLE_CONE != 0)
void SomeSurface(pasuli_vartype u, pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO);
#endif

#endif