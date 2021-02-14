#ifndef __PASULI_NETHROID_TORUS_2__
#define __PASULI_NETHROID_TORUS_2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descNethroidTorus2;

#if (USE_NETHROID_TORUS_2 != 0)
void NethroidTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif