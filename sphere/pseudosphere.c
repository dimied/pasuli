
#include "pseudosphere.h"
#include "sphere_c_includes.h"

#if (USE_PSEUDOSPHERE != 0)
void PseudoSphere(pasuli_vartype u,
				  pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(PSEUDOSPHERE)

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype sin_v = sin(v);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype tan_v_half = tan(v * 0.5);

	P_X(cos_u * sin_v);
	P_Y(sin_u * sin_v);
	P_Z(cos_v + log(tan_v_half));

	UD_X(-sin_u * sin_v);
	UD_Y(cos_u * sin_v);
	UD_Z(0);

	// tan(v) = sin(v)/cos(v)
	// sin(x)*cos(y) = (sin(x-y) + sin(x+y))/2
	// => sin(v/2)*cos(v/2) = (0 + sin(2*v/2))*0.5
	// => 1/sin(v)  - sin(v) = (1-sin(v)^2)/sin(v)
	// = cos(v)^2/sin(v) = cos(v)*cot(v)
	pasuli_calctype xyz = atan(v) * cos_v; //-sin_v + 1 / sin_v;
	VD_X(cos_u * cos_v);
	VD_Y(sin_u * cos_v);
	VD_Z(atan(v) * cos_v);

	N_X(xyz * cos_u * sin_v);
	N_Y(xyz * sin_u * sin_v);
	N_Z(-sin_v * cos_v);

	/*
	UUD_X(-PASULI_COND_COPY_POS_X(cos_u * sin_v));
	UUD_Y(-PASULI_COND_COPY_POS_Y(sin_u * sin_v));
	UUD_Z_CONST(0);

	UVD_X(-PASULI_COND_COPY_VD_Y(cos_v * sin_u));
	UVD_Y(PASULI_COND_COPY_VD_X(cos_u * cos_v));
	UVD_Z_CONST(0);

	xyz = 0.5 / (cos(0.5 * v) * cos(0.5 * v));
	VVD_X(-PASULI_COND_COPY_POS_X(cos_u * sin_v));
	VVD_Y(-PASULI_COND_COPY_POS_Y(sin_u * sin_v));
	//-cos(v) - (1/(2*cos(0.5*v)*sin(0.5*v)))^2 + 1/(2*cos(0.5*v)*cos(0.5*v))
	//-cos(v) - (1/sin(v))^2 + 1/(1+cos(v))
	//(-(sin(v)^2+cos(v))*(1+cos(v)) + sin(v)^2) /((1+cos(v))*sin(v)^2)
	// sin(v)^2 - (sin(v)^2 + cos(v) + sin(v)^2*cos(v) + cos(v)^2)
	// sin(v)^2 - (1 + cos(v) + sin(v)^2*cos(v))
	// cos(v)^2 - cos(v) - sin(v)^2*cos(v) ...
	VVD_Z(-cos_v - xyz * xyz / (tan_v_half * tan_v_half) + xyz);
	*/
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
	"name: Pseudo sphere; \
cat: sphere; \
ut: c; vt: c; \
us:pi: -1; ue:pi: 1; \
vs: 0.1; ve: 3.10; \
x: cos(u)*sin(v); \
y: sin(u)*sin(v); \
z: cos(v) + log(tan(v/2)); \
xu: -sin(v)*sin(u) ; \
yu: sin(v)*cos(u); \
zu: 0; \
xv: cos(u)*cos(v); \
yv: sin(u)*cos(v); \
zv: -sin(v) + 1/(2*cos(0.5*v)*cos(0.5*v)*tan(0.5*v)); \
xn: (-sin(v) + 1/(2*cos(0.5*v)*cos(0.5*v)*tan(0.5*v)))*cos(u)*sin(v); \
yn: (-sin(v) + 1/(2*cos(0.5*v)*cos(0.5*v)*tan(0.5*v)))*sin(u)*sin(v); \
zn: -cos(v)*sin(v); \
xuu: -cos(u)*sin(v); \
yuu: -sin(u)*sin(v); \
zuu: 0; \
xuv: -cos(v)*sin(u); \
yuv: cos(u)*cos(v); \
zuv: 0; \
xvv: -cos(u)*sin(v); \
yvv: -sin(u)*sin(v); \
zvv: -cos(v) - (1/(2*cos(0.5*v)*sin(0.5*v)))^2 + 1/(2*cos(0.5*v)*cos(0.5*v));";
#endif