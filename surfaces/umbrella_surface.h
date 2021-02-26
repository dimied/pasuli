#ifndef __PASULI_UMBRELLA_SURFACE__
#define __PASULI_UMBRELLA_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_UMBRELLA_SURFACE != 0)
void UmbrellaSurface(pasuli_vartype u,
                     pasuli_vartype v,
                     pasuli_consttype *constants,
                     PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descUmbrellaSurface)
#endif

#endif