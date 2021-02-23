#ifndef __PASULI_BOYS_SURFACE2__
#define __PASULI_BOYS_SURFACE2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BOYS_SURFACE2 != 0)
void BoysSurface2(pasuli_vartype u, 
                pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO);
#endif

#endif