#ifndef __PASULI_SINE_CUBE__
#define __PASULI_SINE_CUBE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SINE_CUBE != 0)
void SineCube(pasuli_vartype u,
              pasuli_vartype v,
              pasuli_consttype *constants,
              PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descSineCube)
#endif

#endif