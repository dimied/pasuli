#ifndef __PASULI_TWISTED_SPHERE__
#define __PASULI_TWISTED_SPHERE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_TWISTED_SPHERE != 0)
void TwistedSphere(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO);
#endif

#endif