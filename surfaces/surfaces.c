

#include "surfaces.h"
//#include "../../particle.h"
#include "../pasuli_defs.h"
#include "../pasuli_macros.h"
#include <math.h>

#pragma warning(disable:4244)

#if(COMPILE_SURFACES != 0)

void BohemianDomeSurface(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( BOHEMIAN_DOME_SURFACE )
	double a = constants[0];
	double b = constants[1];
	double c = constants[2];

	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);

	P_X( a*cu );
	P_Y( b*cv + a*su );
	P_Z( c*sv );

	UD_X( -a*su );
	UD_Y( a*cu );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( -b*sv );
	VD_Z( c*cv );

	N_X( a*c*cu*cv );
	N_Y( -a*c*su*cv );
	N_Z( a*b*su*cv );

	UUD_X( -a*cu );
	UUD_Y( -a*su );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( -b*cv );
	VVD_Z( -c*sv );
}


#if(COMPILE_SURFACES != 0)
void BoysSurface(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( BOYS_SURFACE )

	double a = sqrt(2.0);
	double b = 2 - a*sin(3*u)*sin(2*v);
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
	double xz1, xz2;


	xz1 = a*cv*cv;
	xz2 = cu*sin(2*v)/b;
	P_X( xz1*cos(2*u) + xz2 );
	P_Y( 3*cv*cv/b );
	P_Z( xz1*sin(2*u) + xz2 );

	UD_X( -su );
	UD_Y( cu );
	UD_Z_CONST( 0 );

	VD_X_CONST( 0 );
	VD_Y( -sv );
	VD_Z( cv );

	N_X( cu*cv );
	N_Y( -su*cv );
	N_Z( su*cv );

	UUD_X( -cu );
	UUD_Y( -su );
	UUD_Z_CONST( 0 );

	UVD_X_CONST( 0 );
	UVD_Y_CONST( 0 );
	UVD_Z_CONST( 0 );

	VVD_X_CONST( 0 );
	VVD_Y( cv );
	VVD_Z( sv );
}
#endif


#if(COMPILE_SURFACES != 0)
void CrossCup(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID(CROSS_CUP)

	double u2 = u*u;
	double sqrtu = sqrt((1- u2)* 0.5f)*u;

	double sv = sin(v);
	double sinv2 = sv*sv;

	P_X( 1 - u2 + u2*sinv2 );
	P_Y( u2*sinv2 + 2*u2*sin(v)*cos(v) );
	P_Z( sqrtu *(sin(v) + cos(v)) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
#endif
	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 ); 
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif


#if(COMPILE_SURFACES != 0)
void DiniSurface(double u, double v, 
				double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( DINI_SURFACE )

	double a = constants[0];
	double b = constants[1];
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);

	P_X( a*cu*sv );
	P_Y( a*su*sv );
	P_Z( a*(cv + log(tan(v*0.5))) + b*u );

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif




#if(COMPILE_SURFACES != 0)
void EnneperSurface(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( ENNEPER_SURFACE )

	double u2 = u*u;
	double v2 = v*v;

	P_X( u - (u2*u/3) + u*v2 );
	P_Y( v - (v2*v/3) + v*u2 );
	P_Z( u2 - v2 );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif




#if(COMPILE_SURFACES != 0)
void Handkerchief(double u, double v, double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( HANDKERCHIEF )

	double u2 = u*u;
	double v2 = v*v;

	P_X( u );
	P_Y( v );
	P_Z( (u2*u/3) + u*v2 * 2*(u2 - v2) );

	UD_X_CONST( 1 );
	UD_Y_CONST( 0 );
	UD_Z( 0 );

	VD_X_CONST( 0 );
	VD_Y_CONST( 1 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif


#if(COMPILE_SURFACES != 0)
void KleinBottleSurface(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( KLEIN_BOTTLE_SURFACE )

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif



#if(COMPILE_SURFACES != 0)
void MoebiusBand(double u, double v, 
				double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( MOEBIUS_BAND )

	double r = constants[0];
	double s_cost = u*cos(v*0.5f);
	s_cost += r;

	P_X( s_cost*cos(v) );
	P_Y( s_cost*sin(v) );
	P_Z( u * sin(v * 0.5f) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif




#if(COMPILE_SURFACES != 0)
void MonkeySaddle(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( MONKEY_SADDLE )

	P_X( u );
	P_Y( v );
	P_Z( u*u*u - 3*u*v*v );

	UD_X( 1 );
	UD_Y( 0 );
	UD_Z( 3*u*u - 3*v*v );

	VD_X( 0 );
	VD_Y( 1 );
	VD_Z( -6*u*v );

	N_X( 2*v*v - 2*u*u );
	N_Y( -6*u*v );
	N_Z( 1 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 6*u );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( -6*v );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( -6*u );
}
#endif




#if(COMPILE_SURFACES != 0)
void PlueckerConoid(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( PLUECKER_CONOID )

	double xz = 1 - v*v;
	P_X( u * sqrt(xz) );
	P_Y( u * v );
	P_Z( xz );

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif


#if(COMPILE_SURFACES != 0)
void RomanSurface(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( ROMAN_SURFACE );

	double u_sqrt = sqrt(1 - u*u);
	double cv = cos(v);
	double sv = sin(v);

	P_X( 2*u*cv*u_sqrt );
	P_Y( 2*u*sv*u_sqrt );
	P_Z( 1 - 2*u*u*cv*cv );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 ); 

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif



#if(COMPILE_SURFACES != 0)
void ShoeSurface(double u, double v, 
				double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SHOE_SURFACE )

	P_X( u );
	P_Y( v );
	P_Z( (u*u*u)*0.5 - (v*v)*0.5 );

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif




#if(COMPILE_SURFACES != 0)
void SineSurface(double u, double v, 
				double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SINE_SURFACE )

	double su = sin(u);
	double sv = sin(v);
	double suv = sin(u+v);

	P_X( su );
	P_Y( sv );
	P_Z( suv );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double cv = cos(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif




#if(COMPILE_SURFACES != 0)
void SteinbachScrew(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( STEINBACH_SCREW )

	double cv = cos(v);
	double sv = sin(v);
	double cu = cos(u);

	P_X( u*cv );
	P_Y( u*sv );
	P_Z( v*cu );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double su = sin(u);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif




#if(COMPILE_SURFACES != 0)
void WhitneyUmbrella(double u, double v, 
					 double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( WHITNEY_UMBRELLA )

	P_X( u*v );
	P_Y( u );
	P_Z( v*v );

	UD_X( v ); 
	UD_Y_CONST( 1 );
	UD_Z_CONST( 0 );

	VD_X( u );
	VD_Y_CONST( 0 );
	VD_Z( 2*v );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif




#if(COMPILE_SURFACES != 0)
void Catenoid(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( CATENOID )

	double c = constants[0];

	double cdc = cosh(v / c);

	P_X( cos(u)*cdc );
	P_Y( sin(u)*cdc );
	P_Z( v );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif



#if(COMPILE_SURFACES != 0)
void Helicoid(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( HELICOID )

	double c = constants[0];
	double cv = cos(v);
	double sv = sin(v);

	P_X( u*cv );
	P_Y( u*sv );
	P_Z( c*v );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif



#if(COMPILE_SURFACES != 0)
void Paraboloid(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( PARABOLOID )

	double a = constants[0];
	double b = constants[1];
	double acu = a*cos(u);
	double asu = a*sin(u);

	P_X( acu*v );
	P_Y( asu*v );
	P_Z( b*v*v );

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif


#if(COMPILE_SURFACES != 0)
void HyperbolicHelicoid(double u, double v, 
						double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( HYPERBOLIC_HELICOID )

	double a = constants[0];

	double cosh_uv = 1.0 + cosh(u)*sinh(v);
	double ua = u*a;

	P_X( (sinh(v)*cos(ua))/cosh_uv );
	P_Y( (sinh(v)*sin(ua))/cosh_uv );
	P_Z( cosh(v)*sinh(u) / cosh_uv );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif




#if(COMPILE_SURFACES != 0)
void Funnel(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( FUNNEL )

	double cv = cos(v);
	double sv = sin(v);

	P_X( u*cv );
	P_Y( u*sv );
	P_Z( log(u) );

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 ); 
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif




#if(COMPILE_SURFACES != 0)
void Tractroid(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TRACTROID )

	double sech_u = 1.0f / cosh(u);
	double cv = cos(v);
	double sv = sin(v);

	P_X( sech_u*cv );
	P_Y( sech_u*sv );
	P_Z( u - tanh(u) );

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif



#if(COMPILE_SURFACES != 0)
void CatalansSurface(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( CATALANS_SURFACE )

	double chv = cosh(v);
	double cu = cos(u);
	double su = sin(u);

	P_X( u - chv*sin(u) );
	P_Y( 1 - cos(u)*chv );
	P_Z( -4.0f*sin(u*0.5)*sinh(v*0.5) );

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif



#if(COMPILE_SURFACES != 0)
void Hyperboloid(double u, double v, 
				double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( HYPERBOLOID )

	double a = constants[0];
	double b = constants[1];

	double cosh_v = cosh(v);
	double acu = a*cos(u);
	double asu = a*sin(u);

	P_X( asu*cosh_v );
	P_Y( acu*cosh_v );
	P_Z( b*sinh(v) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif



#if(COMPILE_SURFACES != 0)
void HennebergsSurface(double u, double v, 
						double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( HENNEBERGS_SURFACE )

	double sinh_u_2 = 2*sinh(u);
	double sinh_3u_2 = 2*sinh(3.0*u);
	double cv = cos(v);
	double sv = sin(v);
	double c3v = cos(3.0*v);
	double s3v = sin(3.0*v);

	P_X( cv*sinh_u_2 - (c3v*sinh_3u_2)/3.0 );
	P_Y( sv*sinh_u_2 + (s3v*sinh_3u_2)/3.0 );
	P_Z( cos(2*v)*2*cosh(2.0*u) );

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 ); 

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif




#if(COMPILE_SURFACES != 0)
void SwallowSurface(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SWALLOW_SURFACE )

	double v2 = v*v;

	P_X( u*v2 + 3.0*v2*v2 );
	P_Y( -2*u*v - 4.0*v*v2 );
	P_Z( u );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif



#if(COMPILE_SURFACES != 0)
void WallisConicalSurface(double u, double v, 
							double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( WALLIS_CONICAL_SURFACE )

	double a2 = constants[0];
	double b2 = constants[1];
	double c = constants[2];
	double cu = cos(u);

	P_Y( v*sin(u) );
	P_X( v*cu );
	P_Z( c*sqrt(a2*a2 - b2*b2*cu*cu) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif



#if(COMPILE_SURFACES != 0)
void MaedersOwl(double u, double v, 
				double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( MAEDERS_OWL )

	double v2 = v*v;

	P_X( v*cos(u) - 0.5*v2*cos(2*u) );
	P_Y( -v*sin(u) - 0.5*v2*sin(2*u) );
	P_Z( (4*exp(3*log(v)*0.5)*cos(3*u*0.5)) / 3.0 );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif



#if(COMPILE_SURFACES != 0)
void RichmondSurface(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( RICHMOND_SURFACE )

	double u2 = u*u;
	double u3 = u2*u;
	double u4 = u2*u2;

	double v2 = v*v;
	double v3 = v2*v;
	double divisor = 6.0*(u2 + v2);

	P_X( ((-3.0)*u - u2*u3 + 2.0*u3*v2 + 3.0*u*v2*v2)/divisor );
	P_Y( (-3.0*v - 3.0*u4*v - 2*u2*v3 + v2*v3)/divisor );
	P_Z( u );

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}
#endif



void ScherkSurface(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SCHERK_SURFACE )

	double c = constants[0];

	P_X( u ); 
	P_Y( v );
	P_Z( log(cos(c*u)/cos(c*v)) / c );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void CosineSurface(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( COSINE_SURFACE )

	double cu = cos(u);
	double cv = cos(v);

	P_X( cu );
	P_Y( cv );
	P_Z( cos(u + v) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double su = sin(u);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void EightSurface(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( EIGHT_SURFACE )

	double su = sin(u);
	double cu = cos(u);

	P_X( cu*sin(2*v) );
	P_Y( su*sin(2*v) );
	P_Z( sin(v) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void JetSurface(double u, double v, 
				double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( JET_SURFACE )

	double sin_u = sin(u)*(1 - cosh(u))*0.5;
	double cv = cos(v);
	double sv = sin(v);

	P_X( sin_u*cv );
	P_Y( sin_u*sv );
	P_Z( cosh(u) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void Drop(double u, double v, 
			double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( DROP )

	double a = constants[0];
	double b = constants[1];

	double cu = cos(u);
	double su = sin(u);
	double ab_cos_u_sin_u = a*(b - cu)*su;
	double cv = cos(v);
	double sv = sin(v);

	P_X( ab_cos_u_sin_u*cv );
	P_Y( ab_cos_u_sin_u*sv );
	P_Z( cu );

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void TriaxialTeardrop(double u, double v, 
						double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TRIAXIAL_TEARDROP )

	double cos_u_prepared = (1 - cos(u))*cos(u + 2*MY_PI/3.0)*0.5;

	P_X( cos_u_prepared*cos(v + 2*MY_PI/3.0) );
	P_Y( cos_u_prepared*cos(v - 2*MY_PI/3.0) );
	P_Z( cos(u - 2*MY_PI/3.0) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 ); 
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void PillowShape(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( PILLOW_SHAPE )

	double a = constants[0];

	P_X( cos(u) );
	P_Y( cos(v) );
	P_Z( a*sin(u)*sin(v) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void FishSurface(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( FISH_SURFACE )

	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);

	P_X( (cu - cos(2*u))*0.25*cv );
	P_Y( (sin(u) - sin(2*u))*0.25*sv );
	P_Z( cu );

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void Horn(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( HORN )

	double a = constants[0];
	double b = constants[1];
	double c = constants[2];
	b *= MY_PI;

	double au_cos_v = a + u*cos(v);

	P_X( au_cos_v*sin(b*u) );
	P_Y( au_cos_v*cos(b*u) + c*u );
	P_Z( u*sin(v) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif
	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void BentHorns(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( BENT_HORNS )

	double cos_v_minus_1 = cos(v) - 1.0;

	P_X( (cos(u) + 2.0)*(v/3.0 - sin(v)) );
	P_Y( (2.0 + cos(u + 2*MY_PI/3.0))*cos_v_minus_1 );
	P_Z( (2.0 + cos(u - 2*MY_PI/3.0))*cos_v_minus_1 );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void HyperbolicOctahedron(double u, double v, 
							double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( HYPERBOLIC_OCTAHEDRON )

	double y_sincos = cos(v);
	double x_coscos = cos(u)*y_sincos;
	y_sincos *= sin(u);
	double sv = sin(v);

	P_X( x_coscos*x_coscos*x_coscos );
	P_Y( y_sincos*y_sincos*y_sincos );
	P_Z( sv*sv*sv );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
#endif
	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void PseudoCrossCap(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( PSEUDO_CROSS_CAP )

	double one_minus_usq = 1.0 - u*u;

	P_X( one_minus_usq*sin(v) );
	P_Y( one_minus_usq*sin(2*v) );
	P_Z( u );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void Cresent(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( CRESENT )

	double a = constants[0];
	double bpi = constants[1]*MY_PI;
	double cpi = constants[2]*MY_PI;

	double a_sinsin = a + sin(bpi*u)*sin(bpi*v);

	P_X( a_sinsin*sin(cpi*v) );
	P_Y( a_sinsin*cos(cpi*v) );
	P_Z( cos(bpi*u)*sin(bpi*v) + v*4.0 - 2.0 );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void StilettoSurface(double u, double v, 
						double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( STILETTO_SURFACE )

	double cos_v = cos(v);
	double cossin_v2pi3 = cos(v + 2.0*MY_PI/3.0)*sin(v + 2.0*MY_PI/3.0);
	cossin_v2pi3 *= cossin_v2pi3;

	P_X( (2.0 + cos(u))*cos_v*cos_v*cos_v*sin(v) );
	P_Y( (2.0 + cos(u + 2.0*MY_PI/3.0))*cossin_v2pi3 );
	P_Z( (-(2.0 + cos(u - 2.0*MY_PI/3.0)))*cossin_v2pi3 );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void KuensSurface(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( KUENS_SURFACE )

	double x_u = cos(u);
	double u_sq = sin(u);
	double y_u = 2.0*(u_sq - u*x_u);
	x_u = 2.0*(x_u + u*u_sq);
	u_sq = u*u;

	double sin_v = sin(v);
	double h = 1 + u_sq*sin_v*sin_v;

	P_X( x_u*sin_v/h );
	P_Y( y_u*sin_v/h );
	P_Z( log(tan(v*0.2)) + 2*cos(v)/h );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void TrefoilKnots(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TREFOIL_KNOTS )

	double Bx;
	double By;
	double Bz;
	double r_cos_u3;
	double r_sin_u3;
	double R = constants[0];
	double r = constants[1];

	r_cos_u3 = cos(u/3.0);
		r_sin_u3 = sin(u/3.0);
		By = R + r*cos(u*0.5);
		Bx = By*r_cos_u3;
		By = By*r_sin_u3;
		Bz = r + sin(u*0.5);
		r_cos_u3 *= r;
		r_sin_u3 *= r;

	double vpi = cos(v-MY_PI);

	P_X( Bx + r_cos_u3*vpi );
	P_Y( By + r_sin_u3*vpi );
	P_Z( Bz + r*sin(v - MY_PI) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif
	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void TranguloidTrefoil(double u, double v, 
						double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TRANGULOID_TREFOIL )

	double x_u = 2*sin(3.0*u);
	double y_u = 2*(sin(u) + 2*sin(2*u));
	double z_u = cos(u) - 2*cos(2*u);
		z_u *= 0.25;

	double cos_v_plus_2 = 2.0 + cos(v);

	P_X( x_u/cos_v_plus_2 );
	P_Y( y_u/(2 + cos(v + 2*MY_PI/3.0)) );
	P_Z( z_u*cos_v_plus_2*(2 + cos(v + 2*MY_PI/3.0)) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

#if(PARTICLE_N != 0)
	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );
#endif

#if(PARTICLE_UUD != 0)
	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );
#endif
#if(PARTICLE_UVD != 0)
	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );
#endif
#if(PARTICLE_VVD != 0)
	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
#endif
}


void Crown(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( CROWN )

	double cossin_u = cos(u)*sin(u);
	double cos_u4_3 = cos(u + 4.0)/3.0;
	u = 0.5*cos(u);
	double cossin_v = sin(v);
	v = cos(v);
	cossin_v *= v;


	P_X( cos_u4_3 );
	P_Y( cossin_u*cossin_v*v + u );
	P_Z( cossin_u*cossin_v );


#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void TwistedPipeSurface(double u, double v, 
						double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TWISTED_PIPE_SURFACE )

	double two_pi_3 = 2*MY_PI/3.0;

	double y_u = 2.0 + cos(u - two_pi_3);
	double z_u = 2.0 + cos(u + two_pi_3);
	u = 2.0 + cos(u);

	double h = sin(v);
	h = sqrt(1 + h*h);

	P_X( (u*cos(v))/h );
	P_Y( (sin(v - two_pi_3)*y_u)/h );
	P_Z( (sin(v + two_pi_3)*z_u)/h );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void Loop(double u, double v, 
			double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( LOOP )

	double cv = cos(v);
	double sv = sin(v);
	double cu = cos(u);

	P_X( sv*cu );
	P_Y( 2.0*sv*cv );
	P_Z( 4.0*sv*cv );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double su = sin(u);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void DupinCyclide(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( DUPIN_CYCLIDE )

	double a = constants[0];
	double b = constants[1];
	double c = constants[2];
	double d = constants[3];

	double b_sin_u = b*sin(u);
		u = cos(u);
	double b2_cos_u = b*b*u;
	double c_cos_u = c*u;
		u *= a;

	double bsin_v = b*sin(v);
	v = cos(v);
	double h = a - c_cos_u*v;

	P_X( (d*(c - u*v) + b2_cos_u)/h );
	P_Y( (b_sin_u*(a - d*v))/h );
	P_Z( (bsin_v*(c_cos_u - d))/h );


#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void GuimardSurface(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( GUIMARD_SURFACE )

	double a = constants[0];
	double b = constants[1];
	double c = constants[2];
	double cv = cos(v);
	double sv = sin(v);

	P_X( ((1-u)*a + b*u)*cv );
	P_Y( b*u*sv );
	P_Z( c*u*sv*sv );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );

}


void MennsSurface(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( MENNS_SURFACE )

	double a = constants[0];
	double u2 = u*u;

	P_X( u );
	P_Y( v );
	P_Z( a*u2*u2 + u2*v - v*v );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void MilkBag(double u, double v, 
			double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( MILK_BAG )

	double K = constants[0];
	double cv = cos(v);
	double sv = sin(v);

	P_X( K*(1+u)*cos(v) );
	P_Y( K*(1-u)*sin(v) );
	P_Z( u );

	UD_X( K*cv );
	UD_Y( -K*sv );
	UD_Z( 1 );

	VD_X( -K*(1 + u)*sv );
	VD_Y( K*(1 - u)*cv );
	VD_Z( 0 );

	N_X( -K*(1 - u)*cv );
	N_Y( K*(1 + u)*sv );
	N_Z( K*K*(cv*cv*(1-u) + sv*sv*(1+u)) );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( -sv );
	UVD_Y( -cv );
	UVD_Z( 0 );

	VVD_X( -K*(1 + u)*cv );
	VVD_Y( -K*(1 + u)*sv );
	VVD_Z( 0 );
}


void TriaxialTritorus(double u, double v, 
						double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TRIAXIAL_TRITORUS )

	double two_pi_3 = (2.0*MY_PI)/3.0;
	double four_pi_3 = (4.0*MY_PI)/3.0;

	P_X( sin(u)*(1 + cos(v)) );
	P_Y( sin(u + two_pi_3)*(1 + cos(v + two_pi_3)) );
	P_Z( sin(u + four_pi_3)*(1 + cos(v + four_pi_3)) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void VerrillSurface(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( VERRILL_SURFACE )

	double cv2 = 2.0*cos(v);
	double cv3 = (cos(3.0*v)*-(2.0*u*u*u))/3.0;
	double sv2 = 2.0*sin(v);

	P_X( cv2/u - cv2 + cv3 );
	P_Y( 3.0*sv2 - sv2/u + cv3 );
	P_Z( 4.0*log(u) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void ZindlersConoid(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( ZINDLERS_CONOID )

	double a = constants[0];

	P_X( u*cos(v) );
	P_Y( u*sin(v) );
	P_Z( a*tan(2.0*v) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}




void Folium(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( FOLIUM )

	double two_pi_3 = 2.0*MY_PI/3.0;

	double y_u = cos(u + two_pi_3);
	double z_u = cos(u - two_pi_3);
	double cu = cos(u);
	double chv = cosh(v);

	P_X( cu*((2.0*v)/MY_PI - tanh(v)) );
	P_Y( y_u/chv );
	P_Z( z_u/chv );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void Lemniscape(double u, double v, 
				double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( LEMNISCAPE )

	double sqrt_abs_sin_2u_cos_u = sqrt((double)fabs(sin(2*u)));
	double sqrt_abs_sin_2u_sin_u = sqrt_abs_sin_2u_cos_u*sin(u);
	sqrt_abs_sin_2u_cos_u *= cos(u);

	double cos_v = cos(v);

	P_X( sqrt_abs_sin_2u_cos_u*cos_v );
	P_Y( sqrt_abs_sin_2u_sin_u*cos_v );
	P_Z( 2.0*pO->pos[0]*pO->pos[1]*tan(v) +
		pO->pos[0]*pO->pos[0] - 
		pO->pos[1]*pO->pos[1] );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void TriplePointTwist(double u, double v, 
						double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TRIPLE_POINT_TWIST )

	double c = constants[0];

	double v2 = v*v;
	double v3 = v2*v;

	P_X( u );
	P_Y( v3 + c*v );
	P_Z( u*v + v2*v3 + c*v3 );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void Trashcan(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TRASHCAN )

	double a = constants[0];
	double b = constants[1];

	double cu = cos(u);
	double su = sin(u);

	P_X( (b+v)*cu );
	P_Y( v*su );
	P_Z( a*v*v );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void Spring1(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SPRING1 )

	double R = constants[0];
	double r = constants[1];
	double L = constants[2];
	double N = constants[3];

	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	u = (L*u)/MY_PI;
	double Rrcv = v = R + r*cv;

	P_X( Rrcv*cu );
	P_Y( Rrcv*su );
	P_Z( r*sin(v + u) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void Spring2(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SPRING2 )

	double R = constants[0];
	double r = constants[1];
	double h = constants[2];
	double w = R*R + r*r;

	double rr_cos_u = R + r*cos(u);
	double rr_sin_u = R + r*sin(u);
	double rh_sin_u_w = r*h*sin(u)/w;
	double Rrsu = R*r*sin(u)/w;
	double cv = cos(v);
	double sv = sin(v);

	P_X( rr_cos_u*cv + rh_sin_u_w*sv );
	P_Y( rr_cos_u*sv + rh_sin_u_w*cv );
	P_Z( h*sv + Rrsu );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void Cone(double u, double v, 
			double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( CONE )

	double a = constants[0];
	double au = a*u;

	P_X( u );
	P_Y( au*cos(v) );
	P_Z( au*sin(v) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void Isolator(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( ISOLATOR )

	double a = constants[0];
	double b = constants[1];
	double c = constants[2];
	double fx = a + b*sin(c*u*2.0*MY_PI);

	P_X( u );
	P_Y( fx*sin(v) );
	P_Z( fx*cos(v) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void Egg(double u, double v, 
			double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( EGG )

	double a = constants[0];
	double b = constants[1];
	double c = constants[2];
	double fx = c*sqrt(u*(u-a)*(u-b));

	P_X( fx*sin(v) );
	P_Y( u );
	P_Z( fx*cos(v) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void HyperbolicParaboloid(double u, double v, 
							double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( HYPERBOLIC_PARABOLOID )


	P_X( u );
	P_Y( v );
	P_Z( u*v );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void DropSurface(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( DROP_SURFACE )

	double a = constants[0];

	double sin_ua = sin(u - a);
	double cu = cos(u);

	P_X( cu*cos(v) );
	P_Y( cu*sin(v) );
	P_Z( sin_ua );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void FacingSnail(double u, double v, 
				double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( FACING_SNAIL )

	double a = constants[0];
	double su = sin(u);
	double cu = cos(u);

	P_X( cu*cos(v) );
	P_Y( cu*sin(v) );
	P_Z( (1 - a*v)*su );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void PaperBag(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( PAPER_BAG )

	double a = constants[0];
	double b = constants[1];
	double su = sin(u);
	double cu = cos(u);

	P_X( v*cu );
	P_Y( (v + u*b)*su );
	P_Z( a*v*v );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void JeenerKleinSurface(double u, double v, 
						double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( JEENER_KLEIN_SURFACE )

	double Scos_u , Ssin_u;
	double cos_Su , sin_Su;
	double W_sin , W_cos;
	double W;
	double a = constants[0];
	double S = constants[1];
	double T = constants[2];

	a = sqrt(a);

	W = (S+1)*0.25*cos((S+1)*u + MY_PI/T) + a;
	Scos_u = S*cos(u);
	Ssin_u = S*sin(u);
	cos_Su = cos(S*u);
	sin_Su = sin(S*u);
	W_cos = W*cos((S-1)*u*0.5);
	W_sin = W*sin((S-1)*u*0.5);

	P_X( Scos_u + cos_Su - W_sin*cos(v) );
	P_Y( W*sin(v) );
	P_Z( Ssin_u - sin_Su - W_cos*cos(v) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void BonanJeenerKleinSurface(double u, double v, 
							double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( BONAN_JEENER_KLEIN_SURFACE )

	double M_cos_u_Mu;
	double M_sin_u_Mu;
	double MMW_sin_u2;
	double W;
	double M = constants[0];
	double T = constants[1];
	double cv = cos(v);
	double sv = sin(v);

	W = sin((M-1)*u) + T;
	M_cos_u_Mu = M*cos(u) - cos(M*u);
	M_sin_u_Mu = M*sin(u) - sin(M*u);
	u = (M+1)*u*0.5;
	MMW_sin_u2 = (((M-1)*W)/M)*sin(u);
	u = (((M-1)*W)/M)*cos(u);

	P_Y( W*sv );
	P_X( M_cos_u_Mu - cv*MMW_sin_u2 );
	P_Z( M_sin_u_Mu - cv*u );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void KleinCycloid(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( KLEIN_CYCLOID)

	double cos_uc_cos_ub;
	double sin_uc_cos_ub;
	double cos_ub;
	double sincos_v;
	double a = constants[0];
	double b = constants[1];
	double c = constants[2];

	cos_ub = cos(u/b);
	cos_uc_cos_ub = cos(u/c)*cos_ub;
	sin_uc_cos_ub = sin(u/c)*cos_ub;
	u = sin(u / b);

	sincos_v = sin(v)*cos(v);
	double acv = (a + cos(v));

	P_X( cos_uc_cos_ub*acv + u*sincos_v );
	P_Y( sin_uc_cos_ub*acv + u*sincos_v );
	P_Z( cos_ub*sincos_v - u*acv );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void DoubleCone(double u, double v, 
				double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( DOUBLE_CONE )

	double two_pi_div_3 = (2*MY_PI)/3.0;

	P_X( v*cos(u) );
	P_Y( (v-1)*cos(u + two_pi_div_3) );
	P_Z( (1-v)*cos(u - two_pi_div_3) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void HoleDisc(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( HOLE_DISC )

	double divisor = sqrt(2.0) + sin(v);
	double cu = cos(u);
	double su = sin(u);

	P_X( su/divisor );
	P_Y( cu/divisor );
	P_Z( cu/(sqrt(2.0) + 1.0) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void PisotTriaxial(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( PISOT_TRIAXIAL )

	P_X( 0.655866*cos(1.03002 + u)*(2 + cos(v)) );
	P_Y( 0.74878*cos(1.40772 - u)*(2 + 0.868837*cos(2.43773 + v)) );
	P_Z( 0.868837*cos(2.43773 + u)*(2 + 0.495098*cos(0.377696 - v)) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
//	double cv = cos(v);
//	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void TriaxialHexatorus(double u, double v, 
						double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TRIAXIAL_HEXATORUS )

	double two_pi_3 = (2*MY_PI)/3.0;
	double sqrt2 = sqrt(2.0);

	P_X( sin(u)/(sqrt2 + cos(v)) );
	P_Y( sin(u + two_pi_3)/(sqrt2 + cos(v + two_pi_3)) );
	P_Z( cos(u - two_pi_3)/(sqrt2 + cos(v - two_pi_3)) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void TwistedHeart(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TWISTED_HEART )

	double abs_u;
	double abs_v;
	double tanh_mum;
	double tanh_mvm;
	double cosh_mu;
	double m_inv = sqrt((double)2.0);

	abs_u = fabs((double)u);
	tanh_mum = fabs(tanh(u/m_inv)*m_inv);
	cosh_mu = cosh(u / m_inv);
	u = u*u;

	abs_v = fabs(v) - tanh_mum;
	tanh_mvm = fabs(tanh(v/m_inv)*m_inv) - abs_u;

	P_X( (abs_v - tanh_mvm)*sin(v) );
	P_Y( (abs_v + tanh_mvm)*cos(v) );
	P_Z( (u + v*v)/(m_inv*cosh_mu*cosh(v/m_inv)) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void HoleDiscus(double u, double v, 
				double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( HOLE_DISCUS )

	double a = constants[0];
	double b = constants[1];
	double sva = sin(v) + a;

	P_Y( cos(v)/b );
	P_X( sin(u)/sva );
	P_Z( cos(u)/sva );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void Disc(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( DISC )

	double cu = cos(u);
	double su = sin(u);

	P_X( v*cu );
	P_Y( 0 );
	P_Z( v*su );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void Waves(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( WAVES )

	double a = constants[0];
	double b = constants[1];
	double c = constants[2];

	P_X( u );
	P_Y( v );
	P_Z( a*cos(b*u)*cos(c*v) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void SineWave(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SINE_WAVE )

	double a = constants[0];
	double b = constants[1];

	P_X( u );
	P_Y( v );
	P_Z( a*sin(b*sqrt(u*u + v*v)) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void CosineWave(double u, double v, 
				double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( COSINE_WAVE )

	double a = constants[0];
	double b = constants[1];

	P_X( u );
	P_Y( v );
	P_Z( a*cos(b*sqrt(u*u + v*v)) );


	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void SpiralWave(double u, double v, 
				double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SPIRAL_WAVE )

	double a = constants[0];
	double b = constants[1];
	double c = constants[2];

	double cu = cos(u);
	double su = sin(u);

	P_X( v*cu );
	P_Y( a*cos(u*b + c*v) );
	P_Z( v*su );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void Bell(double u, double v, 
			double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( BELL )

	double a = constants[0];
	double b = constants[1];

	double emv  = b*exp(-(u*u + v*v)*a*a);

	P_X( u );
	P_Y( v );
	P_Z( emv );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void BellPolar(double u, double v, 
				double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( BELL_POLAR )

	double a = constants[0];
	double b = constants[1];
	double be = b*exp( -a*a*v*v);
	P_X( v*cos(u) );
	P_Y( v*sin(u) );
	//v = sqrt(v*cos(u)*v*cos(u) + v*sin(u)*v*sin(u)) = sqrt(v*v) = v
	P_Z( be );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void BellWave(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( BELL_WAVE )

	double a = constants[0];
	double b = constants[1];
	double c = constants[2];

	double eav = (u*u + v*v);
	double seav = sqrt(eav);
	eav *= -a*a;

	P_X( u );
	P_Z( v );
	P_Y( cos(c*seav)*b*eav );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void Soucoupoid(double u, double v, 
				double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SOUCOUPOID )

	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);

	P_X( cu*cv );
	P_Y( su*su*su );
	P_Z( cu*sv );

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void EnneperSurfacePolar(double u, double v, 
						double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( ENNEPER_SURFACE_POLAR )

	double cu = cos(u);
	double su = sin(u);

	double s = v*cu;
	double t = v*su;

	P_X( s*(1 + t*t - (s*s)/3.0) );
	P_Y( t*(1 + s*s - (t*t)/3.0) );
	P_Z( s*s - t*t );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void SineCone(double u, double v, 
			  double* constants, PaSuLiObject* pO) {

	double K = constants[0];
	double N = constants[1];

	P_X( u*cos(v) );
	P_Y( K*u*cos(N*v) );
	P_Z( u*sin(v) );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void Spinner(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SPINNER )

	double x_or_z = fabs(u) - 1.0;
	x_or_z *= x_or_z;
	double cv = cos(v);
	double sv = sin(v);

	P_X( x_or_z*cv );
	P_Y( u );
	P_Z( x_or_z*sv );

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void Fresnel(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( FRESNEL )

	double a = constants[0];
	double b = constants[1];
	double c = constants[2];
	double csq = c*c;
	double cca = csq/a;
	double ccb = csq/b;
	double cos_u_sq;
	double sin_u;
	double divisor;
	a *= a;
	b *= b;

	cos_u_sq = cos(u);
	cos_u_sq *= cos_u_sq;
	sin_u = sin(u)*ccb;
	u = cos_u_sq/a + (1- cos_u_sq)/b;
	cos_u_sq *= cca;

	divisor = sin(v);
	divisor *= divisor;
	divisor += csq*(1-divisor)*u;

	P_X( cos_u_sq/divisor );
	P_Y( (sin_u*cos(v))/divisor );
	P_Z( (c*sin(v))/divisor );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void TrefoilKnots2(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TREFOIL_KNOTS2 )

	double R = constants[0];
	double r = constants[1];
	double a = constants[2];
	double N = constants[3];
	double r_cos_u;
	double r_sin_u;
	double x_u;
	double z_u;
	double rcv = r*cos(v);

	r_cos_u = r*cos(u);
	r_sin_u = r*sin(u);
	z_u = R*(1 + a*cos(N*u));
	x_u = z_u*cos(u);
	z_u *= sin(u);
	u = a*sin(N*u);

	P_Y( r*sin(v) + u );
	P_X( rcv*r_cos_u + x_u );
	P_Z( rcv*r_sin_u + z_u );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void BowCurve(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( BOW_CURVE )

	double T = constants[0];

	u = 2.0*MY_PI*u;
	double cu = T*cos(u);
	double su = T*sin(u);
	double sv = sin(2*v);
	double cv = cos(2*v);
	double xy = 2.0 + su;

	P_X( xy*sv );
	P_Y( xy*cv );
	P_Z( cu + 3.0*cv );

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void TripleCorkScrew1(double u, double v, 
						double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TRIPLE_CORK_SCREW1 )

	double Lu;
	double y_u;
	double z_u;

	double R = constants[0];
	double r = constants[1];
	double L = constants[2];
	double N = constants[3];
	N *= MY_PI;

	Lu = L*u;
	y_u = cos(u*N);
	z_u = sin(u*N);
	u = (1 - fabs((double)u));
	y_u *= u*R;
	z_u *= u*R;
	u *= r;

	P_X( Lu );
	P_Y( u*cos(v) + y_u );
	P_Z( u*sin(v) + z_u );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}



void TripleCorkScrew2(double u, double v, 
						double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TRIPLE_CORK_SCREW2 )

	double Lu;
	double y_u;
	double z_u;
	double R = constants[0];
	double r = constants[1];
	double L = constants[2];
	double N = constants[3];
	double a = constants[4];
	double b = constants[5];
	N *= MY_PI;
	a *= a;
	b *= b;

	Lu = L*u;
	z_u = R*exp(-a*u*u);
	y_u = cos(u*N)*z_u;
	z_u *= sin(u*N);
	u = r*exp(-b*u*u);

	P_X( Lu );
	P_Y( u*cos(v) + y_u );
	P_Z( u*sin(v) + z_u );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void TripleCorkScrew3(double u, double v, 
						double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( TRIPLE_CORK_SCREW3 )

	double Lu;
	double y_u;
	double z_u;
	double R = constants[0];
	double r = constants[1];
	double L = constants[2];
	double N = constants[3];
	N *= MY_PI;

	Lu = L*u;
	z_u = R*cos(u*0.5*MY_PI);
	y_u = cos(u*N)*z_u;
	z_u *= sin(N*u);
	u = (1 - fabs((double)u))*r;

	P_X( Lu );
	P_Y( u*cos(v) + y_u );
	P_Z( u*sin(v) + z_u );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void BicornSurface(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( BICORN_SURFACE )

	double cu = cos(u);
	double su = sin(u);

	double sv = sin(v);
	double cv = cos(v);

	double sin_v = sv*sv + 3.0;

	P_X( sv*cu );
	P_Y( v*v*(2.0 + v)/sin_v );
	P_Z( sv*su );

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void PiriformSurface(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( PIRIFORM_SURFACE )

	double a = constants[0];
	double b = constants[1];
	double r = constants[2];

	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
	double xz = b*(v*(r + sv));

	P_X( xz*cu );
	P_Y( a*(r + sin(v)) );
	P_Z( xz*su );

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void KappaSurface(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( KAPPA_SURFACE )

	double a = constants[0];

	double cu = cos(u);
	double su = sin(u);

	double tv = tan(v);
	double acv = a*cos(v);

	P_X( acv*cu );
	P_Y( -(acv/tv) );
	P_Z( acv*su );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void BulletNose(double u, double v, 
				double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( BULLET_NOSE )

	double a = constants[0];
	double b = constants[1];

	double cu = cos(u);
	double su = sin(u);
	double acv = a*cos(v);

	P_X( acv*cu );
	P_Y( (-b)/tan(v) );
	P_Z( acv*u );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void SievertSurface(double u, double v, 
					double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SIEVERT_SURFACE )

	double C = constants[0];
	double sqrtC = sqrt(C);
	double sqrtC1 = sqrt(C+1);

	double r_u = sin(u);
	r_u = sqrt((C+1)*(1 + C*r_u*r_u))/sqrtC;
	double sin_p = -u/(sqrtC1) + atan(sqrtC1*tan(u));
	double cos_p = cos(sin_p);
	sin_p = sin(sin_p);
	u = cos(u);
	u *= u;

	double sin_v = sin(v);
	double a = 2.0/(C + 1 - C*sin_v*sin_v*u);
	sin_v = sin(v)*r_u*a;

	P_X( sin_v*cos_p );
	P_Y( sin_v*sin_p );
	P_Z( (log(tan(v*0.5)) + a*(C+1)*cos(v))/sqrtC );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}


void CosineSurface2(double u, double v, 
					double* constants, PaSuLiObject* pO) {

	PASULI_SET_TYPE_ID( COSINE_SURFACE2 )
	double cvu = cos(v + u);
	double cu = cos(u);
	double cv = cos(v);

	P_X( cu );
	P_Y( cv );
	P_Z( -cvu*cvu );

#if((PARTICLE_UD != 0)||(PARTICLE_VD != 0)||(PARTICLE_UD != 0))
	double su = sin(u);
	double sv = sin(v);
#endif

	UD_X( 0 );
	UD_Y( 0 );
	UD_Z( 0 );

	VD_X( 0 );
	VD_Y( 0 );
	VD_Z( 0 );

	N_X( 0 );
	N_Y( 0 );
	N_Z( 0 );

	UUD_X( 0 );
	UUD_Y( 0 );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}

#endif


pasulidefdesc_ct psldd_15_05_constants[] = {1.5, 0.5, 1.0, 1.0, 1.0, 1.0};
pasulidefdesc_ct psldd_10_constants[] = {1.0};

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBohemianDomeSurface = {
PSLDD_ID( BOHEMIAN_DOME_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(3),
0, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBohemianDomeSurface =
"start; \
name: Bohemian Dome Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi:2; \
vstart:0; \
vend:pi:2; \
c:1:a:1.0; \
c:2:b:1.0; \
c:3:c:1.0; \
x: a*cos(u); \
y: b*cos(v) + a*sin(u); \
z: c*sin(v); "
#if(COMPILE_DESC_DERIV_U_SURFACES != 0)
"xu: -a*sin(u); \
yu: a*cos(u); \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_SURFACES != 0)
"xv: 0; \
yv: -b*sin(v); \
zv: c*cos(v); "
#endif
#if(COMPILE_DESC_NORMAL_SURFACES != 0)
"xn: a*c*cos(u)*cos(v); \
yn: -a*c*sin(u)*cos(v); \
zn: a*b*sin(u)*sin(v); "
#endif
#if(COMPILE_DESC_DERIV2_U_SURFACES != 0)
"xuu: -a*cos(u); \
yuu: -a*sin(u); \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_SURFACES != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_SURFACES != 0)
"xvv: 0; \
yvv: -b*cos(v); \
zvv: -c*sin(v); "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBoysSurface = {
PSLDD_ID( BOYS_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_END_PI| PASULI_CONST_COUNT(0),
-0.5, 0.5 , 0 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBoysSurface =
"start; \
name: Boys Surface; \
utype:closed; \
vtype:closed; \
ustart:pi: -0.5; \
uend:pi: 0.5; \
vstart:0; \
vend:pi: 1; \
a:1:a: sqrt(2) ; \
a:2:b: 2 - a*sin(3*u)*sin(2*v); \
x: a*cos(v)*cos(v)*cos(2*u) + cos(u)*sin(2*v)/b; \
y: 3*cos(v)*cos(v)/b; \
z: a*cos(v)*cos(v)*sin(2*u) + cos(u)*sin(2*v)/b; "
#if(COMPILE_DESC_DERIV_U_SURFACES != 0)
"xu: (3*a*cos(u)*cos(3*u)*sin(2*v)*sin(2*v))/((2-a*sin(2*v)*sin(3*u))^2) - 2*a*cos(v)*cos(v)*sin(2*u) + \
(sin(u)*sin(2*v))/(a*sin(2*v)*sin(3*u)-2); \
yu: (9*a*cos(v)*cos(v)*cos(3*u)*sin(2*v))/((2-a*sin(2*v)*sin(3*u))^2); \
zu: (3*a*cos(u)*cos(3*u)*sin(2*v)*sin(2*v))/((2-a*sin(2*v)*sin(3*u))^2) + 2*a*cos(v)*cos(v)*cos(2*u) + \
(sin(u)*sin(2*v))/(a*sin(2*v)*sin(3*u)-2); "
#endif
#if(COMPILE_DESC_DERIV_V_SURFACES != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
"xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif



#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCrossCup = {
PSLDD_ID( CROSS_CUP )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI,
0, 1 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCrossCup =
"start; \
name: Cross Cup; \
utype: closed; \
vtype: closed; \
ustart:0; \
uend: 1; \
vstart: 0; \
vend:pi: 2; \
x: 1 - u*u + u*u*sin(v)*sin(v); \
y: u*u*sin(v)*sin(v) + 2*u*u*sin(v)*cos(v); \
z: sqrt((1 - u*u)/2)*u*(sin(v) + cos(v)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif



#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDiniSurface = {
PSLDD_ID( DINI_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 4 , 0.01f , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descDiniSurface =
"start; \
name: Dini Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 4; \
vstart: 0.01: \
vend: 2; \
c:1:a: 1.5; \
c:2:b: 0.5; \
x: a*cos(u)*sin(v); \
y: a*sin(u)*sin(v); \
z: a*(cos(v) + ln(tan(v/2))) + b*u; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddEnneperSurface = {
PSLDD_ID( ENNEPER_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_FULL_IMPL,
-2, 2 , -2 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descEnneperSurface =
"start; \
name: Enneper Surface; \
utype: closed; \
vtype: closed; \
ustart: -2; \
uend: 2; \
vstart: -2; \
vend: 2; \
x: u - (u*u*u/3) + u*v*v; \
y: v - (v*v*v/3) + u*u*v; \
z: u*u - v*v; "
"xu: 1 - u*u + v*v; \
yu: 2*u*v; \
zu: 2*u; "
"xv: 2*u*v; \
yv: 1 + u*u - v*v; \
zv: -2*v; "
"xn: -2*u*(1+u*u+v*v); \
yn: 2*v*(1+u*u+v*v); \
zn: 1-((u*u + v*v)^2); "
"xuu: -2*u; \
yuu: 2*v; \
zuu: 2; "
"xuv: 2*v; \
yuv: 2*u; \
zuv: 0; "
"xvv: 2*u; \
yvv: -2*v; \
zvv: -2; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHandkerchief = {
PSLDD_ID( HANDKERCHIEF )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_FULL_IMPL,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHandkerchief =
"start; \
name: Handkerchief; \
utype: closed; \
vtype: closed; \
ustart: -1; \
uend: 1; \
vstart: -1; \
vend: 1; \
x: u; \
y: v; \
z: u*u*u/3 + u*v*v + 2*(u*u - v*v); "
"xu: 1; \
yu: 0; \
zu: u*(4+u)+v*v; "
"xv: 0; \
yv: 1; \
zv: v*(2*u - 4); "
"xn: -u*(4+u) - v*v; \
yn: 2*v*(2-u); \
zn: 1; "
"xuu: 0; \
yuu: 0; \
zuu: 4+2*u; "
"xuv: 0; \
yuv: 0; \
zuv: 2*v; "
"xvv: 0; \
yvv: 0; \
zvv: 2*u-4; "
"end;";
#endif


/**

r = 4 (1 - cos(u)/2)

0 <= u <pi
x = a cos(u) (1 + sin(u)) + r cos(u) cos(v)
y = b sin(u) + r sin(u) cos(v)
z = r sin(v)

pi < u <= 2pi
x = a cos(u) (1 + sin(u)) + r cos(v +pi)
y = b sin(u)
z = r sin(v)
*/
#if(COMPILE_DEF_DESC_SURFACES != 0)

PaSuLiDefDesc pslddKleinBottleSurface = {
PSLDD_ID( KLEIN_BOTTLE_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
//TODO TODO TODO
char *descKleinBottleSurface =
"start; \
name: Klein Bottle Surface; \
utype:closed; \
vtype:closed; \
ustart: 0;  \
uend:pi: 2;  \
vstart: 0;  \
vend:pi: 2;  \
c:1:a: 1.5; \
c:2:b: 0.5; \
x: 0; \
y: 0; \
z: 0; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddMoebiusBand = {
PSLDD_ID( MOEBIUS_BAND )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_FULL_IMPL| \
PASULI_CONST_COUNT(1),
-1, 1 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descMoebiusBand =
"start; \
name: Moebius Band; \
utype: closed; \
vtype: closed; \
ustart: -1; \
uend: 1; \
vstart: 0; \
vend:pi: 2; \
c:1:r: 1.5; \
x: (r + u*cos(v/2))*cos(v); \
y: (r + u*cos(v/2))*sin(v); \
z: u*sin(v/2); "
"xu: cos(v)*cos(0.5*v); \
yu: cos(0.5*v)*sin(v); \
zu: sin(0.5*v); "
"xv: -r*sin(v) - 0.5*u*cos(v)*sin(0.5*v)-u*cos(0.5*v)*sin(v); \
yv: r*cos(v) + u*(cos(v)*cos(0.5*v)-sin(v)*sin(0.5*v)); \
zv: 0.5*u*cos(0.5*v); "
"xn: -sin(0.5*v)*(r*cos(v) + u*cos(v)*cos(0.5*v)) + 0.5*u*sin(v); \
yn: -sin(0.5*v)*(r*sin(v)+u*cos(0.5*v)*sin(v)) - 0.5*u*cos(v); \
zn: (r+u*cos(0.5*v))*cos(0.5*v); "
"xuu: 0; \
yuu: 0; \
zuu: 0; "
"xuv: -0.5*cos(v)*sin(0.5*v) - cos(0.5*v)*sin(v); \
yuv: cos(v)*cos(0.5*v) - 0.5*sin(v)*sin(0.5*v); \
zuv: 0.5*cos(0.5*v); "
"xvv: u*(sin(v)*sin(0.5*v) - 1.25*cos(v)*cos(0.5*v)) - r*cos(v); \
yvv: -u*(cos(v)*sin(0.5*v) + 1.25*cos(0.5*v)*sin(v)) - r*sin(v); \
zvv: -0.25*u*sin(0.5*v); "
"end;";
#endif



#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddMonkeySaddle = {
PSLDD_ID( MONKEY_SADDLE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_FULL_IMPL,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descMonkeySaddle =
"start; \
name: Monkey Saddle; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart: -1; \
vend: 1; \
x: u; \
y: v; \
z: u*u*u - 3*u*v*v; "
"xu: 1; \
yu: 0; \
zu: 3*(u*u - v*v); "
"xv: 0; \
yv: 1; \
zv: -6*u*v; "
"xn: 3*(v*v - u*u); \
yn: 6*u*v; \
zn: 1; "
"xuu: 0; \
yuu: 0; \
zuu: 6*u; "
"xuv: 0; \
yuv: 0; \
zuv: -6*v; "
"xvv: 0; \
yvv: 0; \
zvv: -6*u; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPlueckerConoid = {
PSLDD_ID( PLUECKER_CONOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_FULL_IMPL,
-2, 2 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descPlueckerConoid =
"start; \
name: Pluecker Conoid; \
utype:closed; \
vtype:closed; \
ustart: -2; \
uend: 2; \
vstart: -1; \
vend: 1; \
x: u*sqrt(1 - v*v); \
y: u*v; \
z: 1 - v*v; "
"xu: sqrt(1-v*v); \
yu: v; \
zu: 0; "
"xv: -u*v/(sqrt(1-v*v)); \
yv: u; \
zv: -2*v; "
"xn: -2*v*v; \
yn: 2*v*(sqrt(1-v*v)); \
zn: u/(sqrt(1-v*v)); "
"xuu: 0; \
yuu: 0; \
zuu: 0; "
"xuv: -v/(sqrt(1-v*v)); \
yuv: 1; \
zuv: 0; "
"xvv: -u/(sqrt(1-v*v)*(1-v*v)); \
yvv: 0; \
zvv: -2; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddRomanSurface = {
PSLDD_ID( ROMAN_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_FULL_IMPL,
0, 1 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descRomanSurface =
"start; \
name: Roman Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend: 1; \
vstart: 0; \
vend:pi: 2; \
x: 2*u*cos(v)*sqrt(1 - u*u); \
y: 2*u*sin(v)*sqrt(1 - u*u); \
z: 1 - 2*u*u*cos(v)*cos(v); "
"xu: 2*(1-2*u*u)*cos(v)/(sqrt(1-u*u)); \
yu: 2*(1-2*u*u)*sin(v)/(sqrt(1-u*u)); \
zu: -4*u*cos(v)*cos(v); "
"xv: -2*u*sqrt(1-u*u)*sin(v); \
yv: 2*u*sqrt(1-u*u)*cos(v); \
zv: 4*u*u*cos(v)*sin(v); "
"xn: ((8*u*u*(1-u*u*(1+sin(v)*sin(v))))*cos(v))/(sqrt(1-u*u)); \
yn: 8*((u*u*cos(v))^2)*sin(v)/(sqrt(1-u*u)); \
zn: 4*u(1-2*u*u); "
"xuu: 2*u*(2*u*u-3)*cos(v)/(sqrt(1-u*u)*(1-u*u)); \
yuu: 2*u*(2*u*u-3)*sin(v)/(sqrt(1-u*u)*(1-u*u)); \
zuu: -4*cos(v)*cos(v); \
xuv: 2*sin(v)*(2*u*u-1)/(sqrt(1-u*u)); \
yuv: 2*cos(v)*(1-2*u*u)/(sqrt(1-u*u)); \
zuv: 8*u*cos(v)*sin(v); \
xvv: -2*u*(sqrt(1-u*u))*cos(v); \
yvv: -2*u*(sqrt(1-u*u))*sin(v); \
zvv: 4*u*u*(2*cos(v)*cos(v) - 1); \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddShoeSurface = {
PSLDD_ID( SHOE_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_FULL_IMPL,
-2, 2 , -2 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descShoeSurface =
"start; \
name: Shoe Surface; \
utype:closed; \
vtype:closed; \
ustart: -2; \
uend: 2; \
vstart: -2; \
vend: 2; \
x: u; \
y: v; \
z: u*u*u/3 - v*v/2; "
"xu: 1; \
yu: 0; \
zu: u*u; "
"xv: 0; \
yv: 1; \
zv: -v; "
"xn: -u*u; \
yn: v; \
zn: 1; "
"xuu: 0; \
yuu: 0; \
zuu: 2*u; "
"xuv: 0; \
yuv: 0; \
zuv: 0; "
"xvv: 0; \
yvv: 0; \
zvv: -1; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSineSurface = {
PSLDD_ID( SINE_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_FULL_IMPL,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSineSurface =
"start; \
name: Sine Surface; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart:pi: -1; \
vend:pi: 1; \
x: sin(u); \
y: sin(v); \
z: sin(u+v); "
"xu: cos(u); \
yu: 0; \
zu: cos(u+v); "
"xv: 0; \
yv: cos(v); \
zv: cos(u+v); "
"xn: -cos(v)*cos(u+v); \
yn: -cos(u)*cos(u+v); \
zn: cos(u)*cos(v); "
"xuu: -sin(u); \
yuu: 0; \
zuu: -sin(u+v); "
"xuv: 0; \
yuv: 0; \
zuv: -sin(u+v); "
"xvv: 0; \
yvv: -sin(v); \
zvv: -sin(u+v); "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSteinbachScrew = {
PSLDD_ID( STEINBACH_SCREW )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_FULL_IMPL,
-4, 4 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSteinbachScrew =
"start; \
name: Steinbach Screw; \
utype:closed; \
vtype:closed; \
ustart: -4; \
uend: 4; \
vstart: 0; \
vend:pi: 2; \
x: u*cos(v); \
y: u*sin(v); \
z: v*cos(u); "
"xu: cos(v); yu: sin(v); zu: -v*sin(u); "
"xv: -u*sin(v); yv: u*cos(v); zv: cos(u); "
"xn: u*v*cos(v)*sin(u) + cos(u)*sin(v); \
yn: u*v*sin(u)*sin(v) - cos(u)*cos(v); \
zn: u; "
"xuu: 0; \
yuu: 0; \
zuu: -v*cos(u); "
"xuv: -sin(v); \
yuv: cos(v); \
zuv: -sin(u); "
"xvv: -u*cos(v); \
yvv: -u*sin(v); \
zvv: 0; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddWhitneyUmbrella = {
PSLDD_ID( WHITNEY_UMBRELLA )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_FULL_IMPL,
-1.5, 1.5 , -1.5 , 1.5 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descWhitneyUmbrella =
"start; \
name: Whitney Umbrella; \
utype:closed; \
vtype:closed; \
ustart: -1.5; \
uend: 1.5; \
vstart: -1.5; \
vend: 1.5; \
x: u*v; \
y: u; \
z: v*v; "
"xu: v; yu: 1; zu: 0; "
"xv: u; yv: 0; zv: 2*v; "
"xn: 2*v; \
yn: -2*v*v; \
zn: -u; "
"xuu: 0; yuu: 0; zuu: 0; "
"xuv: 1; yuv: 0; zuv: 0; "
"xvv: 0; yvv: 0; zvv: 2; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCatenoid = {
PSLDD_ID( CATENOID )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_U_START_PI|PASULI_U_END_PI|PASULI_FULL_IMPL|PASULI_CONST_COUNT(1),
-1, 1 , -2 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCatenoid =
"start; \
name: Catenoid; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart: -2; \
vend: 2; \
c:1:c:!=0: 1.5 ; \
x: c*cosh(v/c)*cos(u); \
y: c*cosh(v/c)*sin(u); \
z: v; "
"xu: -c*cosh(v/c)*sin(u); \
yu: c*cosh(v/c)*cos(u); \
zu: 0; "
"xv: sinh(v/c)*cos(u); \
yv: sinh(v/c)*sin(u); \
zv: 1; "
"xn: c*cos(u)*cosh(v/c); \
yn: c*cosh(v/c)*sin(u); \
zn: -c*cosh(v/c)*sinh(v/c); "
"xuu: -c*cos(u)*cosh(v/c); \
yuu: -c*sin(u)*cosh(v/c); \
zuu: 0; "
"xuv: sinh(v/c)*sin(u); \
yuv: sinh(v/c)*cos(u); \
zuv: 0; "
"xvv: (cos(u)*cosh(v/c))/c; \
yvv: (sin(u)*cosh(v/c))/c; \
zvv: 0; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHelicoid = {
PSLDD_ID( HELICOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_FULL_IMPL| \
PASULI_CONST_COUNT(1),
0, 1 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHelicoid =
"start; \
name: Helicoid; \
utype: closed; \
vtype: closed; \
ustart: -2; \
uend: 2; \
vstart: 0; \
vend:pi: 2; \
c:1:c: 1.5; \
x: u*cos(v); \
y: u*sin(v); \
z: c*v; "
"xu: cos(v); yu: sin(v); zu: 0; "
"xv: -u*sin(v); yv: u*cos(v); zv: c; "
"xn: c*sin(v); yn: -c*cos(v); zn: u; "
"xuu: 0; yuu: 0; zuu: 0; "
"xuv: -sin(v); yuv: cos(v); zuv: 0; "
"xvv: -u*cos(v); yvv: -u*sin(v); zvv: 0; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddParaboloid = {
PSLDD_ID( PARABOLOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI| \
PASULI_U_END_PI|PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
-1, 1 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descParaboloid =
"start; \
name: Paraboloid; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart: 0; \
vend: 2; \
c:1:a: 1.5; \
c:2:b: 0.5; \
x: a*v*cos(u); \
y: a*v*sin(u); \
z: b*v*v; "
"xu: -a*v*sin(u); \
yu: a*v*cos(u); \
zu: 0; "
"xv: a*cos(u); \
yv: a*sin(u); \
zv: 2*b*v; "
"xn: 2*a*b*v*v*cos(u); \
yn: 2*a*b*v*v*sin(u); \
zn: -a*a*v; "
"xuu: -a*v*cos(u); \
yuu: -a*v*sin(u); \
zuu: 0; "
"xuv: -a*sin(u); yuv: a*cos(u); zuv: 0; "
"xvv: 0; yvv: 0; zvv: 2*b; "
"end;";
#endif



#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHyperbolicHelicoid = {
PSLDD_ID( HYPERBOLIC_HELICOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(1),
-4, 4 , -4 , 4 , &psldd_15_05_constants[1] };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHyperbolicHelicoid =
"start; \
name: Hyperbolic Helicoid; \
utype:closed; \
vtype:closed; \
ustart: -4; \
uend: 4; \
vstart: -4; \
vend: 4; \
c:1:a: 0.5; \
x: sinh(v)*cos(a*u)/(1+cosh(u)*cosh(v));  \
y: sinh(v)*sin(a*u)/(1+cosh(u)*cosh(v)); \
z: cosh(v)*sinh(u)/(1+cosh(u)*cosh(v)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddFunnel = {
PSLDD_ID( FUNNEL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_FULL_IMPL,
0.01f, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descFunnel =
"start; \
name: Funnel; \
utype:closed; \
vtype:closed; \
ustart: 0.1; \
uend: 2; \
vstart: 0; \
vend:pi: 2; \
x: u*cos(v); \
y: u*sin(v); \
z: log(u); "
"xu: cos(v); yu: sin(v); zu: 1/u; "
"xv: -u*sin(v); yv: u*cos(v); zv: 0; "
"xn: -cos(v); \
yn: -sin(v); \
zn: u; "
"xuu: 0; yuu: 0; zuu: -1/(u*u); "
"xuv: -sin(v); yuv: cos(v); zuv: 0; "
"xvv: -u*cos(v); yvv: -u*sin(v); zvv: 0; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTractroid = {
PSLDD_ID( TRACTROID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI,
0, 4 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTractroid =
"start; \
name: Tractroid; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend: 4; \
vstart: 0; \
vend:pi: 2; \
x: sech(u)*cos(v); \
y: sech(u)*sin(v); \
z: u - tanh(u); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCatalansSurface = {
PSLDD_ID( CATALANS_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED,
-2, 2 , -1.4f , 1.4f , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCatalansSurface =
"start; \
name: Catalans Surface; \
utype:closed; \
vtype:closed; \
ustart:pi: -2; \
uend:pi: 2; \
vstart: -1.4; \
vend: 1.4; \
x: u - cosh(v)*sin(u); \
y: 1 - cosh(v)*cos(u); \
z: -4*sin(u/2)*sinh(v/2); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHyperboloid = {
PSLDD_ID( HYPERBOLOID )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_U_START_PI|PASULI_U_END_PI|PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
-1, 1 , -2 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHyperboloid =
"start; \
name: Hyperboloid; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart: -2; \
vend: 2; \
c:1:a: 1.5; \
c:2:b: 0.5; \
x: a*cosh(v)*cos(u); \
y: a*cosh(v)*sin(u); \
z: b*sinh(v); "
"xu: -a*cosh(v)*sin(u); \
yu: a*cos(u)*cosh(v); \
zu: 0; "
"xv: a*cos(u)*sinh(v); \
yv: a*sin(u)*sinh(v); \
zv: b*cosh(v); "
"xn: a*b*cos(u)*cosh(v)*cosh(v); \
yn: a*b*sin(u)*cosh(v)*cosh(v); \
zn: -a*a*cosh(v)*sinh(v); "
"xuu: -a*cos(u)*cosh(v); \
yuu: -a*sin(u)*cosh(v); \
zuu: 0; "
"xuv: -a*sin(u)*sinh(v); \
yuv: a*cos(u)*sinh(v); \
zuv: 0; "
"xvv: a*cos(u)*cosh(v); \
yvv: a*sin(u)*cosh(v); \
zvv: b*sinh(v); "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHennebergsSurface = {
PSLDD_ID( HENNEBERGS_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -0.5 , 0.5 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHennebergsSurface =
"start; \
name: Hennerbergs Surface; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart:pi: -0.5; \
vend:pi: 0.5; \
x: 2*cos(v)*sinh(u) - (2.0/3.0)*cos(3*v)*sinh(3*u); \
y: 2*sin(v)*sinh(u) + (2.0/3.0)*sin(3*v)*sinh(3*u); \
z: 2*cos(2*v)*cosh(2*u); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSwallowSurface = {
PSLDD_ID( SWALLOW_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_FULL_IMPL,
-2, 2 , -0.75 , 0.75 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSwallowSurface =
"start; \
name: Swallow Surface; \
utype:closed; \
vtype:closed; \
ustart: -2; \
uend: 2; \
vstart: 0.75; \
vend: 0.75; \
x: u*v*v + 3*v*v*v*v; \
y: -2*u*v - 4*v*v*v; \
z: u; "
"xu: v*v; \
yu: -2*v; \
zu: 1; "
"xv: 2*v*(6*v*v + u); \
yv: -2*u - 12*v*v; \
zv: 0; "
"xn: 2*(u+6*v*v); \
yn: 2*v*(u+6*v*v); \
zn: 2*v*v*(u+6*v*v); "
"xuu: 0; yuu: 0; zuu: 0; "
"xuv: 2*v; yuv: -2; zuv: 0; "
"xvv: 2*u+36*v*v; \
yvv: -24*v; \
zvv: 0; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddWallisConicalSurface = {
PSLDD_ID( WALLIS_CONICAL_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_FULL_IMPL|PASULI_CONST_COUNT(3),
-1, 1 , 0 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descWallisConicalSurface =
"start; \
name: Wallis Conical Surface; \
utype: closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart: 0; \
vend: 1; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
x: v*cos(u); \
y: v*sin(u); \
z: c*sqrt(a*a - b*b*cos(u)*cos(u)); "
"xu: -v*sin(u); \
yu: v*cos(u); \
zu: (b*b*c*cos(u)*sin(u))/(sqrt(a*a-b*b*cos(u)*cos(u))); "
"xv: cos(u); yv: sin(u); zv: 0; "
"xn: -(b*b*c*cos(u)*sin(u)*sin(u))/(sqrt(a*a-b*b*cos(u)*cos(u))); \
yn: (b*b*c*cos(u)*cos(u)*sin(u))/(sqrt(a*a-b*b*cos(u)*cos(u))); \
zn: -v; "
"xuu: -v*cos(u); \
yuu: -v*sin(u); \
zuu: (b*b*c*(a*a*(cos(u)*cos(u)-sin(u)*sin(u)) - b*b*(cos(u)^4)))/((a*a-b*b*cos(u)*cos(u))*sqrt(a*a-b*b*cos(u)*cos(u))); "
"xuv: -sin(u); \
yuv: cos(u); \
zuv: 0; "
"xvv: 0; \
yvv: 0; \
zvv: 0; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddMaedersOwl = {
PSLDD_ID( MAEDERS_OWL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI,
0, 4 , 0.001f , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descMaedersOwl =
"start; \
name: Maeders Owl; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 4; \
vstart: 0.001; \
vend: 1; \
x: v*cos(u) - 0.5*v*v*cos(2*u); \
y: -v*sin(u) - 0.5*v*v*sin(2*u); \
z: 4*exp(1.5*log(v))*cos(3*u/2)/3; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddRichmondSurface = {
PSLDD_ID(RICHMOND_SURFACE)
PASULI_U_CLOSED|PASULI_V_CLOSED,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descRichmondSurface =
"start; \
name: Richmond Surface; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart: -1; \
vend: 1; \
x: (-3*u - u^(5) + 2*u*u*u*v*v + 3*u*v*v*v*v)/(6*(u*u + v*v)); \
y: (-3*v - 3*u*u*u*u*v - 2*u*u*v*v*v + v^(5))/(6*(u*u + v*v)); \
z: u; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddScherkSurface = {
PSLDD_ID( SCHERK_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_FULL_IMPL,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descScherkSurface =
"start; \
name: Scherk Surface; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart:pi: -1; \
vend:pi: 1; \
c:1:c:!=0: 1.5; \
x: u; \
y: v; \
z: log(cos(c*u)/cos(c*v))/c; "
"xu: 1; yu: 0; zu: -sin(c*u)/cos(c*u); "
"xv: 0; yv: 1; zv: sin(c*v)/cos(c*v); "
"xn: sin(c*u)/cos(c*u); \
yn: -sin(c*v)/cos(c*v); \
zn: 1; "
"xuu: 0; \
yuu: 0; \
zuu: -c/(cos(c*u)*cos(c*u)); "
"xuv: 0; yuv: 0; zuv: 0; "
"xvv: 0; yvv: 0; zvv: c/(cos(c*v)*cos(c*v)); "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCosineSurface = {
PSLDD_ID( COSINE_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_FULL_IMPL,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCosineSurface =
"start; \
name: Cosine Surface; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart:pi: -1; \
vend:pi: 1; \
x: cos(u); \
y: cos(v); \
z: cos(u + v); "
"xu: -sin(u); yu: 0; zu: -sin(u+v); "
"xv: 0; yv: -sin(v); zv: -sin(u+v); "
"xn: -sin(v)*sin(u+v); \
yn: -sin(u)*sin(u+v); \
zn: sin(u)*sin(v); "
"xuu: -cos(u); yuu: 0; zuu: -cos(u+v); "
"xuv: 0; yuv: 0; zuv: -cos(u+v); "
"xvv: 0; yvv: -cos(v); zvv: -cos(u+v); "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddEightSurface = {
PSLDD_ID( EIGHT_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_FULL_IMPL,
0, 2 , -0.5 , 0.5 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descEightSurface =
"start; \
name: Eight Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart:pi: -0.5; \
vend:pi: 0.5; \
x: cos(u)*sin(2*v); \
y: sin(u)*sin(2*v); \
z: sin(v); "
"xu: -sin(u)*sin(2*v); \
yu: cos(u)*sin(2*v); \
zu: 0; "
"xv: 2*cos(u)*cos(2*v); \
yv: 2*cos(2*v)*sin(u); \
zv: cos(v); "
"xn: cos(u)*cos(v)*sin(2*v); \
yn: sin(u)*cos(v)*sin(2*v); \
zn: -2*cos(2*v)*sin(2*v); "
"xuu: -cos(u)*sin(2*v); \
yuu: -sin(u)*sin(2*v); \
zuu: 0; "
"xuv: -2*cos(2*v)*sin(u); \
yuv: 2*cos(2*v)*cos(u); \
zuv: 0; "
"xvv: -4*cos(u)*sin(2*v); \
yvv: -4*sin(u)*sin(2*v); \
zvv: -sin(v); "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddJetSurface = {
PSLDD_ID( JET_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 1 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descJetSurface =
"start; \
name: Jet Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 1; \
vstart: 0; \
vend:pi: 2; \
x: (1 - cosh(u))*sin(u)*cos(v)/2; \
y: (1 - cosh(u))*sin(u)*sin(v)/2; \
z: cosh(u); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDrop = {
PSLDD_ID( DROP )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
0, 1 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descDrop =
"start; \
name: Drop; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 1; \
vstart: 0; \
vend:pi: 2; \
c:1:a: 1.5; \
c:2:b: 0.5; \
x: a*(b - cos(u))*sin(u)*cos(v); \
y: a*(b - cos(u))*sin(u)*sin(v); \
z: cos(u); "
"xu: a*cos(v)*(b*cos(u) - cos(u)*cos(u) + sin(u)*sin(u)); \
yu: a*sin(v)*(b*cos(u) - cos(u)*cos(u) + sin(u)*sin(u)); \
zu: -sin(u); "
"xv: sin(u)*sin(v)*a*(cos(u)-b); \
yv: sin(u)*cos(v)*a*(b - cos(u)); \
zv: 0; "
"xn: a*(b - cos(u))*cos(v)*sin(u)*sin(u); \
yn: a*(b - cos(u))*sin(u)*sin(u)*sin(v); \
zn: sin(u)*a*a*(b-cos(u)*(1 - b*b + 3*b*cos(u)-2*cos(u)*cos(u))); "
"xuu: sin(u)*a*cos(v)*(4*cos(u)-b); \
yuu: sin(u)*a*sin(v)*(4*cos(u)-b); \
zuu: -cos(u); "
"xuv: sin(v)*a*(cos(u)*cos(u)-sin(u)*sin(u)-b*cos(u)); \
yuv: -cos(v)*a*(cos(u)*cos(u)-sin(u)*sin(u)-b*cos(u)); \
zuv: 0; "
"xvv: sin(u)*a*cos(v)*(cos(u)-b); \
yvv: sin(u)*a*sin(v)*(cos(u)-b); \
zvv: 0; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTriaxialTeardrop = {
PSLDD_ID( TRIAXIAL_TEARDROP )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 1 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTriaxialTeardrop =
"start; \
name: Triaxial Teardrop; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 1; \
vstart: 0; \
vend:pi: 2; \
x: (1 - cos(u))*cos(u + 2*pi/3)*cos(v + 2*pi/3)/2; \
y: (1 - cos(u))*cos(u + 2*pi/3)*cos(v - 2*pi/3)/2; \
z: cos(u - 2*pi/3); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPillowShape = {
PSLDD_ID( PILLOW_SHAPE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_FULL_IMPL| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descPillowShape =
"start; \
name:pillow Shape; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 1; \
vstart:pi: -1; \
vend:pi: 1; \
c:1:a: 1.5; \
x: cos(u); \
y: cos(v); \
z: a*sin(u)*sin(v); "
"xu: -sin(u); \
yu: 0; \
zu: a*cos(u)*sin(v); "
"xv: 0; \
yv: -sin(v); \
zv: a*cos(v)*sin(u); "
"xn: a*cos(u)*sin(v)*sin(v); \
yn: a*cos(v)*sin(u)*sin(u); \
zn: sin(u)*sin(v); "
"xuu: -cos(u); \
yuu: 0; \
zuu: -a*sin(u)*sin(v); "
"xuv: 0; \
yuv: 0; \
zuv: a*cos(u)*cos(v); "
"xvv: 0; \
yvv: -cos(v); \
zvv: -a*sin(u)*sin(v); "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddFishSurface = {
PSLDD_ID( FISH_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 1 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descFishSurface =
"start; \
name: Fish Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 1; \
vstart: 0; \
vend:pi: 2; \
x: (cos(u) - cos(2*u))*cos(v)/4; \
y: (sin(u) - sin(2*u))*sin(v)/4; \
z: cos(u); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHorn = {
PSLDD_ID( HORN )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI| \
PASULI_V_END_PI|PASULI_FULL_IMPL| \
PASULI_CONST_COUNT(3),
0, 1 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHorn =
"start; \
name: Horn; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend: 1; \
vstart:pi: -1; \
vend:pi: 1; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
x: (a + u*cos(v))*sin(b*pi*u); \
y: (a + u*cos(v))*cos(b*pi*u) + c*u; \
z: u*sin(v); "
"xu: b*pi*cos(b*pi*u)(a+u*cos(v)) + cos(v)*sin(b*pi*u); \
yu: c - b*pi*sin(b*pi*u)*(a+u*cos(v)) + cos(v)*cos(b*pi*u); \
zu: sin(v); "
"xv: -u*sin(v)*sin(b*pi*u); \
yv: -u*sin(v)*cos(b*pi*u); \
zv: u*cos(v); "
"xn: u*(b*pi*sin(b*pi*u)*cos(v)*(-a - u*cos(v)) +c*cos(v)+cos(b*pi*u)); \
yn: -u*(b*pi*cos(v)*cos(b*pi*u)*(a+u*cos(v)) + sin(b*pi*u)); \
zn: u*sin(v)*(-b*pi*(a+u*cos(v)) + c*sin(b*pi*u) ); "
"xuu: b*pi*(-b*pi*sin(b*pi*u)*(a + u*cos(v))) + 2*cos(v)*cos(b*pi*u); \
yuu: b*pi*(-b*pi*cos(b*pi*u)*(a + u*cos(v))) - 2*cos(v)*sin(b*pi*u); \
zuu: 0; "
"xuv: -sin(v)*(b*pi*u*cos(b*pi*u) + sin(b*pi*u)); \
yuv: sin(v)*(b*pi*u*sin(b*pi*u) - cos(b*pi*u)); \
zuv: cos(v); "
"xvv: -u*cos(v)*sin(b*pi*u); \
yvv: -u*cos(v)*cos(b*pi*u); \
zvv: -u_sin(v); "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBentHorns = {
PSLDD_ID( BENT_HORNS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -2 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBentHorns =
"start; \
name: Bent Horns; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart:pi: -2; \
vend:pi: 2; \
x: (2 + cos(u))*(v/3 - sin(v)); \
y: (2 + cos(u + 2*pi/3))*(cos(v) - 1); \
z: (2 + cos(u - 2*pi/3))*(cos(v) - 1); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHyperbolicOctahedron = {
PSLDD_ID( HYPERBOLIC_OCTAHEDRON )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_FULL_IMPL,
-0.5, 0.5 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHyperbolicOctahedron =
"start; \
name: Hyperbolic Octahedron; \
utype:closed; \
vtype:closed; \
ustart:pi: -0.5; \
uend:pi: 0.5; \
vstart:pi: -1; \
vend:pi: 1; \
x: (cos(u)*cos(v))^(3); \
y: (sin(u)*cos(v))^(3); \
z: sin(v)^(3); "
"xu: -3*(cos(u)^2)*(cos(v)^3)*sin(u); \
yu: 3*cos(u)*(cos(v)^3)*(sin(u)^2); \
zu: 0; "
"xv: -3*(cos(u)^3)*(cos(v)^2)*sin(v); \
yv: -3*(cos(v)^2)*(sin(u)^3)*sin(v); \
zv: 3*cos(v)*sin(v)*sin(v); "
"xn: 9*cos(u)*(cos(v)^4)*(sin(u)^2)*(sin(v)^2); \
yn: 9*(cos(u)^2)*(cos(v)^4)*sin(u)*(sin(v)^2); \
zn: 9*(cos(u)^2)*(cos(v)^5)*(sin(u)^2)*sin(v); "
"xuu: 3*cos(u)*(cos(v)^3)*(2-3*cos(u)*cos(u)); \
yuu: 3*sin(u)*(cos(v)^3)*(2-3*sin(u)*sin(u)); \
zuu: 0; "
"xuv: 9*((cos(u)*cos(v))^2)*sin(u)*sin(v); \
yuv: -9*(cos(u)*(cos(v)^2)*(sin(u)^2)*sin(v); \
zuv: 0; "
"xvv: 3*(2-3*cos(v)*cos(v))*(cos(u)^3)*cos(v); \
yvv: 3*(2-3*cos(v)*cos(v))*(sin(u)^3)*cos(v); \
zvv: 3*sin(v)*(2-3*sin(v)*sin(v)); "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPseudoCrossCap = {
PSLDD_ID( PSEUDO_CROSS_CAP )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descPseudoCrossCap =
"start; \
name: Pseudo Cross Cap; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart:pi: -1; \
vend:pi: 1; \
x: (1 - u*u)*sin(v); \
y: (1 - u*u)*sin(2*v); \
z: u; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCresent = {
PSLDD_ID( CRESENT )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(3),
0, 1 , 0 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCresent =
"start; \
name: Cresent; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend: 1; \
vstart: 0; \
vend: 1; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
x: (a + sin(b*pi*u)*sin(b*pi*v))*sin(c*pi*v); \
y: (a + sin(b*pi*u)*sin(b*pi*v))*cos(c*pi*v); \
z: cos(b*pi*u)*sin(b*pi*v) + 4*v - 2; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddStilettoSurface = {
PSLDD_ID( STILETTO_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 2 , 0 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descStilettoSurface =
"start; \
name: Stiletto Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 1; \
x: (2+cos(u))*cos(v)*cos(v)*cos(v)*sin(v); \
y: (2+cos(u+2*pi/3))*cos(v+2*pi/3)*cos(v+2*pi/3)*sin(v+2*pi/3)*sin(v+2*pi/3); \
z: -(2+cos(u-2*pi/3))*cos(v+2*pi/3)*cos(v+2*pi/3)*sin(v+2*pi/3)*sin(v+2*pi/3); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddKuensSurface = {
PSLDD_ID( KUENS_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED,
-4.3f, 4.3f , 0.03f , 3.11f , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descKuensSurface =
"start; \
name: Kuens Surface; \
utype:closed; \
vtype:closed; \
ustart: -4.3; \
uend: 4.3; \
vstart: 0.01; \
vend: 3.11; \
a:1:h: 1 + u*u*sin(v)*sin(v); \
x: (2*(cos(u) + u sin(u))*sin(v))/h; \
y: (2*(-u*cos(u) + sin(u))*sin(v))/h; \
z: log(tan(v/2)) + 2*cos(v)/h; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTrefoilKnots = {
PSLDD_ID( TREFOIL_KNOTS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
0, 12 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTrefoilKnots =
"start; \
name: Trefoil Knots; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 12; \
vstart: 0; \
vend:pi: 2; \
c:1:R: 1.5; \
c:2:r: 0.5; \
a:1:Bx: (R + r*cos(u/2))*cos(u/3); \
a:2:By: (R + r*cos(u/2))*sin(u/3); \
a:3:Bz: r + sin(u/2); \
x: Bx + r*cos(u/3)*cos(v-pi); \
y: By + r*sin(u/3)*cos(v-pi); \
z: Bz + r*sin(v-pi); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTranguloidTrefoil = {
PSLDD_ID( TRANGULOID_TREFOIL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTranguloidTrefoil =
"start; \
name: Tranguloid Trefoil; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart:pi: -1; \
vend:pi: 1; \
x: 2*sin(3*u)/(2 + cos(v)); \
y: 2*(sin(u) + 2*sin(2*u))/(2 + cos(v + 2*pi/3)); \
z: (cos(u) - 2*cos(2*u))*(2 + cos(v))*(2 + cos(v + 2*pi/3))/4; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCrown = {
PSLDD_ID( CROWN )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCrown =
"start; \
name: Crown; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 2; \
x: cos(u + 4)/3; \
y: cos(u)*sin(v)*cos(v)*sin(u)*cos(v) + 0.5*cos(u); \
z: cos(v)*sin(u)*cos(u)*sin(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTwistedPipeSurface = {
PSLDD_ID( TWISTED_PIPE_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTwistedPipeSurface =
"start; \
name: Twistedpipe Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 2; \
a:1:h: sqrt(1 + sin(v)*sin(v)); \
x: cos(v)*(2 + cos(u))/h; \
y: sin(v - 2*pi/3)*(2 + cos(u - 2*pi/3))/h; \
z: sin(v + 2*pi/3)*(2 + cos(u + 2*pi/3))/h; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddLoop = {
PSLDD_ID( LOOP )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descLoop =
"start; \
name: Loop; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart:pi: -1; \
vend:pi: 1; \
x: sin(v)*cos(u); \
y: 2*cos(v); \
z: 4*sin(v)*cos(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDupinCyclide = {
PSLDD_ID( DUPIN_CYCLIDE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(4),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descDupinCyclide =
"start; \
name: Dupin Cyclide; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 2; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
c:4:d: 1.0; \
a:1:h: a - c*cos(u)*cos(v); \
x: (d*(c - a*cos(u)*cos(v)) + b*b*cos(u))/h; \
y: (b*sin(u)*(a - d*cos(v)))/h; \
z: b*sin(v)*(c*cos(u) - d)/h; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddGuimardSurface = {
PSLDD_ID( GUIMARD_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(3),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descGuimardSurface =
"start; \
name: Guimard Surface; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart: -1; \
vend: 1; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
x: ((1 - u)*a + u*b)*cos(v); \
y: b*u*sin(v); \
z: c*u*sin(v)*sin(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddMennsSurface = {
PSLDD_ID( MENNS_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(1),
-1, 1 , -1 , 1 , psldd_10_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descMennsSurface =
"start; \
name: Menns Surface; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart: -1; \
vend: 1; \
c:1:a: 1.0; \
x: u; \
y: v; \
z: a*u^(4) + u*u*v - v*v; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddMilkBag = {
PSLDD_ID( MILK_BAG )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(1),
-1, 1 , -1 , 1 , psldd_10_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descMilkBag =
"start; \
name: Milk Bag; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart:pi: -1; \
vend:pi: 1; \
c:1:k: 1.0; \
x: k*(1 + u)*cos(v); \
y: k*(1 - u)*sin(v); \
z: u; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTriaxialTritorus = {
PSLDD_ID( TRIAXIAL_TRITORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTriaxialTritorus =
"start; \
name: Triaxial Tritorus; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart:pi: -1; \
vend:pi: 1; \
x: sin(u)*(1 + cos(v)); \
y: sin(u + 2*pi/3)*(1 + cos(v + 2*pi/3)); \
z: sin(u + 4*pi/3)*(1 + cos(v + 4*pi/3)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddVerrillSurface = {
PSLDD_ID( VERRILL_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI,
0.5, 1 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descVerrillSurface =
"start; \
name: Verrill Surface; \
utype:closed; \
vtype:closed; \
ustart: 0.5; \
uend: 1; \
vstart: 0; \
vend:pi: 2; \
x: -2*u*cos(v) + (2*cos(v)/u) - 2*u^(3)*cos(3*v)/3; \
y: 6*u*sin(v) - 2*sin(v)/u - 2*u^(3)*cos(3*v)/3; \
z: 4*log(u); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddZindlersConoid = {
PSLDD_ID( ZINDLERS_CONOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(1),
-1, 1 , -0.75f , 0.75f , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descZindlersConoid =
"start; \
name: Zindlers Conoid; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart: -0.75; \
vend: 0.75; \
c:1:a: 1.5; \
x: u*cos(v); \
y: u*sin(v); \
z: a*tan(2*v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddFolium = {
PSLDD_ID( FOLIUM )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descFolium =
"start; \
name: Folium; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart:pi: -1; \
vend:pi: 1; \
x: cos(u)*(2*v/pi - tanh(v)); \
y: cos(u + 2*pi/3)/cosh(v); \
z: cos(u - 2*pi/3)/cosh(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddLemniscape = {
PSLDD_ID( LEMNISCAPE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 1 , 0 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descLemniscape =
"start; \
name: Lemniscape; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 1; \
vstart: 0; \
vend:pi: 1; \
x: cos(v)*sqrt(abs(sin(2*u)))*cos(u); \
y: cos(v)*sqrt(abs(sin(2*u)))*sin(u); \
z: x*x - y*y + 2*x*y*tan(v)^(2);  \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTriplePointTwist = {
PSLDD_ID( TRIPLE_POINT_TWIST )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(1),
-2, 1.7f , -1.5f , 1.5f , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTriplePointTwist =
"start; \
name: Triple point Twist; \
utype:closed; \
vtype:closed; \
ustart: -2; \
uend: 1.7; \
vstart: -1.5; \
vend: 1.5; \
c:1:c: 1.5; \
x: u; \
y: v^(3) + c*v; \
z: u*v + v^(5) + c*v^(3); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTrashcan = {
PSLDD_ID( TRASHCAN )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTrashcan =
"start; \
name: Trashcan; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend: 2; \
c:1:a: 1.5; \
c:2:b: 0.5; \
x: (b + v)*cos(u); \
y: v*sin(u); \
z: a*v*v; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSpring1 = {
PSLDD_ID( SPRING1 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(4)|PASULI_CALC_U_END,//MUL_BY_CONST(3),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSpring1 =
"start; \
name: Spring 1; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi:c4: 2; \
vstart: 0; \
vend:pi: 2; \
c:1:R: 1.5; \
c:2:r: 0.5; \
c:3:L: 1.0; \
c:4:N: 1.0; \
x: (R + r*cos(v))*cos(u); \
y: (R + r*cos(v))*sin(u); \
z: r*(sin(v) + L*u/pi); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSpring2 = {
PSLDD_ID( SPRING2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(3),
-1, 1 , 0 , 5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSpring2 =
"start; \
name: Spring 2; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart: 0; \
vend:pi: 5; \
c:1:R: 1.5; \
c:2:r: 0.5; \
c:3:h: 1.0; \
a:1:w: sqrt(R*R + r*r); \
x: (R + r*cos(u))*cos(v) + r*h*sin(u)*sin(v)/w; \
y: (R + r*cos(u))*sin(v) - r*h*sin(u)*cos(v)/w; \
z: h*v + R*r*sin(u)/w; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCone = {
PSLDD_ID( CONE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_CONST_COUNT(1),
1, 3 , 0 , 2 , psldd_10_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCone =
"start; \
name: Cone; \
utype:closed; \
vtype:closed; \
ustart: 1; \
uend: 3; \
vstart: 0; \
vend:pi: 2; \
c:1:a: 1; \
x: u; \
y: a*u*sin(v); \
z: a*u*cos(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddIsolator = {
PSLDD_ID( ISOLATOR )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(3),
1.5f, 9.5f , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descIsolator =
"start; \
name: Isolator; \
utype:closed; \
vtype:closed; \
ustart: 1.5; \
uend:pi: 9.5; \
vstart: 0; \
vend:pi: 2; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
x: u; \
y: (a + b*sin(c*u*2*pi))*sin(v); \
z: (a + b*sin(c*u*2*pi))*cos(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)		//TODO TODO
PaSuLiDefDesc pslddEgg = {
PSLDD_ID( EGG )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_CONST_COUNT(3)| \
PASULI_CALC_U_END,
0, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descEgg =
"start; \
name: Egg; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend: c1: 1; \
vstart: 0; \
vend:pi: 2; \
c:1:a:<=c1: 0.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
x: c*sqrt(u*(u - a)*(u - b))*sin(v); \
y: u; \
z: c*sqrt(u*(u - a)*(u - b))*cos(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHyperbolicParaboloid = {
PSLDD_ID( HYPERBOLIC_PARABOLOID )
PASULI_U_CLOSED|PASULI_V_CLOSED,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHyperbolicParaboloid =
"start; \
name: Hyperbolic Paraboloid; \
utype: closed; \
vtype: closed; \
ustart: -1; \
uend: 1; \
vstart: -1; \
vend: 1; \
x: u; \
y: v; \
z: u*v; \
xu: 1; \
yu: 0; \
zu: v; \
xv: 0; \
yv: 1; \
zv: u; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDropSurface = {
PSLDD_ID( DROP_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-0.5, 0.5 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descDropSurface =
"start; \
name: Drop Surface; \
utype:closed; \
vtype:closed; \
ustart:pi: -0.5; \
uend:pi: 0.5; \
vstart: 0; \
vend:pi: 2; \
c:1:a: 1.5; \
x: cos(v)*cos(u); \
y: sin(v)*cos(u); \
z: sin(u - a); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddFacingSnail = {
PSLDD_ID( FACING_SNAIL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-0.5f, 0.5f , 0 , 6 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descFacingSnail =
"start; \
name: Facing Snail; \
utype:closed; \
vtype:closed; \
ustart:pi: -0.5; \
uend:pi: 0.5; \
vstart: 0; \
vend:pi: 6; \
c:1:a: 1.5; \
x: cos(v)*cos(u); \
y: sin(v)*cos(u); \
z: (1 - a*v)*sin(u); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPaperBag = {
PSLDD_ID( PAPER_BAG )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descPaperBag =
"start; \
name: Paper Bag; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend: 2; \
c:1:a: 1.5; \
c:2:b: 0.5; \
x: v*cos(u); \
y: (v + b*u)*sin(u); \
z: a*v*v; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddJeenerKleinSurface = {
PSLDD_ID( JEENER_KLEIN_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(3),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descJeenerKleinSurface =
"start; \
name: Jeener Klein Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 2; \
c:1:S: 1.5; \
c:2:T: 0.5; \
c:3:a: 1.0; \
a:1:W: ((S + 1)/4)*cos((S + 1)*u +pi/T) + sqrt(a); \
x: S*cos(u) + cos(S*u) - W*sin((S - 1)*u/2)*cos(v); \
y: W*sin(v); \
z: S*sin(u) - sin(S*u) - W*cos((S - 1)*u/2)*cos(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBonanJeenerKleinSurface = {
PSLDD_ID( BONAN_JEENER_KLEIN_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBonanJeenerKleinSurface =
"start; \
name: Bonan Jeener Klein Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 2; \
c:1:M: 1.5; \
c:2:T: 0.5; \
a:1:W: sin((M - 1)*u) + T; \
x: M*cos(u) - cos(M*u) - ((M - 1)/M)*W*sin((M + 1)*u/2)*cos(v); \
y: W*sin(v); \
z: M*sin(u) - sin(M*u) + ((M - 1)/M)*W*cos((M + 1)*u/2)*cos(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddKleinCycloid = {			//TODO TODO
PSLDD_ID( KLEIN_CYCLOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI,
0, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descKleinCycloid =
"start; \
name: Klein Cycloid; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend:pi:c2:c3: 2; \
vstart: 0; \
vend:pi: 4; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
x: cos(u/c)*cos(u/b)*(a + cos(v)) + sin(u/b)*sin(v)*cos(v); \
y: sin(u/c)*cos(u/b)*(a + cos(v)) + sin(u/b)*sin(v)*cos(v); \
z: -sin(u/b)*(a + cos(v)) + cos(u/b)*sin(v)*cos(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDoubleCone = {
PSLDD_ID( DOUBLE_CONE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI,
0, 2 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descDoubleCone =
"start; \
name: Double Cone; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: -1; \
vend: 1; \
x: v*cos(u); \
y: (v - 1)*cos(u + 2*pi/3); \
z: (1 - v)*cos(u - 2*pi/3); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHoleDisc = {
PSLDD_ID( HOLE_DISC )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI,
0, 2 , 3 , 4.5 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHoleDisc =
"start; \
name: Hole Disc; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 3; \
vend: 4.5; \
x: sin(u)/(sqrt(2) + sin(v)); \
y: cos(u)/(sqrt(2) + sin(v)); \
z: cos(u)/(1 + sqrt(2)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPisotTriaxial = {
PSLDD_ID( PISOT_TRIAXIAL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_U_END_PI,
0, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descPisotTriaxial =
"start; \
name:pisot Triaxial; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 2; \
x: 0.655866*cos(1.03002 + u)*(2 + cos(v)); \
y: 0.74878*cos(1.40772 - u)*(2 + 0.868837*cos(2.43773 + v)); \
z: 0.868837*cos(2.43773 + u)*(2 + 0.495098*cos(0.377696 - v)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTriaxialHexatorus = {
PSLDD_ID( TRIAXIAL_HEXATORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_U_END_PI,
0, 2 ,0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTriaxialHexatorus =
"start; \
name: Triaxial Hexatorus; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 2; \
x: sin(u)/(sqrt(2) + cos(v)); \
y: sin(u + 2*pi/3)/(sqrt(2) + cos(v + 2*pi/3)); \
z: cos(u - 2*pi/3)/(sqrt(2) + cos(v - 2*pi/3)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTwistedHeart = {
PSLDD_ID( TWISTED_HEART )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
0, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTwistedHeart =
"start; \
name: Twisted Heart; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend:pi: 1; \
vstart:pi: -1; \
vend:pi: 1; \
a:1:m: 1/sqrt(2); \
x: (|v| - |u| - |tanh(m*u)/m| + |tanh(m*v)/m|)*sin(v); \
y: (|v| + |u| - |(tanh(m*u)/m| - |tanh(m*v)/m|)*cos(v); \
z: m*(u*u + v*v)/(cosh(m*u)*cosh(m*v)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHoleDiscus = {
PSLDD_ID( HOLE_DISCUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHoleDiscus =
"start; \
name: Hole Discus; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 2; \
c:1:a: 1.5; \
c:2:b: 0.5; \
x: sin(u)/(a + sin(v)); \
y: cos(v)/b; \
z: cos(u)/(a + sin(v)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDisc = {
PSLDD_ID( DISC )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI,
0, 2 , 0 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descDisc =
"start; \
name: Disc; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend: 1; \
x: v*sin(u); \
y: 0; \
z: v*sin(u); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddWaves = {
PSLDD_ID( WAVES )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(3),
-2, 2 , -2 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descWaves =
"start; \
name: Waves; \
utype:closed; \
vtype:closed; \
ustart:pi: -2; \
uend:pi: 2; \
vstart:pi: -2; \
vend:pi: 2; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
x: u; \
y: v; \
z: a*cos(b*u)*cos(c*v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSineWave = {
PSLDD_ID( SINE_WAVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(2),
-5 , 5 , -5 , 5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSineWave =
"start; \
name: Sine Wave; \
utype:closed; \
vtype:closed; \
ustart: -5; \
uend: 5; \
vstart: -5; \
vend: 5; \
c:1:a: 1.5; \
c:2:b: 0.5; \
x: u; \
y: v; \
z: a*sin(b*sqrt(u*u + v*v)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCosineWave = {
PSLDD_ID( COSINE_WAVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(2),
-5, 5 , -5 , 5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCosineWave =
"start; \
name: Cosine Wave; \
utype:closed; \
vtype:closed; \
ustart: -5; \
uend: 5; \
vstart: -5; \
vend: 5; \
c:1:a: 1.5; \
c:2:b: 0.5; \
x: u; \
y: v; \
z: a*cos(b*sqrt(u*u + v*v)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSpiralWave = {
PSLDD_ID( SPIRAL_WAVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(3),
0, 2 , 0 , 20 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSpiralWave =
"start; \
name: Spiral Wave; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend: 20; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
x: v*cos(u); \
y: a*cos(b*u + c*v); \
z: v*sin(u); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0 \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBell = {
PSLDD_ID( BELL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(2),
-5 , 5 , -5 , 5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBell =
"start; \
name: Bell; \
utype:closed; \
vtype:closed; \
ustart: -5; \
uend: 5; \
vstart: -5; \
vend: 5; \
c:1:a: 1.5; \
c:2:b: 0.5; \
a:1:r: sqrt(u*u + v*v); \
x: u; \
y: v; \
z: b*exp(-(a*r)^(2)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBellPolar = {
PSLDD_ID( BELL_POLAR )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0 , 12 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBellPolar =
"start; \
name: Bell Polar; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend: 12; \
c:1:a: 1.5; \
c:2:b: 0.5; \
a:1:r: sqrt(2*v*v) = sqrt(x*x + y*y); \
x: v*cos(u); \
y: v*sin(u); \
z: b*exp(-(a*r)^(2)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBellWave = {
PSLDD_ID( BELL_WAVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0 , 12 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBellWave =
"start; \
name: Bell Wave; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend: 12; \
c:1:a: 1.5; \
c:2:b: 0.5; \
a:1:r: sqrt(u*u + v*v); \
x: u; \
y: v; \
z: cos(c*r)*b*exp(-(a*r)^(2)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSoucoupoid = {
PSLDD_ID( SOUCOUPOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_END_PI,
-1, 1 , 0 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSoucoupoid =
"start; \
name: Soucoupoid; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart: 0; \
vend:pi: 1; \
x: cos(u)*cos(v); \
y: (sin(u))^(3); \
z: cos(u)*sin(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddEnneperSurfacePolar = {
PSLDD_ID( ENNEPER_SURFACE_POLAR )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI,
0, 2 , 0 , 2.5f , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descEnneperSurfacePolar =
"start; \
name: Enneper Surface Polar; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend: 2.5; \
a:1:s: v*cos(u); \
a:2:t: v*sin(u); \
x: s - s^(3)/3 + s*t*t; \
y: t - t^(3)/3 + t*s*s; \
z: s*s - t*t; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSineCone = {
PSLDD_ID( 0 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
-10, 10 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSineCone =
"start; \
name: Sine Cone; \
utype:closed; \
vtype:closed; \
ustart: -10; \
uend: 10; \
vstart:pi: -1; \
vend:pi: 1; \
c:1:k: 1.5; \
c:2:N: 0.5; \
x: u*cos(v); \
y: k*u*cos(N*v); \
z: u*sin(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSpinner = {
PSLDD_ID( SPINNER )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_CONST_COUNT(2),
-1, 1 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSpinner =
"start; \
name: Spinner; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart: 0; \
vend:pi: 2; \
c:1:R: 1.5; \
c:2:r: 0.5; \
x: (|u|-1)^(2)*cos(v); \
y: u; \
z: (|u|-1)^(2)*sin(v); \
xu: 0; \
yu: 1; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddFresnel = {
PSLDD_ID( FRESNEL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(3),
-1, 1 , -0.5 , 0.5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descFresnel =
"start; \
name: Fresnel; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart:pi: -0.5; \
vend:pi: 0.5; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
a:1:d: (sin(v)^(2)+c*c*cos(v)^(2)*(cos(u)^(2)/a*a + sin(u)^(2)/b*b)); \
x: (c*c/a)*(cos(u)^(2))/d; \
y: (c*c/b)*(sin(u)*cos(v))/d; \
z: c*(sin(v))/d; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTrefoilKnots2 = {
PSLDD_ID( TREFOIL_KNOTS2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(4),
0, 4 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTrefoilKnots2 =
"start; \
name: Trefoil Knots 2; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 4; \
vstart: 0; \
vend:pi: 2; \
c:1:R: 1.5; \
c:2:r: 0.5; \
c:3:a: 1.0; \
c:4:N: 1.0; \
x: r*cos(v)*cos(u) + R*cos(u)*(1 + a*cos(N*u)); \
y: r*sin(v) + a*sin(N*u); \
z: r*cos(v)*sin(u) + R*sin(u)*(1 + a*cos(N*u)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBowCurve = {
PSLDD_ID( BOW_CURVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(1),
0, 1 , 0 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBowCurve =
"start; \
name: Bow Curve; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend: 1; \
vstart: 0; \
vend: 1; \
c:1:T: 1.5; \
x: (2 + T*sin(2*pi*u))*sin(4*pi*v); \
y: (2 + T*sin(2*pi*u))*cos(4*pi*v); \
z: T*cos(2*pi*u) + 3*cos(2*pi*v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTripleCorkScrew1 = {
PSLDD_ID( TRIPLE_CORK_SCREW1 )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(4),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTripleCorkScrew1 =
"start; \
name: Triple Cork Screw 1; \
utype: closed; \
vtype: closed; \
ustart: -1; \
uend: 1; \
vstart:pi: -1; \
vend:pi: 1; \
c:1:R: 1.5; \
c:2:r: 0.5; \
c:3:L: 1.0; \
c:4:N: 1.0; \
x: L*u; \
y: r*(1 - |u|)*cos(v) + R*(1 - |u|)*cos(u*N*pi); \
z: r*(1 - |u|)*sin(v) + R*(1 - |u|)*sin(u*N*pi); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTripleCorkScrew2 = {
PSLDD_ID( TRIPLE_CORK_SCREW2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(6),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTripleCorkScrew2 =
"start; \
name: Triple Cork Screw 2; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart:pi: -1; \
vend:pi: 1; \
c:1:R: 1.5; \
c:2:r: 0.5; \
c:3:L: 1.0; \
c:4:N: 1.0; \
c:5:a: 1.0; \
c:6:b: 1.0; \
a:1:c: r*exp(-(b*b*u*u)); \
a:2:d: R*exp(-(a*a*u*u)); \
x: L*u; \
y: c*cos(v) + d*cos(u*N*pi); \
z: c*sin(v) + d*sin(u*N*pi); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTripleCorkScrew3 = {
PSLDD_ID( TRIPLE_CORK_SCREW3 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(4),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTripleCorkScrew3 =
"start; \
name: Triple Cork Screw 3; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart:pi: -1; \
vend:pi: 1; \
c:1:R: 1.5; \
c:2:r: 0.5; \
c:3:L: 1.0; \
c:4:N: 1.0; \
a:1:a: r*(1 - |u|); \
a:2:b: R*cos(u*pi/2); \
x: L*u; \
y: a*cos(v) + b*cos(u*N*pi); \
z: a*sin(v) + b*sin(u*N*pi); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBicornSurface = {
PSLDD_ID( BICORN_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 2 , 0 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBicornSurface =
"start; \
name: Bicorn Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 1; \
x: sin(v)*cos(u); \
y: sin(v)*sin(u); \
z: cos(v)*cos(v)*(2 + cos(v))/(3 + sin(v)*sin(v)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPiriformSurface = {
PSLDD_ID( PIRIFORM_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(3),
0, 2 , -0.5 , 0.5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descPiriformSurface =
"start; \
name:piriform Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart:pi: -0.5; \
vend:pi: 0.5; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:r: 1.0; \
a:1:c: (r + sin(v)); \
a:2:d: b*(cos(v)*c; \
x: d*cos(u); \
y: d*sin(u); \
z: a*c; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddKappaSurface = {
PSLDD_ID( KAPPA_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(1),
0, 2 , 0.25f , 0.5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descKappaSurface =
"start; \
name: Kappa Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0.25; \
vend:pi: 0.5; \
c:1:a: 1.5; \
a:1:r: a*cos(v); \
x: r*cos(u); \
y: r*sin(u); \
z: -r/tan(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBulletNose = {
PSLDD_ID( BULLET_NOSE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0.25f , 0.5f , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBulletNose =
"start; \
name: Bullet Nose; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0.25; \
vend:pi: 0.5; \
c:1:a: 1.5; \
c:2:b: 0.5; \
a:1:c: a*cos(v); \
x: c*cos(u); \
y: c*sin(u); \
z: -b/tan(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSievertSurface = {
PSLDD_ID( SIEVERT_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-0.5f , 0.5f , 0.1f , 3 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSievertSurface =
"start; \
name: Sievert Surface; \
utype:closed; \
vtype:closed; \
ustart:pi: -0.5; \
uend:pi: 0.5; \
vstart: 0.1; \
vend:pi: 3; \
c:1:C: 1.5; \
a:1:p: -u/sqrt(C + 1) + atan(tan(u)*sqrt(C + 1)); \
a:2:a: 2/(C + 1 - C*sin(v)*sin(v)*cos(u)*cos(u)); \
a:3:r: a*sqrt((C + 1)*(1 + C*sin(u)*sin(u)))*sin(v)/sqrt(C); \
x: r*cos(p); \
y: r*sin(p); \
z: (ln(tan(v/2)) + a*(C + 1)*cos(v))/sqrt(C); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCosineSurface2 = {
PSLDD_ID( COSINE_SURFACE2)
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCosineSurface2 =
"start; \
name: Cosine Surface 2; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart:pi: -1; \
vend:pi: 1; \
x: cos(u); \
y: cos(v); \
z: -cos(u + v)^(2); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif

