#ifndef __PASULI_KISS_SURFACE__
#define __PASULI_KISS_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_KISS_SURFACE != 0)
void KissSurface(pasuli_vartype u,
                 pasuli_vartype v,
                 pasuli_consttype *constants,
                 PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descKissSurface)
#endif

#endif