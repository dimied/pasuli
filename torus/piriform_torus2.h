#ifndef __PASULI_PIRIFORM_TORUS_2__
#define __PASULI_PIRIFORM_TORUS_2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descPiriformTorus2;

#if (USE_PIRIFORM_TORUS_2 != 0)
void PiriformTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif