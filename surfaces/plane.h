#ifndef __PASULI_PLANE__
#define __PASULI_PLANE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PLANE != 0)
void Plane(pasuli_vartype u, pasuli_vartype v, double* constants, PaSuLiObject* pParticles);
#endif

extern char *descPlane;

extern PaSuLiDefDesc pslddPlane;

#endif