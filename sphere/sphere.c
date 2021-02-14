
#include "../pasuli_const.h"
#include "sphere.h"
#include <math.h>

#include "../pasuli_macros.h"

#if (USE_SPHERE != 0)
void Sphere(pasuli_vartype u,
			pasuli_vartype v,
			pasuli_consttype *constants,
			PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SPHERE)

	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);

	P_X(cu * sv);
	P_Y(su * sv);
	P_Z(cv);

	UD_X(-PASULI_COND_COPY_POS_Y(su * sv));
	UD_Y(PASULI_COND_COPY_POS_X(cu * sv));
	UD_Z_CONST(0);

	VD_X(cu * cv);
	VD_Y(su * cv);
	VD_Z(-sv);

	N_X(-sv * sv * cu);
	N_Y(-sv * sv * su);
	N_Z(-sv * cv);

	UUD_X(-cu * sv);
	UUD_Y(-su * sv);
	UUD_Z_CONST(0);

	UVD_X(-su * cv);
	UVD_Y(cu * cv);
	UVD_Z_CONST(0);

	VVD_X(-PASULI_COND_COPY_POS_X(cu * sv));
	VVD_Y(-PASULI_COND_COPY_POS_Y(su * sv));
	VVD_Z(-cv);
}
#endif

///////////////////////////////////////////////

pasulidefdesc_ct sphere_def_constants[] = {1.5, 1.0, 1.0};

#if (COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddSphere = {
	PSLDD_ID(SPHERE)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI | PASULI_V_END_PI |
		PASULI_FULL_IMPL | PASULI_CONST_COUNT(0),
	0, 2, 0, 1, 0};
#endif

#if (COMPILE_DESC_SPHERE != 0)
char *descSphere =
	"name: sphere; \
cat: sphere; \
ut: c; \
vt: c; \
us: 0; \
ue:pi: 2; \
vs: 0; \
ve:pi: 1; \
x: cos(u)*sin(v); \
y: sin(u)*sin(v); \
z: cos(v); "
#if (COMPILE_DESC_DERIV_U_SPHERE != 0)
	"xu: -sin(u)*sin(v); \
yu: cos(u)*sin(v); \
zu: 0; "
#endif
#if (COMPILE_DESC_DERIV_V_SPHERE != 0)
	"xv: cos(u)*cos(v); \
yv: sin(u)*cos(v); \
zv: -sin(v); "
#endif
#if (COMPILE_DESC_NORMAL_SPHERE != 0)
	"xn: -cos(u)*sin(v)*sin(v); \
yn: -sin(u)*sin(v)*sin(v); \
zn: -sin(v)*cos(v); "
#endif
#if (COMPILE_DESC_DERIV2_U_SPHERE != 0)
	"xuu: -cos(u)*sin(v); \
yuu: -sin(u)*sin(v); \
zuu:  0; "
#endif
#if (COMPILE_DESC_DERIV_UV_SPHERE != 0)
	"xuv: -sin(u)*cos(v); \
yuv: cos(u)*cos(v); \
zuv: 0; "
#endif
#if (COMPILE_DESC_DERIV2_V_SPHERE != 0)
	"xvv: -cos(u)*sin(v); \
yvv: -sin(u)*sin(v); \
zvv:  -cos(v); "
#endif
	"end;";
#endif
