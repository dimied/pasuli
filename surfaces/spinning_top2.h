#ifndef __PASULI_SPINNING_TOP2__
#define __PASULI_SPINNING_TOP2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SPINNING_TOP2 != 0)
void SpinningTop2(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descSpinningTop2)
#endif

#endif