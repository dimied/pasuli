#ifndef __PASULI_TWISTED_PIPE_SURFACE__
#define __PASULI_TWISTED_PIPE_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TWISTED_PIPE_SURFACE != 0)
void TwistedPipeSurface(pasuli_vartype u, pasuli_vartype v,
                        pasuli_consttype *constants,
                        PaSuLiObject *pO);
#endif

#endif