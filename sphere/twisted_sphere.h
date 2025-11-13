#ifndef __PASULI_TWISTED_SPHERE__
#define __PASULI_TWISTED_SPHERE__

#include "../pasuli_conf/pasuli_cfg.h"
#include "../pasuli_common/pasuli_defs.h"

#if (USE_TWISTED_SPHERE != 0)
void TwistedSphere(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SPHERE != 0)
HEADER_DESC_PTR(descTwistedSphere)
#endif

#endif