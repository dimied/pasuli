#ifndef __PASULI_MORIN_SURFACE__
#define __PASULI_MORIN_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_MORIN_SURFACE != 0)
void MorinSurface(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO);
#endif

#endif