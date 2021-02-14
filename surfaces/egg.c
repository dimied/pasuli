
#include "egg.h"
#include "surfaces_c_includes.h"

#if (USE_EGG != 0)
void Egg(double u, double v,
		 double *constants,
		 PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(EGG)

	double a = constants[0];
	double b = constants[1];
	double c = constants[2];
	double fx = c * sqrt(u * (u - a) * (u - b));

	P_X(fx * sin(v));
	P_Y(u);
	P_Z(fx * cos(v));

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
	double cu = cos(u);
	double su = sin(u);
	double cv = cos(v);
	double sv = sin(v);
#endif

	UD_X(0);
	UD_Y(0);
	UD_Z(0);

	VD_X(0);
	VD_Y(0);
	VD_Z(0);

	N_X(0);
	N_Y(0);
	N_Z(0);

	UUD_X(0);
	UUD_Y(0);
	UUD_Z(0);

	UVD_X(0);
	UVD_Y(0);
	UVD_Z(0);

	VVD_X(0);
	VVD_Y(0);
	VVD_Z(0);
}
#endif

#if (COMPILE_DEF_DESC_SURFACES != 0) //TODO TODO
PaSuLiDefDesc pslddEgg = {
	PSLDD_ID(EGG)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_V_END_PI | PASULI_CONST_COUNT(3) |
		PASULI_CALC_U_END,
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descEgg =
	"name: Egg; \
ut: c; vt: c; \
us: 0; ue: c1: 1; \
vs: 0; ve:pi: 2; \
c1:a:<=c1: 0.5; \
c2:b: 0.5; \
c3:c: 1.0; \
x: c*sqrt(u*(u - a)*(u - b))*sin(v); \
y: u; \
z: c*sqrt(u*(u - a)*(u - b))*cos(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif