#ifndef __PASULI_WAVES__
#define __PASULI_WAVES__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_WAVES != 0)
void Waves(pasuli_vartype u, pasuli_vartype v,
           pasuli_consttype *constants,
           PaSuLiObject *pO);
#endif

#endif