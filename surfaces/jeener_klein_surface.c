
#include "jeener_klein_surface.h"
#include "surfaces_c_includes.h"

#if (USE_JEENER_KLEIN_SURFACE != 0)
void JeenerKleinSurface(pasuli_vartype u, pasuli_vartype v,
						pasuli_consttype *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(JEENER_KLEIN_SURFACE)

	pasuli_consttype a = constants[0];
	pasuli_consttype S = constants[1];
	pasuli_consttype T = constants[2];

	pasuli_calctype W = (S + 1) * 0.25 * cos((S + 1) * u + MY_PI / T) + sqrt(a);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	pasuli_calctype Scos_u = S * cos(u);
	pasuli_calctype Ssin_u = S * sin(u);
	pasuli_calctype cos_Su = cos(S * u);
	pasuli_calctype sin_Su = sin(S * u);
	pasuli_calctype W_cos = W * cos((S - 1) * u * 0.5);
	pasuli_calctype W_sin = W * sin((S - 1) * u * 0.5);

	P_X(Scos_u + cos_Su - W_sin * cos_v);
	P_Y(Ssin_u - sin_Su - W_cos * cos_v);
	P_Z(W * sin_v);
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddJeenerKleinSurface = {
PSLDD_ID( JEENER_KLEIN_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(3),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descJeenerKleinSurface =
	"name: Jeener Klein Surface; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs: 0; ve:pi: 2; \
c1:S: 1.5; c2:T: 0.5; c3:a: 1.0; \
a1:W: ((S + 1)/4)*cos((S + 1)*u +pi/T) + sqrt(a); \
x: S*cos(u) + cos(S*u) - W*sin((S - 1)*u/2)*cos(v); \
y: S*sin(u) - sin(S*u) - W*cos((S - 1)*u/2)*cos(v); \
z: W*sin(v); ";
#endif