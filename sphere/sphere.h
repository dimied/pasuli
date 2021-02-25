#ifndef __PASULI_SPHERE__
#define __PASULI_SPHERE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SPHERE != 0)
void Sphere(pasuli_vartype u,
			pasuli_vartype v,
			pasuli_consttype *constants,
			PaSuLiObject *pO);
#endif

#endif
