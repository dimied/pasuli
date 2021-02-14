#ifndef __PASULI_COSINE_SURFACE2__
#define __PASULI_COSINE_SURFACE2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_COSINE_SURFACE2 != 0)
void CosineSurface2(double u, double v,
                    double *constants,
                    PaSuLiObject *pO);
#endif

#endif