
#include "tranguloid_trefoil.h"
#include "surfaces_c_includes.h"

#if (USE_TRANGULOID_TREFOIL != 0)
void TranguloidTrefoil(double u, double v,
					   double *constants,
					   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(TRANGULOID_TREFOIL)

	double x_u = 2 * sin(3.0 * u);
	double y_u = 2 * (sin(u) + 2 * sin(2 * u));
	double z_u = cos(u) - 2 * cos(2 * u);
	z_u *= 0.25;

	double cos_v_plus_2 = 2.0 + cos(v);

	P_X(x_u / cos_v_plus_2);
	P_Y(y_u / (2 + cos(v + 2 * MY_PI / 3.0)));
	P_Z(z_u * cos_v_plus_2 * (2 + cos(v + 2 * MY_PI / 3.0)));

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

#if (PARTICLE_N != 0)
	N_X(0);
	N_Y(0);
	N_Z(0);
#endif

#if (PARTICLE_UUD != 0)
	UUD_X(0);
	UUD_Y(0);
	UUD_Z(0);
#endif
#if (PARTICLE_UVD != 0)
	UVD_X(0);
	UVD_Y(0);
	UVD_Z(0);
#endif
#if (PARTICLE_VVD != 0)
	VVD_X(0);
	VVD_Y(0);
	VVD_Z(0);
#endif
}
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTranguloidTrefoil = {
PSLDD_ID( TRANGULOID_TREFOIL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTranguloidTrefoil =
"name: Tranguloid Trefoil; \
ut:c; vt:c; \
us:pi: -1; ue:pi: 1; \
vs:pi: -1; ve:pi: 1; \
x: 2*sin(3*u)/(2 + cos(v)); \
y: 2*(sin(u) + 2*sin(2*u))/(2 + cos(v + 2*pi/3)); \
z: (cos(u) - 2*cos(2*u))*(2 + cos(v))*(2 + cos(v + 2*pi/3))/4; \
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