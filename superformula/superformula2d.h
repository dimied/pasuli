#ifndef __SUPERFORMULA_2D_PARAMETRIC_SURFACE_
#define __SUPERFORMULA_2D_PARAMETRIC_SURFACE_

#include "../pasuli_defs.h"

typedef struct _SF_2D {

	char* desc;
	float a;
	float b;
	float m;
	float n1;
	float n2;
	float n3;
} SF_2D;

/*
template<class Type>
struct SF_2D_Template {

	char* desc;
	Type a;
	Type b;
	Type m;
	Type n1;
	Type n2;
	Type n3;
};


typedef struct SF_2D_Template<float> SF_2D;


template<class Type, class CalcType>
void TorusWithSuperFormulaTemplate(Particle *pParticle,
						   Type phi, Type rho, Type radius,
						   SF_2D *p2DSuperFormula);
*/


////typedef struct {
////
////	char* pSrcInit;
////	char* pSrcPos;
////	char* pSrcUD;
////	char* pSrcVD;
////	char* pSrcN;
////	char* pSrcUUD;
////	char* pSrcUVD;
////	char* pSrcVVD;
////} ShaderSources;

//extern ShaderSources sf_2d_ogl_ShaderSources;

#endif


