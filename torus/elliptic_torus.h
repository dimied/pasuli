#ifndef __PASULI_ELLIPTIC_TORUS__
#define __PASULI_ELLIPTIC_TORUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descEllipticTorus;

#if (USE_ELLIPTIC_TORUS != 0)
void EllipticTorus(pasuli_vartype u,
				   pasuli_vartype v,
				   pasuli_consttype *constants,
				   PaSuLiObject *pO);
#endif

#endif