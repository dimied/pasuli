#ifndef __PASULI_PLUECKER_CONOID2__
#define __PASULI_PLUECKER_CONOID2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PLUECKER_CONOID2 != 0)
void PlueckerConoid2(pasuli_vartype u,
                     pasuli_vartype v,
                     pasuli_consttype *constants,
                     PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descPlueckerConoid2)
#endif

#endif