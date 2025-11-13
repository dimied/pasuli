#ifndef __PASULI_ELLIPSOID__
#define __PASULI_ELLIPSOID__

#include "../pasuli_conf/pasuli_cfg.h"
#include "../pasuli_common/pasuli_defs.h"

#if (USE_ELLIPSOID != 0)
void Ellipsoid(pasuli_vartype u,
			   pasuli_vartype v,
			   pasuli_consttype *constants,
			   PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SPHERE != 0)
HEADER_DESC_PTR(descEllipsoid)
#endif

#endif