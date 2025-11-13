

#include "superformula2d.h"
#include "superformula3d.h"
#include "../pasuli_defs.h"
#include <math.h>

typedef double pasuli_sf2d_param_type;
typedef double pasuli_sf2d_calc_type;

void TorusWithSuperFormula(PaSuLiObject *pParticle,
						   pasuli_sf2d_param_type phi,
						   pasuli_sf2d_param_type rho,
						   pasuli_sf2d_param_type radius,
						   SF_2D *p2DSuperFormula)
{
	/*
	pasuli_sf2d_calc_type a = p2DSuperFormula->a;
	pasuli_sf2d_calc_type b = p2DSuperFormula->b;
	pasuli_sf2d_calc_type m = p2DSuperFormula->m;
	pasuli_sf2d_calc_type n1 = p2DSuperFormula->n1;
	pasuli_sf2d_calc_type n2 = p2DSuperFormula->n2;
	pasuli_sf2d_calc_type n3 = p2DSuperFormula->n3;
	m *= 0.25f;

	pasuli_sf2d_calc_type cosphi = cos(phi);
	pasuli_sf2d_calc_type sinphi = sin(phi);
	pasuli_sf2d_calc_type cosMphi = cos(m * phi);
	pasuli_sf2d_calc_type sinMphi = sin(m * phi);
	pasuli_sf2d_calc_type cosrho = cos(rho);
	pasuli_sf2d_calc_type sinrho = sin(rho);

	pasuli_sf2d_calc_type cosMrho = cos(m * rho);

	pasuli_sf2d_calc_type R = 0.0;
	if (fabs(a) > SUPER_FORMULA_PARAMETER_A_LOWER_BOUND)
	{
		R = pow(fabs(cosMphi / a), n2);
	}
	if (fabs(b) > SUPER_FORMULA_PARAMETER_B_LOWER_BOUND)
	{
		R += pow(fabs(sinMphi / b), n3);
	}
	R = pow(R, 1.0 / n1);
	R = 1.0 / R;

	pasuli_sf2d_calc_type t3 = (radius + R * cosphi);

#if (PARTICLE_POS != 0)
	pParticle->pos[0] = cosrho * t3;
	pParticle->pos[1] = sinrho * t3;
	pParticle->pos[2] = R * sinphi;
#endif
	pasuli_sf2d_calc_type t1, t2;

//U = phi
#if (PARTICLE_UD != 0)
	t2 = -n1;
	t2 *= (n2 * pow(fabs(cosMphi / a), n2 - 1) * fabs(sinMphi * m / a) +
		   n3 * pow(fabs(sinMphi / b), n3 - 1) * cosMphi * m / b);
	
	// TODO
	//t2 /= (R2 * (pow(abs(cosMphi / a), n2) + pow(abs(sinMphi / b), n3)));

	t1 = t2 * cosphi - sinphi * R;
	pParticle->ud[0] = cosrho * t2;
	pParticle->ud[1] = sinrho * t2;
	pParticle->ud[2] = cosphi * R + sinphi * t2;
#endif

//V = rho
#if (PARTICLE_VD != 0)
	pParticle->vd[0] = -sinrho * t3;
	pParticle->vd[1] = cosrho * t3;
	pParticle->vd[2] = 0;
#endif

#if (PARTICLE_N != 0)

#if (PARTICLE_UD == 0)
	t2 = -n1;
	t2 *= (n2 * pow(abs(cosMphi / a), n2 - 1) * abs(sinMphi * m / a) +
		   n3 * pow(abs(sinMphi / b), n3 - 1) * cosMphi * m / b);
	t2 /= (R2 * (pow(abs(cosMphi / a), n2) + pow(abs(sinMphi / b), n3)));

	t1 = t2 * cosphi - sinphi * R;
#endif

	pParticle->n[0] = -(cosphi * R + sinphi * t2) * cosrho * t3;
	pParticle->n[1] = sinrho * t3 * (cosphi * R + sinphi * t2);
	pParticle->n[2] = cosrho * t2 * cosrho * t3 + sinrho * t2 * sinrho * t3;
#endif

	pasuli_sf2d_calc_type t11, t22, t33;
//second derivative with respect to u
#if (PARTICLE_UUD != 0)

	t2 = -n1;
	// TODO
	//t2 *= (n2 * pow(abs(cosMphi / a), n2 - 1) * abs(sinMphi * m2 / a) +
		   //n3 * pow(abs(sinMphi / b), n3 - 1) * cosMphi * m2 / b);
	t2 /= (R * (pow(fabs(cosMphi / a), n2) + pow(fabs(sinMphi / b), n3)));

	t1 = t2 * cosphi - sinphi * R;

	pParticle->uud[0] = cosrho;
	pParticle->uud[1] = sinrho;
	pParticle->uud[2] = 0;
#endif

//Here we differetiate the u-derivative with respect to v
#if (PARTICLE_UVD != 0)
	t2 = -n1;
	// TODO
	//t2 *= (n2 * pow(abs(cosMphi / a), n2 - 1) * abs(sinMphi * m2 / a) +
	//	   n3 * pow(abs(sinMphi / b), n3 - 1) * cosMphi * m2 / b);
	// TODO
	//t2 /= (R2 * (pow(abs(cosMphi / a), n2) + pow(abs(sinMphi / b), n3)));

	//t1 = t2 * cosphi - sinphi * R2;

	t3 = t1;

	t2 = R * cosphi;
	t1 = -n1;
	// TODO
	//t1 *= (n2 * pow(abs(cosMrho / a), n2 - 1) * abs(sinMrho * m1 / a) +
		   // n3 * pow(abs(sinMrho / b), n3 - 1) * cosMrho * m1 / b);
	// TODO
	//t1 /= (R1 * (pow(abs(cosMrho / a), n2) + pow(abs(sinMrho / b), n3)));

	pParticle->uvd[0] = t3 * (t1 * cosrho - sinrho * R);
	pParticle->uvd[1] = t3 * (R * cosrho + sinrho * t1);

	pParticle->uvd[2] = 0.0; //zero
#endif

//second derivative with respect to v
#if (PARTICLE_VVD != 0)
	//t2 = R2 * cosphi;
	t1 = -n1;
	// TODO
	//t1 *= (n2 * pow(abs(cosMrho / a), n2 - 1) * abs(sinMrho * m1 / a) +
	//	   n3 * pow(abs(sinMrho / b), n3 - 1) * cosMrho * m1 / b);
		   // TODO
	//t1 /= (R1 * (pow(abs(cosMrho / a), n2) + pow(abs(sinMrho / b), n3)));
	// TODO
	//t22 = (R1 * (pow(abs(cosMrho / a), n2) + pow(abs(sinMrho / b), n3)));

	t11 = (111) * t22 - (111) * (111);

	t11 /= t22 * t22;

	// TODO
	//pParticle->vvd[0] = t2 * ((t11 * cosrho - t1 * sinrho) - (cosrho * R1 - sinrho * t1));
	//pParticle->vvd[1] = t2 * ((t1 * cosrho - R1 * sinrho) + (cosrho * t1 + sinrho * t11));
	pParticle->vvd[2] = 0.0; //zero
#endif
*/
}
