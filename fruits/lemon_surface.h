#ifndef __PASULI_LEMON_SURFACE__
#define __PASULI_LEMON_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_LEMON_SURFACE != 0)
void LemonSurface(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_FRUITS != 0)
HEADER_DESC_PTR(descLemonSurface)
#endif

#endif