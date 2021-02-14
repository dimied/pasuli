#ifndef __PASULI_HOLE_DISC__
#define __PASULI_HOLE_DISC__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HOLE_DISC != 0)
void HoleDisc(double u, double v,
              double *constants,
              PaSuLiObject *pO);
#endif

#endif