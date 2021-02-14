
#include "limpet_torus.h"
#include "torus_c_includes.h"

#if (USE_LIMPET_TORUS != 0)
void LimpetTorus(pasuli_vartype u,
				 pasuli_vartype v,
				 pasuli_consttype *constants,
				 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(LIMPET_TORUS)

	pasuli_vartype sqrt2 = sqrt(2.0);

	P_Y(1 / (sqrt2 + cos(v)));
	v = sqrt2 + sin(v);
	P_X(cos(u) / v);
	P_Z(sin(u) / v);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	pasuli_vartype cv = cos(v);
	pasuli_vartype sv = sin(v);
#endif

	UD_X(-su);
	UD_Y(-cu);
	UD_Z(0);

	VD_X(-sv * cu);
	VD_Y(-sv * su);
	VD_Z(-cv);

#if (PARTICLE_N != 0)
	pO->n[0] = cu * cv;
	pO->n[1] = su * sv;
	pO->n[2] = sv;
#endif

#if (PARTICLE_UUD != 0)
	pO->uud[0] = cos(u);
	pO->uud[1] = sin(u);
	pO->uud[2] = 0;
#endif
#if (PARTICLE_UVD != 0)
	pO->uvd[0] = sv * su;
	pO->uvd[1] = sv * cu;
	pO->uvd[2] = 0;
#endif
#if (PARTICLE_VVD != 0)
	pO->vvd[0] = cv * cu;
	pO->vvd[1] = cv * su;
	pO->vvd[2] = sv;
#endif
}
#endif

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddLimpetTorus = {
	PSLDD_ID(LIMPET_TORUS)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI,
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descLimpetTorus =
	"name: Limpet Torus; \
cat: torus; \
ut: c; vt: c; \
us: 0; ue:pi: 2; \
vs: 0; ve:pi: 2; \
x: cos(u)/(sqrt(2) + sin(v)); \
y: 1/(sqrt(2) + cos(v)); \
z: sin(u)/(sqrt(2) + sin(v)); "
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