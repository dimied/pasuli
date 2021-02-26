#ifndef __PASULI_CUSPIDAL_LIPS__
#define __PASULI_CUSPIDAL_LIPS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CUSPIDAL_LIPS != 0)
void CuspidalLips(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descCuspidalLips)
#endif

#endif