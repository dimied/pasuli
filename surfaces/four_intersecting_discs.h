#ifndef __PASULI_FOUR_INTERSECTING_DISCS__
#define __PASULI_FOUR_INTERSECTING_DISCS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_FOUR_INTERSECTING_DISCS != 0)
void FourIntersectingDiscs(pasuli_vartype u,
                           pasuli_vartype v,
                           pasuli_consttype *constants,
                           PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descFourIntersectingDiscs)
#endif

#endif