
#include "surfaces.h"
#include "../pasuli_defs.h"

//#pragma warning(disable:4244)

#include "../pasuli_macros.h"
#include <math.h>

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
