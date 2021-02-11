#ifndef __PASULI_WAVETORUS__
#define __PASULI_WAVETORUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"
#include "../pasuli_macros.h"

#if (COMPILE_TORUS != 0)
void WaveTorus(pasuli_vartype u, pasuli_vartype v,
               pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#endif