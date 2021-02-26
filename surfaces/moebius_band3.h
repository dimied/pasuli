#ifndef __PASULI_MOEBIUS_BAND3__
#define __PASULI_MOEBIUS_BAND3__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_MOEBIUS_BAND3 != 0)
void MoebiusBand3(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descMoebiusBand3)
#endif

#endif