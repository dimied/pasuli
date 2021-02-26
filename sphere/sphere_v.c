
#include "sphere_v.h"
#include "sphere_c_includes.h"

#if (USE_SPHERE_V != 0)
void SphereV(pasuli_vartype u,
			 pasuli_vartype v,
			 pasuli_consttype *constants,
			 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(SPHERE_V)

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	P_X(cos_u * cos_v);
	P_Y(sin_v);
	P_Z(sin_u * cos_v);

	// Ignore scaling by cos_v
	UD_X(-sin_u);
	UD_Y_CONST(0);
	UD_Z(cos_u);

	VD_X(-cos_u * sin_v);
	VD_Y(cos_v);
	VD_Z(-sin_u * sin_v);

	// Ignore scaling by cos_v
	N_X(-PASULI_COND_COPY_POS_X(cos_u * cos_v));
	N_Y(-PASULI_COND_COPY_POS_Y(sin_v));
	N_Z(-PASULI_COND_COPY_POS_Z(sin_u * cos_v));

	// NO scaling by cos_v
	UUD_X(-cos_u);
	UUD_Y_CONST(0);
	UUD_Z(-sin_u);

	// No scaling by sin_v
	UVD_X(sin_u);
	UVD_Y_CONST(0);
	UVD_Z(-cos_u);

	VVD_X(-PASULI_COND_COPY_POS_X(cos_u * cos_v));
	VVD_Y(-PASULI_COND_COPY_POS_Y(sin_v));
	VVD_Z(-PASULI_COND_COPY_POS_Z(sin_u * cos_v));
}
#endif

#if (COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddSphereV = {
	SPHERE_V,
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_START_PI | PASULI_V_END_PI |
		PASULI_FULL_IMPL | PASULI_CONST_COUNT(0),
	0, 1, -1, 1, 0};
#endif
#if (COMPILE_DESC_SPHERE != 0)
char *descSphereV =
	"name: Sphere v;\
cat: sphere;\
ut: c; vt: c;\
us:0; ue:pi:1;\
vs:pi: -1; ve:pi:1;\
x: cos(u)*cos(v);\
y: sin(v);\
z: sin(u)*cos(v);\
xu: -sin(u)*cos(v);\
yu: 0;\
zu: cos(u)*cos(v);\
xv: -cos(u)*sin(v);\
yv: cos(v);\
zv: -sin(u)*sin(v);\
xn: -cos(u)*cos(v)*cos(v);\
yn: -sin(v)*cos(v);\
zn: -sin(u)*cos(v)*cos(v);\
xuu: -cos(u)*cos(v);\
yuu: 0;\
zuu: -sin(u)*cos(v);\
xuv: sin(u)*sin(v);\
yuv: 0;\
zuv: -cos(u)*sin(v);\
xvv: -cos(u)*cos(v);\
yvv: -sin(v);\
zvv: -cos(v)*sin(u); ";
#endif