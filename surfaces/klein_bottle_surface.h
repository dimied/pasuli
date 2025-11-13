#ifndef __PASULI_KLEIN_BOTTLE_SURFACE__
#define __PASULI_KLEIN_BOTTLE_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_KLEIN_BOTTLE_SURFACE != 0)
void KleinBottleSurface(pasuli_vartype u, pasuli_vartype v,
                        pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descKleinBottleSurface)
#endif

#endif