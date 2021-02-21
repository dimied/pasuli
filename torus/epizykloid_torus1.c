
#include "epizykloid_torus1.h"
#include "torus_c_includes.h"

#if (USE_EPIZYKLOID_TORUS_1 != 0)

void EpizykloidTorus1(pasuli_vartype u,
					  pasuli_vartype v,
					  pasuli_consttype *constants,
					  PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(EPIZYKLOID_TORUS_1)

	pasuli_consttype R1 = constants[0];
	pasuli_consttype R = constants[1];
	pasuli_consttype r = constants[2];
	pasuli_consttype h = constants[3];
	R += r;

pasuli_calctype cos_u = cos(u);
	pasuli_calctype sin_u = sin(u);
	pasuli_calctype cos_v = cos(v);
	pasuli_calctype sin_v = sin(v);

	pasuli_calctype rrr_cos_v = R1 + (R)*cos(v);

	P_Y((R)*sin(v) - h * sin(((R)*v) / r));
	v = h * cos(((R)*v) / r);

	P_X(rrr_cos_v - cos(u) * v);
	P_Z(rrr_cos_v - sin(u) * v);

#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
	
#endif

	UD_X(-sin_u);
	UD_Y(-cos_u);
	UD_Z(0);

	VD_X(-r * sin_v * cos_u);
	VD_Y(-r * sin_v * sin_u);
	VD_Z(-r * cos_v);

#if (PARTICLE_N != 0)
	pO->n[0] = cos_u * r * cos_v;
	pO->n[1] = sin_u * r * sin_v;
	pO->n[2] = r * sin_v;
#endif

#if (PARTICLE_UUD != 0)
	pO->uud[0] = cos(u);
	pO->uud[1] = sin(u);
	pO->uud[2] = 0;
#endif
#if (PARTICLE_UVD != 0)
	pO->uvd[0] = r * sin_v * sin_u;
	pO->uvd[1] = -r * sin_v * cos_u;
	pO->uvd[2] = 0;
#endif
#if (PARTICLE_VVD != 0)
	pO->vvd[0] = -r * cos_v * cos_u;
	pO->vvd[1] = -r * cos_v * sin_u;
	pO->vvd[2] = -r * sin_v;
#endif
}
#endif

#if (COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddEpizykloidTorus1 = {
	PSLDD_ID(EPIZYKLOID_TORUS_1)
			PASULI_U_CLOSED |
		PASULI_V_CLOSED | PASULI_U_END_PI |
		PASULI_V_END_PI | PASULI_CONST_COUNT(4),
	0, 2, 0, 2, 0};
#endif
#if (COMPILE_DESC_TORUS != 0)
char *descEpizykloidTorus1 =
	"name: Epizykloid Torus 1;\
cat: torus;\
us: 0; ue:pi:2;\
vs: 0; ve:pi:2;\
c1:R1:1; c2:R: 1; c3:r:0.5; c4:h: 1;\
x: (R1 + (R + r)*cos(v) - h*cos(((R + r)/r)*v))*cos(u);\
y: (R1 + (R + r)*cos(v) - h*cos(((R + r)/r)*v))*sin(u);\
z: (R + r)*sin(v) - h*sin(((R + r)/r)*v);";
#endif
