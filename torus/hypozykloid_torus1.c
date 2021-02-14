
#include "hypozykloid_torus1.h"
#include "torus_c_includes.h"

#if (USE_HYPOZYKLOID_TORUS_1 != 0)
void HypozykloidTorus1(pasuli_vartype u,
					   pasuli_vartype v,
					   pasuli_consttype *constants,
					   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(HYPOZYKLOID_TORUS_1)

	pasuli_vartype R1 = constants[0];
	pasuli_vartype R = constants[1];
	pasuli_vartype r = constants[2];
	pasuli_vartype h = constants[3];
	pasuli_vartype rrr_cos_v = R1 + (R + r) * cos(v);

	P_Y((R + r) * sin(v) - h * sin(((R + r) * v) / r));
	v = h * cos(((R + r) * v) / r);

	P_X(rrr_cos_v + cos(u) * v);
	P_Z(rrr_cos_v + sin(u) * v);

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

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddHypozykloidTorus1 = {
	PSLDD_ID(HYPOZYKLOID_TORUS_1)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(4),
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descHypozykloidTorus1 =
	"name: HypozykloidTorus1; \
cat: torus; \
us: 0; ue:pi:2; \
vs: 0; ve:pi:2; \
c1:R1:1; c2:R: 1; c3:r:0.5; c4:h: 1; \
x = (R1 + (R - r)*cos(v) - h*cos(((R - r)/r)*v))*cos(u); \
y = (R - r)*sin(v) - h*sin(((R + r)/r)*v); \
z = (R1 + (R - r)*cos(v) - h*cos(((R - r)/r)*v))*sin(u); "
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
