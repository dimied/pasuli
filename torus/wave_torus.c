
#include "wave_torus.h"
#include "torus_c_includes.h"

#if (USE_WAVE_TORUS != 0)
void WaveTorus(pasuli_vartype u, pasuli_vartype v,
			   pasuli_consttype *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(WAVE_TORUS)

	pasuli_vartype R = constants[0];
	pasuli_vartype r = constants[1];
	pasuli_vartype a = constants[2];
	pasuli_vartype N = constants[3];

#if ((PARTICLE_POS != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0) || (PARTICLE_N != 0))
	pasuli_vartype cos_u = cos(u);
	pasuli_vartype sin_u = sin(u);
	pasuli_vartype cos_v = cos(v);
	pasuli_vartype sin_v = sin(v);
#endif

#if ((PARTICLE_VD != 0) || (PARTICLE_UD != 0) || (PARTICLE_N != 0))
	pasuli_vartype cos_Nu = cos(N * u);
	pasuli_vartype sin_Nu = sin(N * u);
#endif

	pasuli_vartype posxyz = r + a * sin(N * u);
	pasuli_vartype posxy = cos_v * posxyz + R;

#if (PARTICLE_POS != 0)
	P_X(posxy * cos_u);
	P_Y(posxy * sin_u);
	P_Z(posxyz * sin_v);
#endif

#if ((PARTICLE_UD != 0) || (PARTICLE_N != 0))
	UD_X(-R * sin_u + cos_v * (a * (N * cos(N * u) * cos(u) - sin(u) * sin(N * u)) - r * sin(u)));
	UD_Y(-R * cos_u + cos_v * (a * (N * cos(N * u) * sin(u) - cos(u) * sin(N * u)) - r * cos(u)));
	UD_Z(a * N * cos_Nu * sin_v);
#endif

#if ((PARTICLE_VD != 0) || (PARTICLE_N != 0))
	VD_X(-(r + a * sin_Nu) * sin_v * cos_u);
	VD_Y(-(r + a * sin_Nu) * sin_v * sin_u);
	VD_Z((r + a * sin_Nu) * cos_v);
#endif

#if (PARTICLE_N != 0)
	PASULI_CALC_NORMAL_FROM_UD_VD
#endif
}
#endif

#include "torus_desc.h"
#include "torus_const.h"

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddWaveTorus = {
	PSLDD_ID(WAVE_TORUS)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(4),
	0, 2, 0, 2, torus_def_constants};
#endif
/*

Eigen code

a1 = d((R + cos(v)*(r + a*sin(n*u)))*cos(u), u)
b1 = d((R + cos(v)*(r + a sin(n*u)))*sin(u), u)
c1 = d((r + a*sin(n*u))*sin(v), u)

d1 = d((R + cos(v)*(r + a*sin(n*u)))*cos(u), v)
e1 = d((R + cos(v)*(r + a sin(n*u)))*sin(u), v)
f1 = d((r + a*sin(n*u))*sin(v), v)

U = (ux,uy,uz)
V = (vx,vy,vz)
A = outer(U, V)
A

B = (b1*f1 - c1*e1, c1*d1 - a1*f1, a1*e1 - b1*d1)
B
*/

#if (COMPILE_DESC_TORUS != 0)
char *descWaveTorus =
	"name: wave torus; \
cat: torus;\
ut: c; vt: c;\
us:0; ue:pi:2;\
vs:0; ve:pi:2;\
c1:R:1.5; c2:r:0.5; c3:a:1; c4:n:1; \
x: (R + cos(v)*(r + a*sin(n*u)))*cos(u); \
y: (R + cos(v)*(r + a*sin(n*u)))*sin(u); \
z: (r + a*sin(n*u))*sin(v); \
xu: -R*sin(u) + cos(v)*(a*(n*cos(n*u)*cos(u) - sin(u)*sin(n*u)) -  r*sin(u)); \
yu: -R*cos(u) + cos(v)*(a*(n*cos(n*u)*sin(u) - cos(u)*sin(n*u)) -  r*cos(u)); \
zu: a*n*cos(n*u)*sin(v); \
xv: -(r + a*sin(n*u))*sin(v)*cos(u); \
yv: -(r + a*sin(n*u))*sin(v)*sin(u); \
zv: (r + a*sin(n*u))*cos(v); \
xn: a^2*n*cos(v)^2*cos(n*u)*sin(u)*sin(n*u) + \
a^2*n*cos(n*u)*sin(u)*sin(v)^2*sin(n*u) + \
a^2*cos(u)*cos(v)^2*sin(n*u)^2 +\
a*n*r*cos(v)^2*cos(n*u)*sin(u) +\
a*n*r*cos(n*u)*sin(u)*sin(v)^2 +\
2*a*r*cos(u)*cos(v)^2*sin(n*u) +\
a*R*cos(u)*cos(v)*sin(n*u) +\
r*2*cos(u)*cos(v)^2 + \
r*R*cos(u)*cos(v); \
yn: −a^2*n*cos(u)*cos(v)^2*cos(n*u)*sin(n*u) −\
a^2*n*cos(u)*cos(n*u)*sin(v)^2*sin(n*u) +\
a^2*cos(v)^2*sin(u)*sin(n*u)^2 −\
a*n*r*cos(u)*cos(v)^2*cos(n*u) −\
a*n*r*cos(u)*cos(n*u)*sin(v)^2 +\
2*a*r*cos(v)^2*sin(u)*sin(n*u) +\
a*R*cos(v)*sin(u)*sin(n*u) +\
r*2*cos(v)^2*sin(u) + \
r*R*cos(v)*sin(u); \
zn: a*2*cos(u)^2*cos(v)*sin(v)*sin(n*u)^2 +\
a*2*cos(v)*sin(u)^2*sin(v)*sin(n*u)^2 +\
2*a*r*cos(u)^2*cos(v)*sin(v)*sin(n*u) +\
2*a*r*cos(v)*sin(u)^2*sin(v)*sin(n*u) +\
a*R*cos(u)^2*sin(v)*sin(n*u) +\
a*R*sin(u)^2*sin(v)*sin(n*u) +\
r*2*cos(u)^2*cos(v)*sin(v) +\
r*2*cos(v)*sin(u)^2*sin(v) +\
r*R*cos(u)^2*sin(v) +\
r*R*sin(u)^2*sin(v); \
xuu: -cos(u)*(R + a*cos(v)*sin(n*u) + a*n*n*cos(v)*sin(n*u) + r*cos(v)) - 2*a*n*cos(v)*cos(n*u)*sin(u); \
yuu: -sin(u)*(R + a*cos(v)*sin(n*u) + a*n*n*cos(v)*sin(n*u) + r*cos(v)) -  2*a*n*cos(v)*cos(n*u)*cos(u); \
zuu: -a*n*n*sin(v)*sin(n*u); \
xuv: (-a*n*cos(u)*cos(n*u) + sin(u)*(a*sin(n*u) + r))*sin(v); \
yuv: -(a*n*sin(u)*cos(n*u) + cos(u)*(a*sin(n*u) + r))*sin(v); \
zuv: a*n*cos(v)*cos(n*u); \
xvv: -(r + a*sin(n*u))*cos(v)*cos(u); \
yvv: -(r + a*sin(n*u))*cos(v)*sin(u); \
zvv: (r + a*sin(n*u))*sin(v);";

#endif
