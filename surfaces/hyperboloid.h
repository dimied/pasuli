#ifndef __PASULI_HYPERBOLOID__
#define __PASULI_HYPERBOLOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HYPERBOLOID != 0)
void Hyperboloid(pasuli_vartype u,
                 pasuli_vartype v,
                 pasuli_consttype *constants,
                 PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descHyperboloid)
#endif

#endif