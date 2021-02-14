#ifndef __PASULI_NATICA_STELLATA__
#define __PASULI_NATICA_STELLATA__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_NATICA_STELLATA != 0)
void NaticaStellata(pasuli_vartype u,
                    pasuli_vartype v,
                    pasuli_consttype *constants,
                    PaSuLiObject *pO);
#endif

#endif