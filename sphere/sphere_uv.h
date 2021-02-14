#ifndef __PASULI_SPHERE_UV__
#define __PASULI_SPHERE_UV__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SPHERE_UV != 0)
void SphereUV(pasuli_vartype u,
			   pasuli_vartype v,
			   pasuli_consttype *constants,
			   PaSuLiObject *pO);
#endif

#endif