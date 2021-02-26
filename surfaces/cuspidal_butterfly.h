#ifndef __PASULI_CUSPIDAL_BUTTERFLY__
#define __PASULI_CUSPIDAL_BUTTERFLY__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CUSPIDAL_BUTTERFLY != 0)
void CuspidalButterfly(pasuli_vartype u,
                       pasuli_vartype v,
                       pasuli_consttype *constants,
                       PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descCuspidalButterfly)
#endif

#endif