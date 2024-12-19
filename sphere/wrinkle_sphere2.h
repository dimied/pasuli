#ifndef __PASULI_WRINKLE_SPHERE2__
#define __PASULI_WRINKLE_SPHERE2__

#include "../pasuli_conf/pasuli_cfg.h"
#include "../pasuli_common/pasuli_defs.h"

#if (USE_WRINKLE_SPHERE2 != 0)
void WrinkleSphere2(pasuli_vartype u,
                    pasuli_vartype v,
                    pasuli_consttype *constants,
                    PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SPHERE != 0)
HEADER_DESC_PTR(descWrinkleSphere2)
#endif

#endif