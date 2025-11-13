#ifndef __PASULI_CUSPIDAL_BEAKS__
#define __PASULI_CUSPIDAL_BEAKS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CUSPIDAL_BEAKS != 0)
void CuspidalBeaks(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descCuspidalBeaks)
#endif

#endif