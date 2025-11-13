#ifndef __PASULI_SIEVERT_SURFACE__
#define __PASULI_SIEVERT_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SIEVERT_SURFACE != 0)
void SievertSurface(pasuli_vartype u,
                    pasuli_vartype v,
                    pasuli_consttype *constants,
                    PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descSievertSurface)
#endif

#endif