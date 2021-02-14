#ifndef __PASULI_CATALANS_SURFACE__
#define __PASULI_CATALANS_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CATALANS_SURFACE != 0)
void CatalansSurface(pasuli_vartype u, pasuli_vartype v,
                     pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#endif