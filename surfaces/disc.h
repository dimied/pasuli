#ifndef __PASULI_DISC__
#define __PASULI_DISC__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_DISC != 0)
void Disc(double u, double v,
          double *constants,
          PaSuLiObject *pO);
#endif

#endif