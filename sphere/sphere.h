#ifndef __PARAMETRIC_SURFACE_LIBRARY_SPHERE_DECLARATIONS__
#define __PARAMETRIC_SURFACE_LIBRARY_SPHERE_DECLARATIONS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"

#if(COMPILE_SPHERE != 0)
void Sphere(double u, double v, double* constants, PaSuLiObject* pO);

void Ellipsoid(double u, double v, double* constants, PaSuLiObject* pO);

void SphereV(double u, double v, double* constants, PaSuLiObject* pO);

void OpenSphere(double u, double v, double* constants, PaSuLiObject* pO);

void SphereUV(double u, double v, double* constants, PaSuLiObject* pO);

void TwistedSphere(double u, double v, 
				   double* constants, PaSuLiObject* pO);

void WaveSphere(double u, double v, double* constants, PaSuLiObject* pO);

void PseudoSphere(double u, double v, 
					double* constants, PaSuLiObject* pO);
#endif


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
