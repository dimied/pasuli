
#include "curly_torus1.h"
#include "torus_c_includes.h"

#if (USE_CURLY_TORUS_1 != 0)
void CurlyTorus1(pasuli_vartype u,
				 pasuli_vartype v,
				 pasuli_consttype *constants,
				 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(CURLY_TORUS_1)

	pasuli_vartype R1 = constants[0];
	pasuli_vartype R2 = constants[1];
	pasuli_vartype r = constants[2];
	pasuli_vartype N = constants[3];

	P_Y(r * sin(v) + R2 * sin(N * u));
	v = R1 + r * cos(v);

	P_X(v * cos(u));
	P_Z(v * sin(u));

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	pasuli_vartype cv = cos(v);
	pasuli_vartype sv = sin(v);
#endif

	UD_X(-su);
	UD_Y(-cu);
	UD_Z(0);

	VD_X(-r * sv * cu);
	VD_Y(-r * sv * su);
	VD_Z(-r * cv);

#if (PARTICLE_N != 0)
	pO->n[0] = cu * r * cv;
	pO->n[1] = su * r * sv;
	pO->n[2] = r * sv;
#endif

#if (PARTICLE_UUD != 0)
	pO->uud[0] = cos(u);
	pO->uud[1] = sin(u);
	pO->uud[2] = 0;
#endif
#if (PARTICLE_UVD != 0)
	pO->uvd[0] = r * sv * su;
	pO->uvd[1] = -r * sv * cu;
	pO->uvd[2] = 0;
#endif
#if (PARTICLE_VVD != 0)
	pO->vvd[0] = -r * cv * cu;
	pO->vvd[1] = -r * cv * su;
	pO->vvd[2] = -r * sv;
#endif
}
#endif

#include "torus_desc.h"

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddCurlyTorus1 = {
	PSLDD_ID(CURLY_TORUS_1)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(4),
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descCurlyTorus1 =
	"name: Curly Torus 1; \
cat: torus; \
us: 0; ue:pi:2; \
vs: 0; ve:pi:2; \
c1:R1:1; c2:R2:1; c3:r:1; c4:n:1; \
x: (R1 + r*cos(v))*cos(u); \
y: r*sin(v) + R2*sin(n*u); \
z: (R1 + r*cos(v))*sin(u); "
#if (COMPILE_DESC_DERIV_U_TORUS != 0)
	"xu: -(R1 + r*cos(v))*sin(u); \
yu: R2*n*cos(n*u); \
zu: (R1 + r*cos(v))*cos(u); "
#endif
#if (COMPILE_DESC_DERIV_V_TORUS != 0)
	"xv: -r*cos(u)*sin(v); \
yv: r*cos(v); \
zv: -r*sin(u)*sin(v); "
#endif
#if (COMPILE_DESC_NORMAL_TORUS != 0)
	"xn:X; \
xn: -r*(cos(u)*(cos(v)*(R1 + r*cos(v))) + R2*n*cos(n*u)*sin(u)*sin(v)); \
yn:X; \
yn: -r*(R1 + r*cos(v))*sin(v); \
zn:X; \
zn: r*(-sin(u)*cos(v)*R1 + r*cos(v) + R2*n*cos(u)*cos(n*u)*sin(v)); "
#endif
#if (COMPILE_DESC_DERIV2_U_TORUS != 0)
	"xuu: -(R1 + r*cos(v))*cos(u); \
yuu: -R2*n*n*sin(n*u); \
zuu: -(R1 + r*cos(v))*sin(u); "
#endif
#if (COMPILE_DESC_DERIV_UV_TORUS != 0)
	"xuv: r*sin(u)*sin(v); \
yuv: 0; \
zuv: -r*cos(u)*sin(v); "
#endif
#if (COMPILE_DESC_DERIV2_V_TORUS != 0)
	"xvv: -r*cos(u)*cos(v); \
yvv: -r*sin(v); \
zvv: -r*cos(v)*sin(u); "
#endif
	"";
#endif
