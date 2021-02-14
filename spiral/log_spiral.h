#ifndef __PASULI_LOG_SPIRAL__
#define __PASULI_LOG_SPIRAL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_LOG_SPIRAL != 0)
void LogSpiral(pasuli_vartype u,
			   pasuli_vartype v,
			   pasuli_consttype *constants,
			   PaSuLiObject *pO);
#endif

#endif