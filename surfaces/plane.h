#ifndef __PASULI_PLANE__
#define __PASULI_PLANE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PLANE != 0)
void Plane(pasuli_vartype u,
           pasuli_vartype v,
           pasuli_consttype *constants,
           PaSuLiObject *pParticles);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descPlane)
#endif

extern PaSuLiDefDesc pslddPlane;

#endif