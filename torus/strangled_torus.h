#ifndef __PASULI_STRANGLED_TORUS__
#define __PASULI_STRANGLED_TORUS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

extern char *descStrangledTorus;

#if (USE_STRANGLED_TORUS != 0)
void StrangledTorus(pasuli_vartype u,
					pasuli_vartype v,
					pasuli_consttype *constants,
					PaSuLiObject *pO);
#endif

#endif