#ifndef __PASULI_RICHMOND_SURFACE3__
#define __PASULI_RICHMOND_SURFACE3__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_RICHMOND_SURFACE3 != 0)
void RichmondSurface3(pasuli_vartype u,
                      pasuli_vartype v,
                      pasuli_consttype *constants,
                      PaSuLiObject *pO);
#endif

#endif