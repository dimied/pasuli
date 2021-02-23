#ifndef __PASULI_WRINKLE_SPHERE__
#define __PASULI_WRINKLE_SPHERE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_WRINKLE_SPHERE != 0)
void WrinkleSphere(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO);
#endif

#endif