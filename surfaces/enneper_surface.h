#ifndef __PASULI_ENNEPER_SURFACE__
#define __PASULI_ENNEPER_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_ENNEPER_SURFACE != 0)
void EnneperSurface(pasuli_vartype u, pasuli_vartype v,
                    pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#endif