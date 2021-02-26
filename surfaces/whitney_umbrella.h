#ifndef __PASULI_WHITNEY_UMBRELLA__
#define __PASULI_WHITNEY_UMBRELLA__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_WHITNEY_UMBRELLA != 0)
void WhitneyUmbrella(pasuli_vartype u, pasuli_vartype v,
                     pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descWhitneyUmbrella)
#endif

#endif