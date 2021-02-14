#ifndef __PASULI_HYPOZYKLOID_CYLINDER__
#define __PASULI_HYPOZYKLOID_CYLINDER__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HYPOZYKLOID_CYLINDER != 0)
void HypozykloidCylinder(pasuli_vartype u, pasuli_vartype v,
						 pasuli_consttype *constants,
						 PaSuLiObject *pO);
#endif

#endif