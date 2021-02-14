#ifndef __PASULI_NETHROID_TORUS_1__
#define __PASULI_NETHROID_TORUS_1__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descNethroidTorus1;

#if (USE_NETHROID_TORUS_1 != 0)
void NethroidTorus1(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif