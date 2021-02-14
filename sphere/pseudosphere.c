
#include "pseudosphere.h"
#include "sphere_c_includes.h"

#if (USE_PSEUDOSPHERE != 0)
void PseudoSphere(pasuli_vartype u,
				  pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(PSEUDOSPHERE)

	double cu = cos(u);
	double su = sin(u);
	double sv = sin(v);
	double cv = cos(v);

	P_X(cu * sv);
	P_Y(su * sv);
	P_Z(cv + log(tan(v * 0.5)));

	UD_X(-su * sv);
	UD_Y(cu * sv);
	UD_Z_CONST(0);

	double xyz = -sv + 0.5 / (cos(0.5 * v) * cos(0.5 * v) * tan(v * 0.5));
	VD_X(cu * cv);
	VD_Y(su * cv);
	VD_Z(xyz);

	N_X(xyz * cu * sv);
	N_Y(xyz * su * sv);
	N_Z(-sv * cv);

	UUD_X(-PASULI_COND_COPY_POS_X(cu * sv));
	UUD_Y(-PASULI_COND_COPY_POS_Y(su * sv));
	UUD_Z_CONST(0);

	UVD_X(-cv * su); //same as -VD_Y
	UVD_Y(cu * cv);	 //same as VD_X
	UVD_Z_CONST(0);

	xyz = 0.5 / (cos(0.5 * v) * cos(0.5 * v) * tan(v * 0.5));
	VVD_X(-PASULI_COND_COPY_POS_X(cu * sv));
	VVD_Y(-PASULI_COND_COPY_POS_Y(su * sv));
	VVD_Z(-cv - xyz * xyz + xyz * tan(0.5 * v));
}
#endif

#if (COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddPseudoSphere = {
	PSLDD_ID(PSEUDOSPHERE)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED |
		PASULI_U_START_PI | PASULI_U_END_PI |
		PASULI_FULL_IMPL,
	-1, 1, 0.1f, 3.1f, 0};
#endif
#if (COMPILE_DESC_SPHERE != 0)
char *descPseudoSphere =
	"name: pseudo sphere; \
cat: sphere; \
ut: c; \
vt: c; \
us: pi : -1; \
ue: pi : 1; \
vs: 0.1; \
ve: 3.10; \
x: cos(u)*sin(v); \
y: sin(u)*sin(v); \
z: cos(v) + log(tan(v/2)); "
#if (COMPILE_DESC_DERIV_U_SPHERE != 0)
	"xu: -sin(v)*sin(u) ; \
yu: sin(v)*cos(u); \
zu: 0; "
#endif
#if (COMPILE_DESC_DERIV_V_SPHERE != 0)
	"xv: cos(u)*cos(v); \
yv: sin(u)*cos(v); \
zv: -sin(v) + 1/(2*cos(0.5*v)*cos(0.5*v)*tan(0.5*v)); "
#endif
#if (COMPILE_DESC_NORMAL_SPHERE != 0)
	"xn: (-sin(v) + 1/(2*cos(0.5*v)*cos(0.5*v)*tan(0.5*v)))*cos(u)*sin(v); \
yn: (-sin(v) + 1/(2*cos(0.5*v)*cos(0.5*v)*tan(0.5*v)))*sin(u)*sin(v); \
zn: -cos(v)*sin(v); "
#endif
#if (COMPILE_DESC_DERIV2_U_SPHERE != 0)
	"xuu: -cos(u)*sin(v); \
yuu: -sin(u)*sin(v); \
zuu: 0; "
#endif
#if (COMPILE_DESC_DERIV_UV_SPHERE != 0)
	"xuv: -cos(v)*sin(u); \
yuv: cos(u)*cos(v); \
zuv: 0; "
#endif
#if (COMPILE_DESC_DERIV2_V_SPHERE != 0)
	"xvv: -cos(u)*sin(v); \
yvv: -sin(u)*sin(v); \
zvv: -cos(v) - (1/(2*cos(0.5*v)*cos(0.5*v)*tan(0.5*v)))^2 + 1/(2*cos(0.5*v)*cos(0.5*v)); "
#endif
	"end;";
#endif