
#include "antisym_torus.h"
#include "torus_c_includes.h"

#if (USE_ANTISYMMETRIC_TORUS != 0)

void AntisymmetricTorus(pasuli_vartype u,
						pasuli_vartype v,
						pasuli_consttype *constants,
						PaSuLiObject *pO)
{

	PASULI_SET_TYPE_ID(ANTISYMMETRIC_TORUS)

	pasuli_consttype R = constants[0];
	pasuli_consttype r = constants[1];
	pasuli_consttype a = constants[2];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype cos_v = cos(v);

	pasuli_vartype r_a_sin_u = (a + sin_u) * r;

	pasuli_calctype posxy = cos_v * r_a_sin_u + R;
	P_X(posxy * cos_u);
	P_Y(posxy * sin_u);
	P_Z(sin_v * r_a_sin_u);

	UD_X(r * cos_v * cos_u * cos_u - (R + cos_v * r_a_sin_u) * sin_u);
	UD_Y((R + cos_v * (a + 2 * sin_u) * r) * cos_u);
	UD_Z(r * sin_v * cos_u);

	// Ignore scaling by r*(a + sin(u))
	pasuli_calctype factor = PASULI_CALC_SIGN(r_a_sin_u);
	VD_X(factor * sin_v * cos_u);
	VD_Y(factor * sin_v * sin_u);
	VD_Z(cos_v * factor);

	PASULI_CALC_NORMAL_FROM_UD_VD
}

#endif

#if (USE_ANTISYMMETRIC_TORUS != 0)
void AntisymmetricTorusArr(
	pasuli_vartype *pU,
	pasuli_size_t uCount,
	pasuli_vartype *pV,
	pasuli_size_t vCount,
	pasuli_consttype *pConstants,
	PaSuLiObject *pO)
{
	//PASULI_SET_TYPE_ID(ANTISYMMETRIC_TORUS)

	pasuli_consttype R = pConstants[0];
	pasuli_consttype r = pConstants[1];
	pasuli_consttype a = pConstants[2];

	pasuli_vartype *pVTempEnd = pV + vCount;

	while (uCount > 0)
	{
		pasuli_vartype u = *pU;
		pasuli_calctype cos_u = cos(u);
		pasuli_calctype sin_u = sin(u);

		pasuli_vartype r_a_sin_u = (a + sin_u) * r;
		pasuli_calctype factor = PASULI_CALC_SIGN(r_a_sin_u);

		++pU;
		--uCount;
		pasuli_vartype *pVTemp = pV;

		while (pVTemp != pVTempEnd)
		{
			pasuli_vartype v = *pVTemp;
			pasuli_calctype sin_v = sin(v);
			pasuli_calctype cos_v = cos(v);
			++pVTemp;

#if (PASULIOBJECT_POS != 0)
			pasuli_calctype posxy = cos_v * r_a_sin_u + R;
			P_X(posxy * cos_u);
			P_Y(posxy * sin_u);
			P_Z(sin_v * r_a_sin_u);
#endif

			UD_X(r * cos_v * cos_u * cos_u - (R + cos_v * r_a_sin_u) * sin_u);
			UD_Y((R + cos_v * (a + 2 * sin_u) * r) * cos_u);
			UD_Z(r * sin_v * cos_u);

			// Ignore scaling by r*(a + sin(u))
			VD_X(factor * sin_v * cos_u);
			VD_Y(factor * sin_v * sin_u);
			VD_Z(cos_v * factor);

			PASULI_CALC_NORMAL_FROM_UD_VD
			++pO;
		}
	}
}
#endif

/*
#if (COMPILE_DEF_DESC_TORUS != 0)
#include "torus_const.h"
PaSuLiDefDesc pslddAntisymmetricTorus = {
	ANTISYMMETRIC_TORUS,
			PASULI_U_CLOSED |
		PASULI_V_CLOSED |
		PASULI_U_END_PI | PASULI_V_END_PI | PASULI_CONST_COUNT(2),
	0, 2, 0, 2, torus_def_constants};
#endif
*/
#if (COMPILE_DESC_TORUS != 0)
char *descAntisymmetricTorus =
	"name: Antisymmetric Torus;\
cat: torus;\
ut: c; vt: c;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
c1:R: 1.5; c2:r: 0.5; c3:a: 1;\
x: (R + r*cos(v)*(a + sin(u)))*cos(u);\
y: (R + r*cos(v)*(a + sin(u)))*sin(u);\
z: r*sin(v)*(a + sin(u));\
xu: r*cos(v)*cos(u)*cos(u) -  (R + r*cos(v)*(a + sin(u)))*sin(u);\
yu: (R + r*cos(v)*(a + 2*sin(u)))*cos(u);\
zu: r*sin(v)*cos(u);\
xv: -r*sin(v)*(a + sin(u))*cos(u);\
yv: -r*sin(v)*(a + sin(u))*sin(u);\
zv: r*cos(v)*(a + sin(u));";
#endif