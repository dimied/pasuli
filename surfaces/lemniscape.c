
#include "lemniscape.h"
#include "surfaces_c_includes.h"

#if (USE_LEMNISCAPE != 0)
void Lemniscape(pasuli_vartype u, pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(LEMNISCAPE)

	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sqrt_abs_sin_2u = sqrt(fabs(sin(2 * u)));
	pasuli_calctype sqrt_abs_sin_2u_cos_v = sqrt_abs_sin_2u * cos_v;
	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);

	pasuli_calctype x = sqrt_abs_sin_2u_cos_v * cos_u;
	pasuli_calctype y = sqrt_abs_sin_2u_cos_v * sin_u;
	//pasuli_calctype tan_v = tan(v);
	pasuli_calctype sin_v = sin(v);

	P_X(x);
	P_Y(y);
	// sqrt(fabs(sin(2 * u)))^2*(cos(u)^2*cos(v)^2 - sin(u)^2*cos(v)^2
	// + 2*cos(u)*sin(u)*cos(v)^2tan(v)^2 )
	// (1-2*sin(u)^2)*cos(v)^2 + 2*cos(u)*sin(u)*sin(v)^2
	// (1-2*sin(u)^2)*cos(v)^2 + sin(2*u)*sin(v)^2
	P_Z(((1 - 2 * sin_u * sin_u) * cos_v * cos_v + sin(2 * u) * sin_v * sin_v) * sqrt_abs_sin_2u * sqrt_abs_sin_2u);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddLemniscape = {
	PSLDD_ID(LEMNISCAPE)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI | PASULI_V_END_PI,
	0, 1, 0, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descLemniscape =
	"name: Lemniscape; \
ut:c; vt:c; \
us: 0; ue:pi: 1; \
vs: 0; ve:pi: 1; \
x: cos(v)*sqrt(abs(sin(2*u)))*cos(u); \
y: cos(v)*sqrt(abs(sin(2*u)))*sin(u); \
z: x*x - y*y + 2*x*y*tan(v)^(2);";
#endif