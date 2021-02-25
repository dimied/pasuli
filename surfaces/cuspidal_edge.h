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

#endif