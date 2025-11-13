#ifndef __PASULI_FOLIUM__
#define __PASULI_FOLIUM__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_FOLIUM != 0)
void Folium(pasuli_vartype u, pasuli_vartype v,
			pasuli_consttype *constants,
			PaSuLiObject *pO);
#endif

#if (COMPILE_DESC_SURFACES != 0)
HEADER_DESC_PTR(descFolium)
#endif

#endif