#ifndef __PASULI_ELLIPSOID__
#define __PASULI_ELLIPSOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_ELLIPSOID != 0)
void Ellipsoid(pasuli_vartype u,
			   pasuli_vartype v,
			   pasuli_consttype *constants,
			   PaSuLiObject *pO);
#endif

#endif