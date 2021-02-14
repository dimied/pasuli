#ifndef __PASULI_ROMAN_SURFACE__
#define __PASULI_ROMAN_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_ROMAN_SURFACE != 0)
void RomanSurface(pasuli_vartype u, pasuli_vartype v,
                  pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#endif