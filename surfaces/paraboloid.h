#ifndef __PASULI_PARABOLOID__
#define __PASULI_PARABOLOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PARABOLOID != 0)
void Paraboloid(pasuli_vartype u, pasuli_vartype v,
                pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descParaboloid)
#endif

#endif