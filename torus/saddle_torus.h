#ifndef __PASULI_SADDLE_TORUS__
#define __PASULI_SADDLE_TORUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descSaddleTorus;

#if (USE_SADDLE_TORUS != 0)
void SaddleTorus(pasuli_vartype u,
				 pasuli_vartype v,
				 pasuli_consttype *constants,
				 PaSuLiObject *pO);
#endif

#endif