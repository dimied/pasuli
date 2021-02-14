#ifndef __PASULI_GERONO_LEMNISKATE_TORUS_1__
#define __PASULI_GERONO_LEMNISKATE_TORUS_1__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descGeronoLemniskateTorus1;

#if (USE_GERONO_LEMNISKATE_TORUS_1 != 0)
void GeronoLemniskateTorus1(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif