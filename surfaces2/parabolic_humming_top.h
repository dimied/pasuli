#ifndef __PASULI_PARABOLIC_HUMMING_TOP__
#define __PASULI_PARABOLIC_HUMMING_TOP__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PARABOLIC_HUMMING_TOP != 0)
void ParabolicHummingTop(pasuli_vartype u,
                         pasuli_vartype v,
                         pasuli_consttype *constants,
                         PaSuLiObject *pO);
#endif

#endif