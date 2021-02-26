#ifndef __PASULI_SPINNER__
#define __PASULI_SPINNER__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_SPINNER != 0)
void Spinner(pasuli_vartype u, pasuli_vartype v,
             pasuli_consttype *constants,
             PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descSpinner)
#endif

#endif