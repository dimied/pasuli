
#include "eight_torus.h"
#include "torus_c_includes.h"

#if (USE_EIGHT_TORUS != 0)
void EightTorus(pasuli_vartype u,
				pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(EIGHT_TORUS)

	pasuli_vartype c = constants[0];

	pasuli_vartype cos_u = cos(u);
	pasuli_vartype sin_u = sin(u); //-->u=sin(u)/2;

	pasuli_vartype sin_v = sin(v); //-->v=sin(2*v)
	v = sin(2.0 * v);

	P_Y(sin_u * sin_v + cos_u * 0.5 * v);
	v = (c + sin_v * cos_u - v * sin_u * 0.5);

	P_X(cos_u * v);
	P_Z(sin_u * v);

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

#if (PARTICLE_N != 0)
	pO->n[0] = cu * c * cv;
	pO->n[1] = su * c * sv;
	pO->n[2] = c * sv;
#endif

#if (PARTICLE_UUD != 0)
	pO->uud[0] = cos(u);
	pO->uud[1] = sin(u);
	pO->uud[2] = 0;
#endif
#if (PARTICLE_UVD != 0)
	pO->uvd[0] = c * sv * su;
	pO->uvd[1] = -c * sv * cu;
	pO->uvd[2] = 0;
#endif
#if (PARTICLE_VVD != 0)
	pO->vvd[0] = -c * cv * cu;
	pO->vvd[1] = -c * cv * su;
	pO->vvd[2] = -c * sv;
#endif
}
#endif

/*
#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddEightTorus = {
PSLDD_ID( EIGHT_TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI|\
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-1 , 1 , -1 , 1 , &torus_def_constants[2] };
#endif
*/
#if (COMPILE_DESC_TORUS != 0)
char *descEightTorus =
	"name: Eight Torus; \
cat: torus; \
ut: c; \
vt: c; \
us: pi : -1; \
ue: pi: 1; \
vs: pi: -1; \
ve: pi : 1; \
c1:c: 1; \
x: cos(u) (c + sin(v) cos(u) - sin(2 v) sin(u)/2); \
y: sin(u) sin(v) + cos(u) sin(2 v)/2; \
z: sin(u) (c + sin(v) cos(u) - sin(2 v) sin(u)/2); "
#if (COMPILE_DESC_DERIV_U_TORUS != 0)
	"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if (COMPILE_DESC_DERIV_V_TORUS != 0)
	"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if (COMPILE_DESC_NORMAL_TORUS != 0)
	"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if (COMPILE_DESC_DERIV2_U_TORUS != 0)
	"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if (COMPILE_DESC_DERIV_UV_TORUS != 0)
	"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if (COMPILE_DESC_DERIV2_V_TORUS != 0)
	"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
	"end;";
#endif