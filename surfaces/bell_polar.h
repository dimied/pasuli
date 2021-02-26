#ifndef __PASULI_BELL_POLAR__
#define __PASULI_BELL_POLAR__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BELL_POLAR != 0)
void BellPolar(pasuli_vartype u, pasuli_vartype v,
               pasuli_consttype *constants,
               PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descBellPolar)
#endif

#endif