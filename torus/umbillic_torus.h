#ifndef __PASULI_UMBILLIC_TORUS__
#define __PASULI_UMBILLIC_TORUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_UMBILLIC_TORUS != 0)
void UmbillicTorus(pasuli_vartype u,
                   pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_TORUS != 0)
HEADER_DESC_PTR(descUmbillicTorus)
#endif

#endif