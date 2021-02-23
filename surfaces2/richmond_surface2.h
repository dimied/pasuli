#ifndef __PASULI_RICHMOND_SURFACE2__
#define __PASULI_RICHMOND_SURFACE2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_RICHMOND_SURFACE2 != 0)
void RichmondSurface2(pasuli_vartype u,
                      pasuli_vartype v,
                      pasuli_consttype *constants,
                      PaSuLiObject *pO);
#endif

#endif