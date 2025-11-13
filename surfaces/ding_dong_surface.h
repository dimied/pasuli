#ifndef __PASULI_DING_DONG_SURFACE__
#define __PASULI_DING_DONG_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_DING_DONG_SURFACE != 0)
void DingDongSurface(pasuli_vartype u,
                     pasuli_vartype v,
                     pasuli_consttype *constants,
                     PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descDingDongSurface)
#endif

#endif