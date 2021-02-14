#ifndef __PASULI_GAUSS_CYLINDER__
#define __PASULI_GAUSS_CYLINDER__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_GAUSS_CYLINDER != 0)
void GaussCylinder(pasuli_vartype u,
							pasuli_vartype v,
							pasuli_consttype *constants,
							PaSuLiObject *pO);
#endif

#endif