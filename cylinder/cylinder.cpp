
#include "../pasuli_macros.h"
#include "../pasuli_const.h"
#include "cylinder.h"

//#pragma warning(disable:4244)

//#if(COMPILE_CYLINDER != 0)

void Cylinder(pasuli_vartype u, pasuli_vartype v, 
			pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( CYLINDER )

	pasuli_consttype r = constants[0];

	P_X( r*cos(u) );
	P_Y( r*sin(u) );
	P_Z( v );

	UD_X( -PASULI_COND_COPY_POS_Y( r*sin(u) ) );
	UD_Y( PASULI_COND_COPY_POS_X( r*cos(u) ) );
	UD_Z_CONST( 0 );

	VD_X_CONST( 0 );
	VD_Y_CONST( 0 );
	VD_Z_CONST( 1 );

	N_X( PASULI_COND_COPY_POS_X( r*cos(u) ) );
	N_Y( PASULI_COND_COPY_POS_Y( r*sin(u) ) );
	N_Z_CONST( 0 );

	UUD_X( -PASULI_COND_COPY_POS_X( r*cos(u) ) );
	UUD_Y( -PASULI_COND_COPY_POS_X( r*sin(u) ) );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}

void initConstCylinder(PaSuLiObject* pO, pasuli_consttype* constants) {
	UD_Z( 0 );
	VD_X( 0 );	VD_Y( 0 );	VD_Z( 1 );
	N_Z( 0 );
}



void EpizykloidCylinder(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( EPIZYKLOID_CYLINDER )

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];
	pasuli_consttype h = constants[2];
	pasuli_consttype H = constants[3];
	R += r;								//ATTENTION

	P_X( R*cos(u) - h*cos((R*u)/r) );
	P_Y( H*v );
	P_Z( R*sin(u) - h*sin((R*u)/r) );

	UD_X( h*(R)*sin((R)*u/r)/r -(R)*sin(u) );
	UD_Y_CONST( 0 );
	UD_Z( -h*(R)*cos((R)*u/r)/r + (R)*cos(u) );

	VD_X_CONST( 0 );
	VD_Y_CONST( H );
	VD_Z_CONST( 0 );

	N_X( H*(h*(R)*cos((R)*u/r)/r - (R)*cos(u)) );
	N_Y_CONST( 0 );
	N_Z( H*(h*(R)*sin((R)*u/r)/r -(R)*sin(u)) );

	UUD_X( -PASULI_COND_COPY_POS_X( r*cos(u) ) );
	UUD_Y( -PASULI_COND_COPY_POS_X( r*sin(u) ) );
	UUD_Z( 0 );

	UVD_X( 0 );
	UVD_Y( 0 );
	UVD_Z( 0 );

	VVD_X( 0 );
	VVD_Y( 0 );
	VVD_Z( 0 );
}

void initConstEpizykloidCylinder(PaSuLiObject* pO, pasuli_consttype* constants) {
	UD_Y( 0 );
	VD_X( 0 );	VD_Y( constants[3] );	VD_Z( 0 );
	N_Y( 0 );
}



void HypozykloidCylinder(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( HYPOZYKLOID_CYLINDER )

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];
	pasuli_consttype h = constants[2];
	pasuli_consttype H = constants[3];
	R -= r;							//ATTENTION

	P_X( (R)*cos(u) + h*cos((R*u)/r) );
	P_Y( H*v );
	P_Z( (R)*sin(u) - h*sin((R*u)/r) );

	UD_X( h*(R)*sin((R)*u/r)/r -(R)*sin(u) );
	UD_Y_CONST( 0 );
	UD_Z( -h*(R)*cos((R)*u/r)/r + (R)*cos(u) );

	VD_X_CONST( 0 );
	VD_Y_CONST( H );
	VD_Z_CONST( 0 );

	N_X( H*(h*(R)*cos((R)*u/r)/r - (R)*cos(u)) );
	N_Y_CONST( 0 );
	N_Z( H*(h*(R)*sin((R)*u/r)/r -(R)*sin(u)) );
}
void initConstHypozykloidCylinder(PaSuLiObject* pO, pasuli_consttype* constants) {
	UD_Y( 0 );
	VD_X( 0 );	VD_Y( constants[3] );	VD_Z( 0 );
	N_Y( 0 );
}



void LemniskateCylinder(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( LEMNISKATE_CYLINDER )

	pasuli_consttype r = constants[0];
	pasuli_consttype H = constants[1];

	pasuli_consttype su = sin(u);
	pasuli_consttype cu = cos(u);
	pasuli_consttype x_u = su*su + 1.0;

	P_X( r*cu/(x_u) );
	P_Y( H*v );
	P_Z( r*su*cu/(x_u) );

	pasuli_consttype x_u_q = x_u*x_u;
	pasuli_consttype cuq = cu*cu;
	pasuli_consttype suq = su*su;

	UD_X( -2*r*cuq*su/(x_u_q) - r*su/x_u);
	UD_Y_CONST( 0 );
	UD_Z( -2*r*cuq*suq/(x_u_q) + r*(cuq - suq)/x_u);

	VD_X_CONST( 0 );
	VD_Y_CONST( H );
	VD_Z_CONST( 0 );

	N_X( H*r*(3*suq - 1)/(x_u_q) );
	N_Y( 0 );
	N_Z( H*r*(-2 - cuq)*su/(x_u_q) );
}

void initConstLemniskateCylinder(PaSuLiObject* pO, pasuli_consttype* constants) {
	UD_Y( 0 );
	VD_X( 0 );	VD_Y( constants[1] );	VD_Z( 0 );
	N_Y( 0 );
}



void StrophoideCylinder(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( STROPHOIDE_CYLINDER )

	pasuli_consttype R = constants[0];
	pasuli_consttype a = constants[1];

	pasuli_consttype vq = v*v;
	pasuli_consttype vqp1 = (vq + 1);
	pasuli_consttype vsq = (a*(vq - 1))/(vq + 1);

	pasuli_consttype su = sin(u);
	pasuli_consttype cu = cos(u);
	pasuli_consttype xz = vsq + R;

	P_X( xz*cu );
	P_Y( vsq*v );
	P_Z( xz*su );

	UD_X( - PASULI_COND_COPY_POS_Z( xz*su ) );
	UD_Y_CONST( 0 );
	UD_Z( PASULI_COND_COPY_POS_X( xz*cu ) );

	pasuli_consttype vqp1q = vqp1*vqp1;
	
	//TODO
	pasuli_consttype vd = (4*a*v)/(vqp1q);
	VD_X( vd*cu );
	VD_Y( a*(2*vq*(1 - vq)/(vqp1q) + (3*vq- 1)/vqp1) );
	VD_Z( vd*su );

	vd = vqp1q*vqp1;
	xz = a*(R*(1 - vq*(3 - vq*(5 - vq))) + a*(-1.0 + vq*(5 - vq*(3 - vq))) )/(vd);
	N_X( xz*cu );
	N_Y( 4*a*v*(R - a + vq*(R + a))/vd );
	N_Z( xz*su );
}

void initConstStrophoideCylinder(PaSuLiObject* pO, pasuli_consttype* constants) {
	UD_Y( 0 );
}



void ZissoideCylinder(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( ZISSOIDE_CYLINDER )

	pasuli_consttype R = constants[0];
	pasuli_consttype a = constants[1];

	pasuli_consttype vq = v*v;
	pasuli_consttype vqp1 = (vq + 1);
	pasuli_consttype vsq = (a*v*v)/vqp1;
	pasuli_consttype su = sin(u);
	pasuli_consttype cu = cos(u);
	pasuli_consttype xz = vsq + R;

	P_X( xz*cu );
	P_Y( vsq*v );
	P_Z( xz*su );

	xz = (R + a*vq/vqp1);
	UD_X( -su*xz );
	UD_Y_CONST( 0 );
	UD_Z( xz*cu );

	pasuli_consttype vqp1q = vqp1*vqp1;
	xz = 2*a*v/(vqp1q);
	VD_X( cu*xz );
	VD_Y( (a*vq*(3*vqp1q - vq))/(vqp1q) );
	VD_Z( su*xz );

	vqp1q *= vqp1;
	xz = a*vq*(-R*(3 + vq*(4 + vq)) - a*vq*(3 + vq))/vqp1q;
	N_X( xz*cu );
	N_Y( 2*a*v*(R + vq*(R + a))/ vqp1q );
	N_Z( xz*su );
}

void initConstZissoideCylinder(PaSuLiObject* pO, pasuli_consttype* constants) {
	UD_Y( 0 );
}



void VersieraAgnesiCylinder(pasuli_vartype u, pasuli_vartype v, 
						pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( VERSIERA_AGNESI_CYLINDER )

	pasuli_consttype R = constants[0];
	pasuli_consttype a = constants[1];

	a *= 2.0;		//attention

	pasuli_consttype vqp1 = (1 + v*v);
	pasuli_consttype xz = R + (a)/vqp1;
	pasuli_consttype cu = cos(u);
	pasuli_consttype su = sin(u);

	P_X( xz*cu );
	P_Y( a*v );
	P_Z( xz*su );

	UD_X( -su*xz );
	UD_Y_CONST( 0 );
	UD_Z( cu*xz );

	xz = -2.0*a*v/(vqp1*vqp1);
	VD_X( xz*cu );
	VD_Y_CONST( a );
	VD_Z( xz*su );

	xz = a*(-R - a/vqp1);
	N_X( xz*cu );
	N_Y( 2*a*v*(-R*vqp1 - a)/(vqp1*vqp1*vqp1) );
	N_Z( xz*su );
}

void initConstVersieraAgnesiCylinder(PaSuLiObject* pO, pasuli_consttype* constants) {
	UD_Y( 0 );
	VD_Y( 2*constants[1] );
}



void GaussCylinder(pasuli_vartype u, pasuli_vartype v, 
					pasuli_consttype* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( GAUSS_CYLINDER )

	pasuli_consttype R = constants[0];
	pasuli_consttype a = constants[1];
	pasuli_consttype b = constants[2];

	pasuli_consttype xz = v*a;
	xz = b*exp(-(xz*xz));

	pasuli_consttype xzR = R + xz;

	pasuli_consttype cu = cos(u);
	pasuli_consttype su = sin(u);

	P_X( xzR*cu );
	P_Y( v );
	P_Z( xzR*su );

	UD_X( -xzR*su );
	UD_Y_CONST( 0 );
	UD_Z( xzR*cu );

	xzR = 2*a*a*v*xz;
	VD_X( xzR*cu );
	VD_Y_CONST( 1 );
	VD_Z( xzR*su );

	xzR = -(R + xz );
	N_X( xzR*cu );
	N_Y( -2*a*a*v*xz*(b + R*exp(v*v*a*a)) );
	N_Z( xzR*su );
}

void initConstGaussCylinder(PaSuLiObject* pO, pasuli_consttype* constants) {
	UD_Y( 0 );
	VD_Y( 1 );
}

//#endif

