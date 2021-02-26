#ifndef __PASULI_LEMNISCAPE__
#define __PASULI_LEMNISCAPE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_LEMNISCAPE != 0)
void Lemniscape(pasuli_vartype u, pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descLemniscape)
#endif

#endif