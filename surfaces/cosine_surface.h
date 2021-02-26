#ifndef __PASULI_COSINE_SURFACE__
#define __PASULI_COSINE_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_COSINE_SURFACE != 0)
void CosineSurface(pasuli_vartype u, pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descCosineSurface)
#endif

#endif