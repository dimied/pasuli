
#include "ellipsoid.h"
#include "sphere_c_includes.h"

#if (USE_ELLIPSOID != 0)
void Ellipsoid(pasuli_vartype u,
			   pasuli_vartype v,
			   pasuli_consttype *constants,
			   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(ELLIPSOID)

	double a = constants[0];
	double b = constants[1];
	double c = constants[2];

	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);

	P_X(a * cu * sv);
	P_Y(b * su * sv);
	P_Z(c * cv);

	UD_X(-a * su * sv);
	UD_Y(b * cu * sv);
	UD_Z_CONST(0);

	VD_X(a * cu * cv);
	VD_Y(b * su * cv);
	VD_Z(-c * sv);

	N_X(-b * c * sv * sv * cu);
	N_Y(-a * c * sv * sv * su);
	N_Z(-a * b * sv * cv);

	UUD_X(-PASULI_COND_COPY_POS_X(a * cu * sv));
	UUD_Y(-PASULI_COND_COPY_POS_Y(b * su * sv));
	UUD_Z_CONST(0);

	UVD_X(-a * su * cv);
	UVD_Y(b * cu * cv);
	UVD_Z_CONST(0);

	VVD_X(-a * cu * sv);
	VVD_Y(-b * su * sv);
	VVD_Z(-c * cv);
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
	"name: ellipsoid; \
cat: sphere; \
ut: c; \
vt: c; \
us: 0; \
ue: pi : 2; \
vs: 0; \
ve: pi : 1; \
c1:a: 1.5; \
c2:b: 1.0; \
c3:c: 1.0; \
x: a*cos(u)*sin(v); \
y: b*sin(u)*sin(v); \
z: c*cos(v); "
#if (COMPILE_DESC_DERIV_U_SPHERE != 0)
	"xu: -a*sin(u)*sin(v); \
yu: b*cos(u)*sin(v); \
zu: 0; "
#endif
#if (COMPILE_DESC_DERIV_V_SPHERE != 0)
	"xv: a*cos(u)*cos(v); \
yv: b*sin(u)*cos(v); \
zv: -c*sin(v); "
#endif
#if (COMPILE_DESC_NORMAL_SPHERE != 0)
	"xn: -b*c*sin(v)*sin(v)*cos(u); \
yn: -a*c*sin(v)*sin(v)*sin(u); \
zn: -a*b*sin(v)*cos(v); "
#endif
#if (COMPILE_DESC_DERIV2_U_SPHERE != 0)
	"xuu: -a*cos(u)*sin(v); \
yuu: -b*sin(u)*sin(v); \
zuu: 0; "
#endif
#if (COMPILE_DESC_DERIV_UV_SPHERE != 0)
	"xuv: -a*sin(u)*cos(v); \
yuv: b*cos(u)*cos(v); \
zuv: 0; "
#endif
#if (COMPILE_DESC_DERIV2_U_SPHERE != 0)
	"xvv: -a*cos(u)*sin(v); \
yvv: -b*sin(u)*sin(v); \
zvv: -c*cos(v); "
#endif
	"end;";
#endif