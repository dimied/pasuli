#ifndef __PASULI_HOLE_DISCUS__
#define __PASULI_HOLE_DISCUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HOLE_DISCUS != 0)
void HoleDiscus(double u, double v,
                double *constants,
                PaSuLiObject *pO);
#endif

#endif