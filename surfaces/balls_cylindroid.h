#ifndef __PASULI_BALLS_CYLINDROID__
#define __PASULI_BALLS_CYLINDROID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BALLS_CYLINDROID != 0)
void BallsCylindroid(pasuli_vartype u,
                     pasuli_vartype v,
                     pasuli_consttype *constants,
                     PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descBallsCylindroid)
#endif 

#endif