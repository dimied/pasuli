
#include "loop.h"
#include "surfaces_c_includes.h"

#if (USE_LOOP != 0)
void Loop(double u, double v,
		  double *constants,
		  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(LOOP)

	double cv = cos(v);
	double sv = sin(v);
	double cu = cos(u);

	P_X(sv * cu);
	P_Y(2.0 * sv * cv);
	P_Z(4.0 * sv * cv);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
	double su = sin(u);
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
PaSuLiDefDesc pslddLoop = {
	PSLDD_ID(LOOP)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_START_PI | PASULI_U_END_PI |
		PASULI_V_START_PI | PASULI_V_END_PI,
	-1, 1, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descLoop =
	"name: Loop; \
ut:c; vt:c; \
us:pi: -1; ue:pi: 1; \
vs:pi: -1; ve:pi: 1; \
x: sin(v)*cos(u); \
y: 2*cos(v); \
z: 4*sin(v)*cos(v); \
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