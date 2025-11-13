#ifndef __PASULI_CROSS_CUP__
#define __PASULI_CROSS_CUP__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CROSS_CUP != 0)
void CrossCup(pasuli_vartype u,
              pasuli_vartype v,
              pasuli_consttype *constants,
              PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descCrossCup)
#endif

#endif