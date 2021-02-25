#ifndef __PASULI_SNAIL2__
#define __PASULI_SNAIL2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SNAIL2 != 0)
void Snail2(pasuli_vartype u,
            pasuli_vartype v,
            pasuli_consttype *constants,
            PaSuLiObject *pO);
#endif

#endif