#ifndef __PASULI_HYPERBOLOID__
#define __PASULI_HYPERBOLOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HYPERBOLOID != 0)
void Hyperboloid(double u,
                 double v,
                 double *constants,
                 PaSuLiObject *pO);
#endif

#endif