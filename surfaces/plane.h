#ifndef __PASULI_PLANE__
#define __PASULI_PLANE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_PLANE != 0)
void Plane(double u, double v, double* constants, PaSuLiObject* pParticles);
#endif

extern char *descPlane;

extern PaSuLiDefDesc pslddPlane;

#endif