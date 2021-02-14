#ifndef __PASULI_HANDKERCHIEF__
#define __PASULI_HANDKERCHIEF__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HANDKERCHIEF != 0)
void Handkerchief(pasuli_vartype u, pasuli_vartype v,
                  pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#endif