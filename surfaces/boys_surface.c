
#include "boys_surface.h"
#include "surfaces_c_includes.h"

#if (USE_BOYS_SURFACE != 0)
void BoysSurface(pasuli_vartype u, pasuli_vartype v,
				 double *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(BOYS_SURFACE)

	pasuli_calctype a = sqrt(2.0);
	pasuli_calctype b = a - sin(3 * v) * sin(2 * u);

	pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);

	P_X(cos_u * (cos_u * cos(2 * v) - a * sin_u * cos(v)) / b);
	P_Y(cos_u * (cos_u * sin(2 * v) - a * sin_u * sin(v)) / b);
	P_Z(3 * cos_u * cos_u / b);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBoysSurface = {
	BOYS_SURFACE,
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_START_PI | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(0),
	-0.5, 0.5, 0, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
// See: https://mathcurve.com/surfaces.gb/boy/boy.shtml
char *descBoysSurface =
	"name: Boys Surface;\
ut:c;\
vt:c;\
us:pi: -0.5; ue:pi: 0.5;\
vs:0; ve:pi:1;\
a1:a: sqrt(2);\
a2:b: a - sin(3*v)*sin(2*u);\
x: cos(u)*(cos(u)*cos(2*v) + a*sin(u)*cos(v))/b;\
y: cos(u)*(cos(u)*sin(2*v) - a*sin(u)*sin(v))/b;\
z: 3*cos(u)*cos(u)/b;";
#endif