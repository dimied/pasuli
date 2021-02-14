#ifndef __PASULI_SPHERE_V__
#define __PASULI_SPHERE_V__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SPHERE_V != 0)
void SphereV(pasuli_vartype u,
			   pasuli_vartype v,
			   pasuli_consttype *constants,
			   PaSuLiObject *pO);
#endif

#endif