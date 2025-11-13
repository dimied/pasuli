#ifndef __PASULI_FUNNEL__
#define __PASULI_FUNNEL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_FUNNEL != 0)
void Funnel(pasuli_vartype u, pasuli_vartype v,
            pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descFunnel)
#endif

#endif