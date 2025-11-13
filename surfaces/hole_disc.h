#ifndef __PASULI_HOLE_DISC__
#define __PASULI_HOLE_DISC__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HOLE_DISC != 0)
void HoleDisc(pasuli_vartype u, pasuli_vartype v,
              pasuli_consttype *constants,
              PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descHoleDisc)
#endif

#endif