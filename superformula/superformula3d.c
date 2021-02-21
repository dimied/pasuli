

#include "../pasuli_macros.h"
#include "superformula3d.h"
#include <math.h>

#define GET_UD_X			(pO->ud[0])
#define GET_UD_Y			(pO->ud[1])
#define GET_UD_Z			(pO->ud[2])
#define GET_VD_X			(pO->vd[0])
#define GET_VD_Y			(pO->vd[1])
#define GET_VD_Z			(pO->vd[2])


//u is rho
//v is phi
////u:rho;\
////v:phi;\
///

char* descSuperFormula3D= 
"name: SuperFormula 3D;\
ut:c; vt:c;\
us:pi: -1; ue:pi: 1;\
vs:pi: -0.5 ; ve:pi: 0.5;\
c1:a1: ;\
c2:b1: ;\
c3:m1: ;\
c4:n11: ;\
c5:n12: ;\
c6:n13: ;\
c7:a2: ;\
c8:b2: ;\
c9:m2: ;\
c10:n21: ;\
c11:n22: ;\
c12:n23: ;\
f:1:R1: (abs(cos((m1*u)/4)/a1)^n12 + abs(sin((m1*u)/4)/b1)^n13)^(-1/n11);\
f:2:R2: (abs(cos((m2*v)/4)/a2)^n22 + abs(sin((m2*v)/4)/b2)^n23)^(-1/n21);\
x: R1*R2*cos(v)*cos(u);\
y: R1*R2*cos(v)*sin(u);\
z: R2*sin(v);";

#pragma warning(disable: 4005)

#define PASULI_SF3D_A1_LOW	0x1
#define PASULI_SF3D_A1_BIG	0x2
#define PASULI_SF3D_B1_LOW	0x4
#define PASULI_SF3D_B1_BIG	0x8
#define PASULI_SF3D_A2_LOW	0x10
#define PASULI_SF3D_A2_BIG	0x20
#define PASULI_SF3D_B2_LOW	0x40
#define PASULI_SF3D_B2_BIG	0x80

#define PASULI_SGN_OF( X )			(( X < 0) ? -1 : 1)

void SuperFormula3D(pasuli_sf3d_vartype rho, pasuli_sf3d_vartype phi,
					pasuli_sf3d_consttype* pConstants, PaSuLiSF3DObject* pO) {
#if(PASULI_SF3D_SAVE_STATE != 0)
	int state = 0;
#endif
	//first 6 constants
	pasuli_sf3d_vartype a1 = pConstants[0];
	pasuli_sf3d_vartype b1 = pConstants[1];
	pasuli_sf3d_consttype m1 = pConstants[2]*0.25f;		//m1 *= 0.25f;
	pasuli_sf3d_vartype n11 = pConstants[3];
	pasuli_sf3d_vartype n12 = pConstants[4];
	pasuli_sf3d_consttype n13 = pConstants[5];

	pasuli_sf3d_vartype cosrho = cos(rho);
	pasuli_sf3d_vartype sinrho = sin(rho);
	pasuli_sf3d_vartype cosMrho = cos(m1*rho);
	pasuli_sf3d_vartype sinMrho = sin(m1*rho);

	pasuli_sf3d_vartype abs_a1 = fabs(a1);
	pasuli_sf3d_vartype abs_b1 = fabs(b1);

	pasuli_sf3d_vartype R1 = 0.0;
#if(PASULI_SF3D_SAVE_STATE != 0)
	if(abs_a1 < SUPER_FORMULA_PARAMETER_A_LOWER_BOUND) {
		state |= PASULI_SF3D_A1_LOW;
	} else {
		if( abs_a1 > SUPER_FORMULA_PARAMETER_A_UPPER_BOUND) {
			state |= PASULI_SF3D_A1_BIG;
		} else {
			R1 = pow(abs(cosMrho/a1), n12);
		}
	}
#else
	if((abs_a1 > SUPER_FORMULA_PARAMETER_A_LOWER_BOUND)&&
		( abs_a1 < SUPER_FORMULA_PARAMETER_A_UPPER_BOUND) ) {
		R1 = pow(fabs(cosMrho/a1), n12);
	}
#endif
#if(PASULI_SF3D_SAVE_STATE != 0)
	if(abs_b1 < SUPER_FORMULA_PARAMETER_B_LOWER_BOUND) {
		state |= PASULI_SF3D_B1_LOW;
	} else {
		if( abs_b1 > SUPER_FORMULA_PARAMETER_B_UPPER_BOUND) {
			state |= PASULI_SF3D_B1_BIG;
		} else {
			R1 += pow(abs(sinMrho/b1), n13); 
		}
	}
#else
	if((abs_b1 > SUPER_FORMULA_PARAMETER_B_LOWER_BOUND)&&
		( abs_b1 < SUPER_FORMULA_PARAMETER_B_UPPER_BOUND) ) {
		R1 += pow(fabs(sinMrho/b1), n13); 
	}
#endif

	pasuli_sf3d_calctype R1n11 = 1.0 / pow(R1 , (pasuli_sf3d_calctype)1.0/n11);

	//second 6 constants
	pasuli_sf3d_vartype a2 = pConstants[6];
	pasuli_sf3d_vartype b2 = pConstants[7];
	pasuli_sf3d_vartype m2 = pConstants[8]*0.25f;		//m2 *= 0.25f;
	pasuli_sf3d_vartype n21 = pConstants[9];
	pasuli_sf3d_vartype n22 = pConstants[10];
	pasuli_sf3d_consttype n23 = pConstants[11];
	
	pasuli_sf3d_vartype cosphi = cos(phi);
	pasuli_sf3d_vartype sinphi = sin(phi);
	pasuli_sf3d_vartype cosMphi = cos(m2*phi);
	pasuli_sf3d_vartype sinMphi = sin(m2*phi);
	pasuli_sf3d_vartype R2 = 0.0;
	pasuli_sf3d_vartype abs_a2 = fabs(a2);
	pasuli_sf3d_vartype abs_b2 = fabs(b2);

#if(PASULI_SF3D_SAVE_STATE != 0)
	if(abs_a2 < SUPER_FORMULA_PARAMETER_A_LOWER_BOUND) {
		state |= PASULI_SF3D_A1_LOW;
	} else {
		if( abs_a2 > SUPER_FORMULA_PARAMETER_A_UPPER_BOUND) {
			state |= PASULI_SF3D_A1_BIG;
		} else {
			R2 = pow(abs(cosMphi/a2), n22);
		}
	}
#else
	if((abs_a2 > SUPER_FORMULA_PARAMETER_A_LOWER_BOUND)&&
		( abs_a2 < SUPER_FORMULA_PARAMETER_A_UPPER_BOUND) ) {
		R2 = pow(fabs(cosMphi/a2), n22);
	}
#endif
#if(PASULI_SF3D_SAVE_STATE != 0)
	if(abs_b2 < SUPER_FORMULA_PARAMETER_B_LOWER_BOUND) {
		state |= PASULI_SF3D_B2_LOW;
	} else {
		if( abs_b2 > SUPER_FORMULA_PARAMETER_B_UPPER_BOUND) {
			state |= PASULI_SF3D_B2_BIG;
		} else {
			R2 += pow(abs(sinMphi/b2), n23); 
		}
	}
#else
	if((abs_b2 > SUPER_FORMULA_PARAMETER_B_LOWER_BOUND)&&
		( abs_b2 < SUPER_FORMULA_PARAMETER_B_UPPER_BOUND) ) {
		R2 += pow(fabs(sinMphi/b2), n23); 
	}
#endif
	pasuli_sf3d_calctype R2n21 = 1.0 / pow(R2 , (pasuli_sf3d_calctype)1.0/n21);

	pasuli_sf3d_vartype xy = R1n11*R2n21*cosphi;
	P_X( xy*cosrho );
	P_Y( xy*sinrho );
	P_Z( R2n21*sinphi );

#if((PASULIOBJECT_UD != 0)||(PASULIOBJECT_VD != 0)||(PASULIOBJECT_N != 0) )
	pasuli_sf3d_vartype t1;

	pasuli_sf3d_vartype divisor;
	pasuli_sf3d_vartype cucv = cosrho*cosphi;
	pasuli_sf3d_vartype cvsu = cosphi*sin(rho);
	pasuli_sf3d_vartype sgn_cu = PASULI_SGN_OF( cosMrho );
	pasuli_sf3d_vartype sgn_su = PASULI_SGN_OF( sinMrho );
#endif
#if(PASULIOBJECT_UD != 0)

	t1 = n11*pow(abs_a1, n12)*pow(abs_b1, n13);

	xy = (sgn_cu*n12*pow(abs_b1, n13)*pow(fabs(cosMrho), (n12 - 1))*sinMrho
		- sgn_su*n13*pow(abs_a1, n12)*pow(fabs(sinMrho), (n13 - 1))*cosMrho );

	xy *= R1*0.25*m1;

	divisor = R2n21*R1n11/(n11*t1);

	//ATTENTION: multiplying by divisor
	UD_X( cosphi*(cosrho*(xy) - t1*sinrho)*divisor);
	UD_Y( cosphi*(sinrho*(xy) + t1*cosrho)*divisor );
	UD_Z_CONST( 0 );
#endif

#if(PASULIOBJECT_VD != 0)
	sgn_cu = PASULI_SGN_OF( cosMphi );
	sgn_su = PASULI_SGN_OF( sinMphi );

	t1 = n21*pow(abs_a2, n22)*pow(abs_b2, n23);

	xy = (sgn_cu*n22*pow(abs_b2, n23)*pow(fabs(cosMphi), (n22 - 1))*sinMphi
		- sgn_su*n23*pow(abs_a2, n22)*pow(fabs(sinMphi), (n23 - 1))*cosMphi );

	xy *= R1*0.25*m2;

	divisor = R2n21*R1n11/(n21*t1);
#endif
	//ATTENTION: multiplying by divisor
	VD_X( cosrho*(cosrho*(xy) - t1*sinphi)*divisor);
	VD_Y( sinrho*(sinrho*(xy) - t1*sinphi)*divisor );
	VD_Z_CONST( 0 );

#if((PASULIOBJECT_UD != 0)&&(PASULIOBJECT_VD != 0))
	N_X( -GET_UD_Z*GET_VD_Y );
	N_Y( -GET_UD_Z*GET_VD_X );
	N_Z( GET_UD_X*GET_VD_Y - GET_UD_Y*GET_VD_X );
#endif

	UUD_ALL( 0 );
	UVD_ALL( 0 );
	VVD_ALL( 0 );
}

#undef GET_UD_X
#undef GET_UD_Y
#undef GET_UD_Z

#undef GET_VD_X
#undef GET_VD_Y
#undef GET_VD_Z