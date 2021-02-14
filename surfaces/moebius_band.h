#ifndef __PASULI_MOEBIUS_SURFACE__
#define __PASULI_MOEBIUS_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_MOEBIUS_BAND != 0)
void MoebiusBand(pasuli_vartype u, pasuli_vartype v,
                 pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#endif