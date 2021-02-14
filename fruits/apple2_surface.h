#ifndef __PASULI_APPLE2_SURFACE__
#define __PASULI_APPLE2_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_APPLE2_SURFACE != 0)
void Apple2_Surface(pasuli_vartype u, pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO);
#endif

#endif