#ifndef __PASULI_TWISTED_HEART__
#define __PASULI_TWISTED_HEART__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TWISTED_HEART != 0)
void TwistedHeart(pasuli_vartype u, pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO);
#endif

#endif