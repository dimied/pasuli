#ifndef __PASULI_TWISTED_PIPE_SURFACE__
#define __PASULI_TWISTED_PIPE_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TWISTED_PIPE_SURFACE != 0)
void TwistedPipeSurface(double u, double v,
                        double *constants,
                        PaSuLiObject *pO);
#endif

#endif