#ifndef __PASULI_TWISTED_HEART__
#define __PASULI_TWISTED_HEART__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TWISTED_HEART != 0)
void TwistedHeart(double u, double v,
                  double *constants,
                  PaSuLiObject *pO);
#endif

#endif