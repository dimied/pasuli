#ifndef __PASULI_BELLEROPHINA__
#define __PASULI_BELLEROPHINA__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_BELLEROPHINA != 0)
void Bellerophina(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO);
#endif

#endif