#ifndef __PASULI_SKIDAN_RULED_SURFACE__
#define __PASULI_SKIDAN_RULED_SURFACE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SKIDAN_RULED_SURFACE != 0)
void SkidanRuledSurface(pasuli_vartype u, 
                pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descSkidanRuledSurface)
#endif

#endif