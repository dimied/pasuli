#ifndef __PASULI_SPINNING_TOP1__
#define __PASULI_SPINNING_TOP1__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SPINNING_TOP1 != 0)
void SpinningTop1(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descSpinningTop1)
#endif

#endif