
#include "../pasuli_const.h"
#include "../pasuli_macros.h"
#include "spiral.h"

#pragma warning(disable:4244)


#if(COMPILE_SPIRAL != 0)
void ArchimedicSpiral(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( ARCHIMEDIC_SPIRAL )

	P_X( u*cos(u) );
	P_Y( v*(*constants) );
	P_Z( sin(u) );
}
#endif

#if(COMPILE_SPIRAL != 0)
void HyperbolicSpiral(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( HYPERBOLIC_SPIRAL )
	double cu;
	double su;

	if(u > 0.001f) {
		cu = cos(u)/u;
		su = sin(u)/u;
	} else {
		cu = 0;
		su = 1;
	}

	P_X( cu );
	P_Y( v*(*constants) );
	P_Z( su );
}
#endif




#if(COMPILE_SPIRAL != 0)
void FermatSpiral(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( FERMAT_SPIRAL )

	P_X( sqrt(u)*cos(u) );
	P_Y( v*(*constants) );
	P_Z( sqrt(u)*sin(u) );
}
#endif



#if(COMPILE_SPIRAL != 0)
void TanhSpiral(double u, double v, 
			   double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TANH_SPIRAL )

	double x_u;
	double z_u;
	double a = constants[0];
	double H = constants[1];

		if(u > 0) {
			u *= 2.0;
			z_u = cos(a*u) + cosh(u);
			x_u = sin(u)/z_u;
			z_u = sin(a*u)/z_u;

		} else {
			x_u = 0;
			z_u = 0;
		}

	P_X( x_u );
	P_Y( H*v );
	P_Z( z_u );
}
#endif



#if(COMPILE_SPIRAL != 0)
void LogSpiral(double u, double v, 
			   double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( LOG_SPIRAL )

	double a = constants[0];
	double H = constants[1];
	double x_u = exp(a*u)*cos(u);
	double eau_su = exp(a*u)*sin(u);

	P_X( x_u );
	P_Y( H*v );
	P_Z( eau_su );
}
#endif


