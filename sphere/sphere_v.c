
#include "sphere_v.h"
#include "sphere_c_includes.h"

#if (USE_SPHERE_V != 0)
void SphereV(pasuli_vartype u,
			 pasuli_vartype v,
			 pasuli_consttype *constants,
			 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SPHERE_V)

	pasuli_calctype cu = cos(u);
	pasuli_calctype su = sin(u);
	pasuli_calctype cv = cos(v);
	pasuli_calctype sv = sin(v);

	P_X(cu * cv);
	P_Y(sv);
	P_Z(su * cv);

	UD_X(-PASULI_COND_COPY_POS_Z(su * cv));
	UD_Y_CONST(0);
	UD_Z(PASULI_COND_COPY_POS_X(cu * cv));

	VD_X(-cu * sv);
	VD_Y(cv);
	VD_Z(-su * sv);

	N_X(-cu * cv * cv);
	N_Y(-sv * cv);
	N_Z(-su * cv * cv);

	UUD_X(-PASULI_COND_COPY_POS_X(cu * cv));
	UUD_Y_CONST(0);
	UUD_Z(-PASULI_COND_COPY_POS_Z(su * cv));

	UVD_X(su * sv);
	UVD_Y_CONST(0);
	UVD_Z(-cu * sv);

	VVD_X(-PASULI_COND_COPY_POS_X(cu * cv));
	VVD_Y(-sv);
	VVD_Z(-PASULI_COND_COPY_POS_Z(su * cv));
}
#endif

#if (COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddSphereV = {
	PSLDD_ID(SPHERE_V)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_START_PI | PASULI_V_END_PI |
		PASULI_FULL_IMPL | PASULI_CONST_COUNT(0),
	0, 1, -1, 1, 0};
#endif
#if (COMPILE_DESC_SPHERE != 0)
char *descSphereV =
	"name: sphere v; \
cat: sphere; \
ut: c; \
vt: c; \
us: 0; \
ue: pi : 1; \
vs: pi : -1; \
ve: pi : 1; \
x: cos(u)*cos(v); \
y: sin(v); \
z: sin(u)*cos(v); "
#if (COMPILE_DESC_DERIV_U_SPHERE != 0)
	"xu: -sin(u)*cos(v); \
yu: 0; \
zu: cos(u)*cos(v); "
#endif
#if (COMPILE_DESC_DERIV_V_SPHERE != 0)
	"xv: -cos(u)*sin(v); \
yv: cos(v); \
zv: -sin(u)*sin(v); "
#endif
#if (COMPILE_DESC_NORMAL_SPHERE != 0)
	"xn: -cos(u)*cos(v)*cos(v); \
yn: -sin(v)*cos(v); \
zn: -sin(u)*cos(v)*cos(v); "
#endif
#if (COMPILE_DESC_DERIV2_U_SPHERE != 0)
	"xuu: -cos(u)*cos(v); \
yuu: 0; \
zuu: -sin(u)*cos(v); "
#endif
#if (COMPILE_DESC_DERIV_UV_SPHERE != 0)
	"xuv: sin(u)*sin(v); \
yuv: 0; \
zuv: -cos(u)*sin(v); "
#endif
#if (COMPILE_DESC_DERIV2_V_SPHERE != 0)
	"xvv: -cos(u)*cos(v); \
yvv: -sin(v); \
zvv: -cos(v)*sin(u); "
#endif
	"end;";
#endif