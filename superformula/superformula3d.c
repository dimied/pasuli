#include "../pasuli_defs.h"
#include "../pasuli_macros.h"
#include "superformula3d.h"
#include <math.h>

//#pragma warning(disable : 4005)

#define GET_UD_X (pO->ud[0])
#define GET_UD_Y (pO->ud[1])
#define GET_UD_Z (pO->ud[2])
#define GET_VD_X (pO->vd[0])
#define GET_VD_Y (pO->vd[1])
#define GET_VD_Z (pO->vd[2])

char *descSuperFormula3D =
	"name: SuperFormula 3D;\
ut:c; vt:c;\
us:pi: -1; ue:pi:1;\
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
a1:R1: (abs(cos((m1*u)/4)/a1)^n12 + abs(sin((m1*u)/4)/b1)^n13)^(-1/n11);\
a2:R2: (abs(cos((m2*v)/4)/a2)^n22 + abs(sin((m2*v)/4)/b2)^n23)^(-1/n21);\
x: R1*R2*cos(u)*cos(v);\
y: R1*R2*sin(u)*cos(v);\
z: R2*sin(v);";

void SuperFormula3D(pasuli_sf3d_vartype rho, pasuli_sf3d_vartype phi,
					pasuli_sf3d_consttype *pConstants, PaSuLiSF3DObject *pO)
{
	//first 6 constants for r1(rho)
	pasuli_sf3d_vartype a1 = pConstants[0];
	pasuli_sf3d_vartype b1 = pConstants[1];
	pasuli_sf3d_consttype m1 = pConstants[2] * 0.25f; //m1 *= 0.25f;
	pasuli_sf3d_vartype n11 = pConstants[3];
	pasuli_sf3d_vartype n12 = pConstants[4];
	pasuli_sf3d_consttype n13 = pConstants[5];
	//second 6 constants for r2(phi)
	pasuli_sf3d_vartype a2 = pConstants[6];
	pasuli_sf3d_vartype b2 = pConstants[7];
	pasuli_sf3d_vartype m2 = pConstants[8] * 0.25f; //m2 *= 0.25f;
	pasuli_sf3d_vartype n21 = pConstants[9];
	pasuli_sf3d_vartype n22 = pConstants[10];
	pasuli_sf3d_consttype n23 = pConstants[11];

	pasuli_sf3d_vartype cos_rho = cos(rho);
	pasuli_sf3d_vartype sin_rho = sin(rho);
	pasuli_sf3d_vartype cos_m1_rho = cos(m1 * rho);
	pasuli_sf3d_vartype sin_m1_rho = sin(m1 * rho);
	//
	//pasuli_sf3d_vartype abs_a1 = fabs(a1);
	//pasuli_sf3d_vartype abs_b1 = fabs(b1);
	//
	pasuli_sf3d_vartype cos_phi = cos(phi);
	pasuli_sf3d_vartype sin_phi = sin(phi);
	pasuli_sf3d_vartype cos_m2_phi = cos(m2 * phi);
	pasuli_sf3d_vartype sin_m2_phi = sin(m2 * phi);
	//
	//pasuli_sf3d_vartype abs_a2 = fabs(a2);
	//pasuli_sf3d_vartype abs_b2 = fabs(b2);

	pasuli_sf3d_vartype R1 = pow(fabs(cos_m1_rho / a1), n12) + pow(fabs(sin_m1_rho / b1), n13);
	R1 = pow(R1, -1.0 / n11);

	pasuli_sf3d_vartype R2 = pow(fabs(cos_m2_phi / a2), n22) + pow(fabs(sin_m2_phi / b2), n23);
	R2 = pow(R2, -1.0 / n21);

	pasuli_sf3d_vartype R1_times_R2 = R1 * R2 * cos_phi;

	P_X(R1_times_R2 * cos_rho);
	P_Y(R1_times_R2 * sin_rho);
	P_Z(R2 * sin_phi);

	// Currently no evaluations for 1.st derivates
/*
#if ((PASULIOBJECT_UD != 0) || (PASULIOBJECT_VD != 0) || (PASULIOBJECT_N != 0))
	pasuli_sf3d_calctype sign_value = R2 * cos_phi;
	sign_value = PASULI_CALC_SIGN(sign_value);

#if ((PASULIOBJECT_UD != 0) || (PASULIOBJECT_N != 0))
	//R2*cos(v) can be ignored

	pasuli_sf3d_vartype ud_x = sign_value;
	pasuli_sf3d_vartype ud_y = sign_value;
	//pasuli_sf3d_vartype ud_z = 0;

#if (PASULIOBJECT_UD != 0)
	UD_X(ud_x);
	UD_Y(ud_y);
	UD_Y(0);
#endif

#endif
#if ((PASULIOBJECT_VD != 0) || (PASULIOBJECT_N != 0))
	pasuli_sf3d_vartype vd_x = 0;
	pasuli_sf3d_vartype vd_y = 0;
	pasuli_sf3d_vartype vd_z = 0;

#if (PASULIOBJECT_UD != 0)
	VD_X(vd_x);
	VD_Y(vd_y);
	VD_Y(vd_z);
#endif
#endif
#if (PASULIOBJECT_N != 0)
	// ud_z always 0
	N_X(ud_y * vd_z);
	N_Y(-ud_x * vd_z);
	N_Z(ud_x * vd_y - ud_y * vd_x);
#endif
*/
}