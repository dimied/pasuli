#ifndef __PASULI_UMBILLIC_TORUS__
#define __PASULI_UMBILLIC_TORUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"
#include "../pasuli_macros.h"

#if (USE_UMBILLIC_TORUS != 0)
void UmbillicTorus(pasuli_vartype u, pasuli_vartype v,
                   pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#endif