
#include "umbillictorus.h"
#include <math.h>

#if (COMPILE_TORUS != 0)
void UmbillicTorus(pasuli_vartype u, pasuli_vartype v,
				   pasuli_consttype *constants, PaSuLiObject *pO)
{
	PASULI_SET_TYPE_ID(UMBILLIC_TORUS)

	//pasuli_vartype R = constants[0];
	//pasuli_vartype r = constants[1];

	pasuli_vartype cos_u = cos(u);
	pasuli_vartype sin_u = sin(u);
	u = u / 3.0; //u = u/3.0

	pasuli_vartype u_minus2 = u - 2 * v;
	pasuli_vartype u_plus = u + v;
	pasuli_vartype x_or_y = 7.0 + cos(u_minus2) + 2 * cos(u_plus);

#if (PARTICLE_POS != 0)
	P_X(sin_u * x_or_y);
	P_Y(cos_u * x_or_y);
	P_Z(sin(u_minus2) + 2 * sin(u_plus));
#endif

/*
#if (PARTICLE_N != 0)
	pO->n[0] = cu * r * cv;
	pO->n[1] = su * r * sv;
	pO->n[2] = r * sv;
#endif
*/

/*
#if ((PARTICLE_UD != 0) || (PARTICLE_VD != 0) || (PARTICLE_UD != 0))
	pasuli_vartype cu = cos(u);
	pasuli_vartype su = sin(u);
	pasuli_vartype cv = cos(v);
	pasuli_vartype sv = sin(v);
#endif

	UD_X(su);
	UD_Y(cu);
	UD_Z(0);

	VD_X(-r * sv * cu);
	VD_Y(-r * sv * su);
	VD_Z(-r * cv);



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
*/
}
#endif
