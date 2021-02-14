#ifndef __PASULI_TRACTROID__
#define __PASULI_TRACTROID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TRACTROID != 0)
void Tractroid(pasuli_vartype u, pasuli_vartype v,
               pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#endif