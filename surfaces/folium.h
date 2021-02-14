#ifndef __PASULI_FOLIUM__
#define __PASULI_FOLIUM__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_FOLIUM != 0)
void Folium(double u, double v,
			double *constants,
			PaSuLiObject *pO);
#endif

#endif