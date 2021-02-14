
#include "folium.h"
#include "surfaces_c_includes.h"

#if (USE_FOLIUM != 0)
void Folium(pasuli_vartype u, pasuli_vartype v,
			pasuli_consttype *constants,
			PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(FOLIUM)

	double two_pi_3 = 2.0 * MY_PI / 3.0;

	double y_u = cos(u + two_pi_3);
	double z_u = cos(u - two_pi_3);
	double cu = cos(u);
	double chv = cosh(v);

	P_X(cu * ((2.0 * v) / MY_PI - tanh(v)));
	P_Y(y_u / chv);
	P_Z(z_u / chv);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
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
PaSuLiDefDesc pslddFolium = {
	PSLDD_ID(FOLIUM)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_START_PI | PASULI_U_END_PI |
		PASULI_V_START_PI | PASULI_V_END_PI,
	-1, 1, -1, 1, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descFolium =
	"name: Folium; \
ut:c; vt:c; \
us:pi: -1; ue:pi: 1; \
vs:pi: -1; ve:pi: 1; \
x: cos(u)*(2*v/pi - tanh(v)); \
y: cos(u + 2*pi/3)/cosh(v); \
z: cos(u - 2*pi/3)/cosh(v); \
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