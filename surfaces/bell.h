#ifndef __PASULI_BELL__
#define __PASULI_BELL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BELL != 0)
void Bell(double u, double v,
          double *constants,
          PaSuLiObject *pO);
#endif

#endif