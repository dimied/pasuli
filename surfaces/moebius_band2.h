#ifndef __PASULI_MOEBIUS_BAND2_SURFACE__
#define __PASULI_MOEBIUS_BAND2_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_MOEBIUS_BAND2 != 0)
void MoebiusBand2(pasuli_vartype u, pasuli_vartype v,
                 pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descMoebiusBand2)
#endif

#endif