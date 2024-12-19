#ifndef __PASULI_SPHERE_UV__
#define __PASULI_SPHERE_UV__

#include "../pasuli_conf/pasuli_cfg.h"
#include "../pasuli_common/pasuli_defs.h"

#if (USE_SPHERE_UV != 0)
void SphereUV(pasuli_vartype u,
			   pasuli_vartype v,
			   pasuli_consttype *constants,
			   PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SPHERE != 0)
HEADER_DESC_PTR(descSphereUV)
#endif

#endif