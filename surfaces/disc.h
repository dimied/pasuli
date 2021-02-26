#ifndef __PASULI_DISC__
#define __PASULI_DISC__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_DISC != 0)
void Disc(pasuli_vartype u, pasuli_vartype v,
          pasuli_consttype *constants,
          PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descDisc)
#endif

#endif