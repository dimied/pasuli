#ifndef __PASULI_WAVETORUS__
#define __PASULI_WAVETORUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_WAVE_TORUS != 0)
void WaveTorus(pasuli_vartype u,
               pasuli_vartype v,
               pasuli_consttype *constants,
               PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_TORUS != 0)
HEADER_DESC_PTR(descWaveTorus)
#endif

#endif