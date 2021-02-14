#ifndef __PASULI_LEMNISKATE_TORUS_2__
#define __PASULI_LEMNISKATE_TORUS_2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descLemniskateTorus2;

#if (USE_LEMNISKATE_TORUS_2 != 0)
void LemniskateTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif