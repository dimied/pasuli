#ifndef __PASULI_ASTROIDAL_ELLIPSOID__
#define __PASULI_ASTROIDAL_ELLIPSOID__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if (USE_ASTROIDAL_ELLIPSOID != 0)
void AstroidalEllipsoid(pasuli_vartype u, 
                pasuli_vartype v,
                pasuli_consttype *constants,
                PaSuLiObject *pO);
#endif

#endif