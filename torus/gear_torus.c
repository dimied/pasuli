
#include "gear_torus.h"
#include "torus_c_includes.h"

#if (USE_GEAR_TORUS != 0)
void GearTorus(pasuli_vartype u,
			   pasuli_vartype v,
			   pasuli_consttype *constants,
			   PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(GEAR_TORUS)

	pasuli_vartype R = constants[0];
	pasuli_vartype a = constants[1];
	pasuli_vartype b = constants[2];
	pasuli_vartype N = constants[3];

	pasuli_vartype r = a + tanh(b * sin(N * v)) / b;

	P_Y(r * sin(v));
	v = R + r * cos(v);

	P_X(v * cos(u));
	P_Z(v * sin(u));

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	pasuli_vartype cv = cos(v);
	pasuli_vartype sv = sin(v);
#endif

	UD_X(-su);
	UD_Y(-cu);
	UD_Z(0);

	VD_X(-r * sv * cu);
	VD_Y(-r * sv * su);
	VD_Z(-r * cv);

#if (PARTICLE_N != 0)
	pO->n[0] = cu * r * cv;
	pO->n[1] = su * r * sv;
	pO->n[2] = r * sv;
#endif

#if (PARTICLE_UUD != 0)
	pO->uud[0] = cos(u);
	pO->uud[1] = sin(u);
	pO->uud[2] = 0;
#endif
#if (PARTICLE_UVD != 0)
	pO->uvd[0] = r * sv * su;
	pO->uvd[1] = -r * sv * cu;
	pO->uvd[2] = 0;
#endif
#if (PARTICLE_VVD != 0)
	pO->vvd[0] = -r * cv * cu;
	pO->vvd[1] = -r * cv * su;
	pO->vvd[2] = -r * sv;
#endif
}
#endif

#include "torus_desc.h"

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddGearTorus = {
	PSLDD_ID(GEAR_TORUS)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_FULL_IMPL | PASULI_CONST_COUNT(4),
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descGearTorus =
	"name: GearTorus; \
cat: torus; \
us: 0; ue:pi:2; \
vs: 0; ve:pi:2; \
c1:R:1; c2:a:1; c3:b:1; c4:N:1; \
a1:r: a + tanh(b*sin(n*v))/b; \
x: (R + r*cos(v))*cos(u); \
y: r*sin(v); \
z: (R + r*cos(v))*sin(u); "
#if (COMPILE_DESC_DERIV_U_TORUS != 0)
	"xu: -(cos(v)*(a*b+tanh(b*sin(n*v)))+ R*b)*sin(u)/b; \
yu: 0; \
zu: (cos(v)*(a*b+tanh(b*sin(n*v)))+ R*b)*cos(u)/b; "
#endif
#if (COMPILE_DESC_DERIV_V_TORUS != 0)
	"xv: (-a*sin(v) + (n*cos(v)*cos(n*v))/(cosh(b*sin(n*v))^2) - sin(v)*tanh(b*sin(n*v))/b)*cos(u); \
yv: a*cos(v) + ()/(cosh(b*sin(n*v))^2) +cos(v)*tanh(b*sin(n*v))/b); \
zv: (-a*sin(v) + (n*cos(v)*cos(n*v))/(cosh(b*sin(n*v))^2) - sin(v)*tanh(b*sin(n*v))/b)*sin(u); "
#endif
#if (COMPILE_DESC_NORMAL_TORUS != 0)
	"xn:X; \
xn: (-R*a*cos(v) - (R*n*cos(n*v)*sin(v))/(cosh(b*sin(n*v))^2) - \
(R*cos(v)*tanh(b*sin(n*v)))/b - (a*n*cos(v)*cos(n*v)*sin(v))/(cosh(b*sin(n*v))^2) - \
(2*a*cos(v)*cos(v)*tanh(b*sin(n*v)))/b - a*a*cos(v)*cos(v) - \
((cos(v)*tanh(b*sin(n*v))/(b))^2) - \
(n*cos(v)*cos(n*v)*sin(v)*tanh(b*sin(n*v)))/((cosh(b*sin(n*v))^2)*b) )*cos(u); \
yn:X; \
yn: -R*a*sin(v) + (R*n*cos(v)*cos(n*v))/(cosh(b*sin(n*v))^2) - (R*sin(v)*tanh(b*sin(n*v)))/b + \
(a*n*cos(v)*cos(v)*cos(n*v))/(cosh(b*sin(n*v))^2) - (2*a*cos(v)*sin(v)*tanh(b*sin(n*v)))/b - \
a*a*cos(v)*sin(v) - cos(v)*sin(v)*((tanh(b*sin(n*v)))/(b))^2 + \
(n*cos(v)*cos(v)*cos(n*v)*tanh(b*sin(n*v)))/(b*(cosh(b*sin(n*v))^2)); \
zn:X; \
zn: (-R*a*cos(v) - (R*n*cos(n*v)*sin(v))/(cosh(b*sin(n*v))^2) - \
(R*cos(v)*tanh(b*sin(n*v)))/b - (a*n*cos(v)*cos(n*v)*sin(v))/(cosh(b*sin(n*v))^2) - \
(2*a*cos(v)*cos(v)*tanh(b*sin(n*v)))/b - a*a*cos(v)*cos(v) - \
((cos(v)*tanh(b*sin(n*v))/(b))^2) - \
(n*cos(v)*cos(n*v)*sin(v)*tanh(b*sin(n*v)))/((cosh(b*sin(n*v))^2)*b) )*sin(u); "
#endif
#if (COMPILE_DESC_DERIV2_U_TORUS != 0)
	"xuu: -(R*b + cos(v)*(a*b + tanh(b*sin(n*v))))*cos(u)/b; \
yuu: 0; \
zuu: -(R*b + cos(v)*(a*b + tanh(b*sin(n*v))))*sin(u)/b; "
#endif
#if (COMPILE_DESC_DERIV_UV_TORUS != 0)
	"xuv: sin(u)*(a*sin(v) - (n*cos(v)*cos(n*v))/(cosh(b*sin(n*v))^2) + (sin(v)*tanh(b*sin(n*v)))/b); \
yuv: 0; \
zuv: -cos(u)*(a*sin(v) - (n*cos(v)*cos(n*v))/(cosh(b*sin(n*v))^2) + (sin(v)*tanh(b*sin(n*v)))/b); "
#endif
#if (COMPILE_DESC_DERIV2_V_TORUS != 0)
	"xvv: (-a*cos(v) - (2*b*n*n*cos(v)*(cos(n*v)^2)*sinh(b*sin(n*v)))/(cosh(b*sin(n*v))^3) - \
(2*n*cos(n*v)*sin(v))/(cosh(b*sin(n*v))^2) - (cos(v)*tanh(b*sin(n*v)))/b - \
(n*n*cos(v)*sin(n*v))/(cosh(b*sin(n*v))^2))*cos(u); \
yvv: -a*sin(v) - (2*b*n*n*(cos(n*v)^2)*sin(v)*sinh(b*sin(n*v)))/(cosh(b*sin(n*v))^3) + \
(2*n*cos(v)*cos(n*v))/(cosh(b*sin(n*v))^2) - (sin(v)*tanh(b*sin(n*v)))/b - \
(n*n*sin(v)*sin(n*v))/(cosh(b*sin(n*v))^2); \
zvv: (-a*cos(v) - (2*b*n*n*cos(v)*(cos(n*v)^2)*sinh(b*sin(n*v)))/(cosh(b*sin(n*v))^3) - \
(2*n*cos(n*v)*sin(v))/(cosh(b*sin(n*v))^2) - (cos(v)*tanh(b*sin(n*v)))/b - \
(n*n*cos(v)*sin(n*v))/(cosh(b*sin(n*v))^2))*sin(u); "
#endif
	"";
#endif
