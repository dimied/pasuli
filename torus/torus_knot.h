#ifndef __PASULI_TORUS_KNOT__
#define __PASULI_TORUS_KNOT__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descTorusKnot;

#if (USE_TORUS_KNOT != 0)
void TorusKnot(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif