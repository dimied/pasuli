#ifndef __PASULI_KAI_WING_FUNG_SURFACE1__
#define __PASULI_KAI_WING_FUNG_SURFACE1__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_KAI_WING_FUNG_SURFACE1 != 0)
void KaiWingFungSurface1(pasuli_vartype u,
                         pasuli_vartype v,
                         pasuli_consttype *constants,
                         PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descKaiWingFungSurface1)
#endif

#endif