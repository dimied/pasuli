
#include "bonan_jeener_klein_surface.h"
#include "surfaces_c_includes.h"

#if (USE_BONAN_JEENER_KLEIN_SURFACE != 0)

void BonanJeenerKleinSurface(pasuli_vartype u, pasuli_vartype v,
							 pasuli_consttype *constants,
							 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(BONAN_JEENER_KLEIN_SURFACE)

	pasuli_consttype M = constants[0];
	pasuli_consttype T = constants[1];

	pasuli_calctype cos_v = cos(v);

	pasuli_calctype W = sin((M - 1) * u) + T;

	P_X(M * cos(u) - cos(M * u) - W * (M - 1) * sin((M + 1) * u * 0.5) * cos_v / M);
	P_Y(W * sin(v));
	P_Z(M * sin(u) - sin(M * u) - W * (M - 1) * cos((M + 1) * u * 0.5) * cos_v / M);

	// No further calculations, because errors would be too large
}
#endif

/*
#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBonanJeenerKleinSurface = {
PSLDD_ID( BONAN_JEENER_KLEIN_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
*/
#if (COMPILE_DESC_SURFACES != 0)
char *descBonanJeenerKleinSurface =
	"name: Bonan Jeener Klein Surface;\
ut:c; vt:c;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
c1:M: 1.5; c2:T: 0.5;\
a1:W: sin((M - 1)*u) + T;\
x: M*cos(u) - cos(M*u) - ((M - 1)/M)*W*sin((M + 1)*u/2)*cos(v);\
y: W*sin(v);\
z: M*sin(u) - sin(M*u) + ((M - 1)/M)*W*cos((M + 1)*u/2)*cos(v);";
#endif
