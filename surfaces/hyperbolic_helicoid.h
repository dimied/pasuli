#ifndef __PASULI_HYPERBOLIC_HELICOID__
#define __PASULI_HYPERBOLIC_HELICOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HYPERBOLIC_HELICOID != 0)
void HyperbolicHelicoid(double u, double v,
                        double *constants, PaSuLiObject *pO);
#endif

#endif