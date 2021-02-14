
#include "open_sphere.h"
#include "sphere_c_includes.h"

#if (USE_OPEN_SPHERE != 0)
void OpenSphere(pasuli_vartype u,
				pasuli_vartype v,
				pasuli_consttype *constants,
				PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(OPEN_SPHERE)

	double uq = u * u;
	double vq = v * v;
	double divisor = 1 + uq + vq;

	P_X((2.0 * u) / divisor);
	P_Y((uq + vq - 1) / divisor);
	P_Z((2.0 * v) / divisor);

	double divq = divisor * divisor;

	UD_X(2 * (1 - uq + vq) / (divq * divisor));
	UD_Y((4 * u) / divq);
	UD_Z(-4 * u * v / divq);

	VD_X(PASULI_COND_COPY_UD_Z(-4 * u * v / divq));
	VD_Y(4 * v / divq);
	VD_Z(2 * (1 - vq * vq + uq * (2 + uq)) / (divq * divisor));

	double div3 = divq * divisor;
	N_X(8 * u / (div3));
	N_Y(4 * (vq + uq - 1) / (div3));
	N_Z(8 * v / (div3));

	UUD_X(4 * u * (uq - 3 * (1 + vq)) / (div3));
	UUD_Y(4 * (1 - 3 * uq + vq) / div3);
	UUD_Z(4 * v * (-1 + 3 * uq - vq) / div3);

	UVD_X(4 * v * (-1 + 3 * uq - vq) / div3);
	UVD_Y(-16 * u * v / div3);
	UVD_Z(4 * u * (3 * vq - uq - 1) / div3);

	VVD_X(4 * u * (3 * vq - uq - 1) / div3);
	VVD_Y(4 * (1 + uq - 3 * vq) / div3);
	VVD_Z(4 * v * (vq - 3 * (1 + uq)) / div3);
}
#endif

#if (COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddOpenSphere = {
	PSLDD_ID(OPEN_SPHERE)
			PASULI_FULL_IMPL |
		PASULI_U_CLOSED | PASULI_V_CLOSED,
	-10, 10, -10, 10, 0};
#endif
#if (COMPILE_DESC_SPHERE != 0)
char *descOpenSphere =
	"name: open sphere; \
cat: sphere; \
ut: o; \
vt: o; \
us: -10; \
ue: 10; \
vs: -10; \
ve: 10; \
x: 2*u/(1 + u*u + v*v); \
y: (u*u + v*v - 1)/(1 + u*u + v*v); \
z: 2*v/(1 + u*u + v*v); "
#if (COMPILE_DESC_DERIV_U_SPHERE != 0)
	"xu: 2*(1 - u*u + v*v)/((1 + u*u + v*v)^2); \
yu: 4*u/((1 + u*u + v*v)^2); \
zu: -4*u*v/((1 + u*u + v*v)^2); "
#endif
#if (COMPILE_DESC_DERIV_V_SPHERE != 0)
	"xv: -4*u*v/((1 + u*u + v*v)^2); \
yv: 4*v/((1 + u*u + v*v)^2); \
zv: 2*(1+u*u - v*v)/((1 + u*u + v*v)^2); "
#endif
#if (COMPILE_DESC_NORMAL_SPHERE != 0)
	"xn: 8*u/((1 + u*u + v*v)^3); \
yn: 4*(-1 + u*u + v*v)/((1 + u*u + v*v)^3); \
zn: 8*v/((1 + u*u + v*v)^3); "
#endif
#if (COMPILE_DESC_DERIV2_U_SPHERE != 0)
	"xuu: 4*u*(u*u - 3*(1+v*v))/((1 + u*u + v*v)^3); \
yuu: 4*(1+v*v-3*u*u)/((1 + u*u + v*v)^3); \
zuu: 4*v*(3*u*u - (1+v*v))/((1 + u*u + v*v)^3); "
#endif
#if (COMPILE_DESC_DERIV_UV_SPHERE != 0)
	"xuv: 4*v*(3*u*u - (1+v*v))/((1 + u*u + v*v)^3); \
yuv: -(16*u*v)/((1 + u*u + v*v)^3); \
zuv: 4*u*(3*v*v - (1+u*u))/((1 + u*u + v*v)^3); "
#endif
#if (COMPILE_DESC_DERIV2_U_SPHERE != 0)
	"xvv: 4*u*(3*v*v - (1+u*u))/((1 + u*u + v*v)^3); \
yvv: 4*(1+u*u-3*v*v)/((1 + u*u + v*v)^3); \
zvv: 4*v*(v*v - 3*(1+u*u))/((1 + u*u + v*v)^3); "
#endif
	"end;";
#endif