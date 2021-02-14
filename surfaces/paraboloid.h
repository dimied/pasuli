#ifndef __PASULI_PARABOLOID__
#define __PASULI_PARABOLOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PARABOLOID != 0)
void Paraboloid(pasuli_vartype u, pasuli_vartype v,
                pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#endif