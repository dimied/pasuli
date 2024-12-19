#ifndef __PASULI_OPEN_SPHERE__
#define __PASULI_OPEN_SPHERE__

#include "../pasuli_conf/pasuli_cfg.h"
#include "../pasuli_common/pasuli_defs.h"

#if (USE_OPEN_SPHERE != 0)
void OpenSphere(pasuli_vartype u,
			   pasuli_vartype v,
			   pasuli_consttype *constants,
			   PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SPHERE != 0)
HEADER_DESC_PTR(descOpenSphere)
#endif

#endif