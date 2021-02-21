
#include "elliptic_torus.h"
#include "torus_c_includes.h"

#if (USE_ELLIPTIC_TORUS != 0)
void EllipticTorus(pasuli_vartype u,
				   pasuli_vartype v,
				   pasuli_consttype *constants,
				   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(ELLIPTIC_TORUS)

	pasuli_consttype c = constants[0];

	P_Z(sin(v) * cos(v));
	v = cos(v);
	v += (constants[0]);
	P_X(v * cos(u));
	P_Y(v * sin(u));

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	pasuli_vartype cv = cos(v);
	pasuli_vartype sv = sin(v);
#endif

	UD_X(-su);
	UD_Y(-cu);
	UD_Z(0);

	VD_X(-c * sv * cu);
	VD_Y(-c * sv * su);
	VD_Z(-c * cv);

}
#endif

/*
#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddEllipticTorus = {
PSLDD_ID( ELLIPTIC_TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(1),
0 , 2 , 0 , 2 , &torus_def_constants[2] };
#endif
*/
#if (COMPILE_DESC_TORUS != 0)
char *descEllipticTorus =
	"name: Elliptic Torus;\
cat: torus;\
ut: c; vt: c;\
us: 0; ue:pi: 2;\
vs: 0; ve:pi: 2;\
c1:a: 1;\
x: (a + cos(v))*cos(u); \
y: (a + cos(v))*sin(u); \
z: sin(v) + cos(v); ";
#endif