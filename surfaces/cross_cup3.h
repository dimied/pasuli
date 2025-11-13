#ifndef __PASULI_CROSS_CUP3__
#define __PASULI_CROSS_CUP3__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CROSS_CUP3 != 0)
void CrossCup3(pasuli_vartype u,
               pasuli_vartype v,
               pasuli_consttype *constants,
               PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descCrossCup3)
#endif

#endif