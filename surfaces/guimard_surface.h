#ifndef __PASULI_GUIMARD_SURFACE__
#define __PASULI_GUIMARD_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_GUIMARD_SURFACE != 0)
void GuimardSurface(pasuli_vartype u, pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif