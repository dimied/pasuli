#ifndef __PASULI_BELL__
#define __PASULI_BELL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BELL != 0)
void Bell(pasuli_vartype u, pasuli_vartype v,
          pasuli_consttype *constants,
          PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descBell)
#endif

#endif