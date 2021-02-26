#ifndef __PASULI_LAWSON_BOTTLE__
#define __PASULI_LAWSON_BOTTLE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_LAWSON_BOTTLE != 0)
void LawsonBottle(pasuli_vartype u,
                  pasuli_vartype v,
                  pasuli_consttype *constants,
                  PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descLawsonBottle)
#endif

#endif