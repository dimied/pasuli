#ifndef __PASULI_LEMNISCAPE__
#define __PASULI_LEMNISCAPE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_LEMNISCAPE != 0)
void Lemniscape(pasuli_vartype u, pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO);
#endif

#endif