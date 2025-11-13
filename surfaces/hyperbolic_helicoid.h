#ifndef __PASULI_HYPERBOLIC_HELICOID__
#define __PASULI_HYPERBOLIC_HELICOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HYPERBOLIC_HELICOID != 0)
void HyperbolicHelicoid(pasuli_vartype u, pasuli_vartype v,
                        pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descHyperbolicHelicoid)
#endif

#endif