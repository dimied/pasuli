#ifndef __PASULI_GERONO_LEMNISKATE_TORUS_2__
#define __PASULI_GERONO_LEMNISKATE_TORUS_2__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_GERONO_LEMNISKATE_TORUS_2 != 0)
void GeronoLemniskateTorus2(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descGeronoLemniskateTorus2)
#endif

#endif