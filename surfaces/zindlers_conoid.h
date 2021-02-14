#ifndef __PASULI_ZINDLERS_CONOID__
#define __PASULI_ZINDLERS_CONOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_ZINDLERS_CONOID != 0)
void ZindlersConoid(double u, double v,
                    double *constants,
                    PaSuLiObject *pO);
#endif

#endif