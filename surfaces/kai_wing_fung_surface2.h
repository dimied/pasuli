#ifndef __PASULI_KAI_WING_FUNG_SURFACE2__
#define __PASULI_KAI_WING_FUNG_SURFACE2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_KAI_WING_FUNG_SURFACE2 != 0)
void KaiWingFungSurface2(pasuli_vartype u,
                         pasuli_vartype v,
                         pasuli_consttype *constants,
                         PaSuLiObject *pO);
#endif

#endif