
#include "ellipsoid.h"
#include "sphere_c_includes.h"

#if (USE_ELLIPSOID != 0)
void Ellipsoid(pasuli_vartype u,
			   pasuli_vartype v,
			   pasuli_consttype *constants,
			   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(ELLIPSOID)

	pasuli_consttype a = constants[0];
	pasuli_consttype b = constants[1];
	pasuli_consttype c = constants[2];

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	P_X(a * cos_u * sin_v);
	P_Y(b * sin_u * sin_v);
	P_Z(c * cos_v);

	UD_X(-a * sin_u * sin_v);
	UD_Y(b * cos_u * sin_v);
	UD_Z(0);

	VD_X(a * cos_u * cos_v);
	VD_Y(b * sin_u * cos_v);
	VD_Z(-c * sin_v);

	//sin(v)^2 = (1-cos(v))*0.5
	NORMAL_OP(pasuli_calctype sin_v2 = 0.5 - 0.5*cos(2*v));
	N_X(-b * c * sin_v2 * cos_u);
	N_Y(-a * c * sin_v2 * sin_u);
	N_Z(-a * b * sin_v * cos_v);

	UUD_X(-PASULI_COND_COPY_POS_X(a * cos_u * sin_v));
	UUD_Y(-PASULI_COND_COPY_POS_Y(b * sin_u * sin_v));
	UUD_Z_CONST(0);

	UVD_X(-a * sin_u * cos_v);
	UVD_Y(b * cos_u * cos_v);
	UVD_Z_CONST(0);

	VVD_X(-PASULI_COND_COPY_POS_X(a * cos_u * sin_v));
	VVD_Y(-PASULI_COND_COPY_POS_Y(b * sin_u * sin_v));
	VVD_Z(-c * cos_v);
}
#endif

#if (COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddEllipsoid = {
	PSLDD_ID(ELLIPSOID)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI | PASULI_V_END_PI |
		PASULI_FULL_IMPL | PASULI_CONST_COUNT(3),
	0, 2, 0, 1, sphere_def_constants};
#endif

#if (COMPILE_DESC_SPHERE != 0)
char *descEllipsoid =
	"name: ellipsoid;\
cat: sphere;\
ut: c; vt: c;\
us: 0; ue:pi: 2;\
vs: 0; ve:pi: 1;\
c1:a: 1.5; c2:b: 1.0; c3:c: 1.0;\
x: a*cos(u)*sin(v);\
y: b*sin(u)*sin(v);\
z: c*cos(v);\
xu: -a*sin(u)*sin(v);\
yu: b*cos(u)*sin(v);\
zu: 0;\
xv: a*cos(u)*cos(v);\
yv: b*sin(u)*cos(v);\
zv: -c*sin(v);\
xn: -b*c*sin(v)*sin(v)*cos(u);\
yn: -a*c*sin(v)*sin(v)*sin(u);\
zn: -a*b*sin(v)*cos(v);\
xuu: -a*cos(u)*sin(v);\
yuu: -b*sin(u)*sin(v);\
zuu: 0;\
xuv: -a*sin(u)*cos(v);\
yuv: b*cos(u)*cos(v);\
zuv: 0;\
xvv: -a*cos(u)*sin(v);\
yvv: -b*sin(u)*sin(v);\
zvv: -c*cos(v); ";
#endif