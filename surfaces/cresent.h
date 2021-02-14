#ifndef __PASULI_CRESENT__
#define __PASULI_CRESENT__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_CRESENT != 0)
void Cresent(pasuli_vartype u, pasuli_vartype v,
             pasuli_consttype *constants,
             PaSuLiObject *pO);
#endif

#endif