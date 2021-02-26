#ifndef __PASULI_FRESNEL__
#define __PASULI_FRESNEL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_FRESNEL != 0)
void Fresnel(pasuli_vartype u, pasuli_vartype v,
             pasuli_consttype *constants,
             PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descFresnel)
#endif

#endif