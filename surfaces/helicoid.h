#ifndef __PASULI_HELICOID__
#define __PASULI_HELICOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_HELICOID != 0)
void Helicoid(pasuli_vartype u, pasuli_vartype v,
              pasuli_consttype *constants, PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descHelicoid)
#endif

#endif