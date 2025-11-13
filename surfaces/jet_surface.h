#ifndef __PASULI_JET_SURFACE__
#define __PASULI_JET_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_JET_SURFACE != 0)
void JetSurface(pasuli_vartype u, pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descJetSurface)
#endif

#endif