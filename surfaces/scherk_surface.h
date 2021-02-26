#ifndef __PASULI_SCHERK_SURFACE__
#define __PASULI_SCHERK_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SCHERK_SURFACE != 0)
void ScherkSurface(pasuli_vartype u, pasuli_vartype v,
                   pasuli_consttype *constants,
                   PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descScherkSurface)
#endif

#endif