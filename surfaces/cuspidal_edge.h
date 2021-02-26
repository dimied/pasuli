#ifndef __PASULI_CUSPIDAL_EDGE__
#define __PASULI_CUSPIDAL_EDGE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CUSPIDAL_EDGE != 0)
void CuspidalEdge(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descCuspidalEdge)
#endif

#endif