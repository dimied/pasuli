#ifndef __PASULI_HOLE_DISCUS__
#define __PASULI_HOLE_DISCUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HOLE_DISCUS != 0)
void HoleDiscus(pasuli_vartype u, pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO);
#endif

#endif