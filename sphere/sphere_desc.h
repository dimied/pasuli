#ifndef __PARAMETRIC_SURFACE_LIBRARY_SPHERE_DESCRIPTIONS__
#define __PARAMETRIC_SURFACE_LIBRARY_SPHERE_DESCRIPTIONS__

#include "../pasuli_defs.h"
#include "../pasuli_cfg.h"

#if(COMPILE_DESC_SPHERE != 0)
extern char* descSphere;
extern char* descEllipsoid;
extern char* descSphereV;
extern char* descOpenSphere;
extern char* descSphereUV;
extern char* descTwistedSphere;
extern char* descWaveSphere;
extern char* descPseudoSphere;
#endif

#if(COMPILE_DEF_DESC_SPHERE != 0)
extern PaSuLiDefDesc pslddSphere;
extern PaSuLiDefDesc pslddEllipsoid;
extern PaSuLiDefDesc pslddSphereV;
extern PaSuLiDefDesc pslddOpenSphere;
extern PaSuLiDefDesc pslddSphereUV;
extern PaSuLiDefDesc pslddTwistedSphere;
extern PaSuLiDefDesc pslddWaveSphere;
extern PaSuLiDefDesc pslddPseudoSphere;
#endif


#endif


