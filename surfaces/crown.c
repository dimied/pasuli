
#include "crown.h"
#include "surfaces_c_includes.h"

#if (USE_CROWN != 0)
void Crown(double u, double v,
		   double *constants,
		   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(CROWN)

	double cossin_u = cos(u) * sin(u);
	double cos_u4_3 = cos(u + 4.0) / 3.0;
	u = 0.5 * cos(u);

	double cossin_v = sin(v);
	v = cos(v);
	cossin_v *= v;

	P_X(cos_u4_3);
	P_Y(cossin_u * cossin_v * v + u);
	P_Z(cossin_u * cossin_v);

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

#if (COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCrown = {
	PSLDD_ID(CROWN)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI | PASULI_V_END_PI,
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descCrown =
	"name: Crown; \
ut:c; vt:c; \
us: 0; ue:pi: 2; \
vs: 0; ve:pi: 2; \
x: cos(u + 4)/3; \
y: cos(u)*sin(v)*cos(v)*sin(u)*cos(v) + 0.5*cos(u); \
z: cos(v)*sin(u)*cos(u)*sin(v); \
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