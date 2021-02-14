#ifndef __PASULI_DOUBLE_CONE__
#define __PASULI_DOUBLE_CONE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_DOUBLE_CONE != 0)
void DoubleCone(pasuli_vartype u, pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO);
#endif

#endif