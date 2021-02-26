#ifndef __PASULI_AGNESI_CURL__
#define __PASULI_AGNESI_CURL__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_AGNESI_CURL != 0)
void AgnesiCurl(pasuli_vartype u, 
                pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descAgnesiCurl)
#endif

#endif