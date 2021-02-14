
#include "kuens_surface.h"
#include "surfaces_c_includes.h"

#if (USE_KUENS_SURFACE != 0)
void KuensSurface(pasuli_vartype u, pasuli_vartype v,
				  pasuli_consttype *constants,
				  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(KUENS_SURFACE)

	double x_u = cos(u);
	double u_sq = sin(u);
	double y_u = 2.0 * (u_sq - u * x_u);
	x_u = 2.0 * (x_u + u * u_sq);
	u_sq = u * u;

	double sin_v = sin(v);
	double h = 1 + u_sq * sin_v * sin_v;

	P_X(x_u * sin_v / h);
	P_Y(y_u * sin_v / h);
	P_Z(log(tan(v * 0.2)) + 2 * cos(v) / h);

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
PaSuLiDefDesc pslddKuensSurface = {
	PSLDD_ID(KUENS_SURFACE)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED,
	-4.3f, 4.3f, 0.03f, 3.11f, 0};
#endif
#if (COMPILE_DESC_SURFACES != 0)
char *descKuensSurface =
	"name: Kuens Surface; \
ut:c; vt:c; \
us: -4.3; ue: 4.3; \
vs: 0.01; ve: 3.11; \
a:1:h: 1 + u*u*sin(v)*sin(v); \
x: (2*(cos(u) + u sin(u))*sin(v))/h; \
y: (2*(-u*cos(u) + sin(u))*sin(v))/h; \
z: log(tan(v/2)) + 2*cos(v)/h; \
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