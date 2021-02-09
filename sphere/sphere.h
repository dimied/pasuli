#ifndef __PARAMETRIC_SURFACE_LIBRARY_SPHERE_DECLARATIONS__
#define __PARAMETRIC_SURFACE_LIBRARY_SPHERE_DECLARATIONS__

#include "../pasuli_cfg.h"
#include "../pasuli_defs.h"
#include <math.h>


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


#endif



