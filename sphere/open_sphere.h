#ifndef __PASULI_OPEN_SPHERE__
#define __PASULI_OPEN_SPHERE__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_OPEN_SPHERE != 0)
void OpenSphere(pasuli_vartype u,
			   pasuli_vartype v,
			   pasuli_consttype *constants,
			   PaSuLiObject *pO);
#endif

#endif