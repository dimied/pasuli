

#include "superformula2d.h"


template<class Type, class CalcType>
void TorusWithSuperFormulaTemplate(Particle *pParticle,
						   Type phi, Type rho, Type radius,
						   SF_2D *p2DSuperFormula) {


	CalcType a = p2DSuperFormula->a;
	CalcType b = p2DSuperFormula->b;
	CalcType m = p2DSuperFormula->m;
	CalcType n1 = p2DSuperFormula->n1;
	CalcType n2 = p2DSuperFormula->n2;
	CalcType n3 = p2DSuperFormula->n3;
	m *= 0.25f;
	CalcType cosphi = cos(phi);
	CalcType sinphi = sin(phi);
	CalcType cosMphi = cos(m*phi);
	CalcType sinMphi = sin(m*phi);
	CalcType cosrho = cos(rho);
	CalcType sinrho = sin(rho);

	CalcType R = 0.0;
	if(abs(a) > SUPER_FORMULA_PARAMETER_A_LOWER_BOUND) {
		R = pow(abs(cosMphi/a), n2);
	}
	if(abs(b) > SUPER_FORMULA_PARAMETER_B_LOWER_BOUND) {
		R += pow(abs(sinMphi/b), n3);
	}
	R = pow(R , 1.0/n1);
	R = 1.0/R;

	CalcType t3 = (radius + R*cosphi);

#if(PARTICLE_POS != 0)
	pParticle->pos[0] = cosrho*t3;
	pParticle->pos[1] = sinrho*t3;
	pParticle->pos[2] = R*sinphi;
#endif
	CalcType t1, t2;

//U = phi
#if(PARTICLE_UD != 0)
	t2 = -n1;
	t2 *= (n2*pow(abs(cosMphi/a), n2-1)*abs(sinMphi*m/a) + 
			n3*pow(abs(sinMphi/b), n3-1)*cosMphi*m/b);
	t2 /= (R2*(pow(abs(cosMphi/a), n2) + pow(abs(sinMphi/b), n3)));

	t1 = t2*cosphi - sinphi*R;
	pParticle->ud[0] = cosrho*t2;
	pParticle->ud[1] = sinrho*t2;
	pParticle->ud[2] = cosphi*R + sinphi*t2;
#endif


//V = rho
#if(PARTICLE_VD != 0)
	pParticle->vd[0] = -sinrho*t3;
	pParticle->vd[1] = cosrho*t3;
	pParticle->vd[2] = 0;
#endif


#if(PARTICLE_N != 0)
#if(PARTICLE_UD == 0)
	t2 = -n1;
	t2 *= (n2*pow(abs(cosMphi/a), n2-1)*abs(sinMphi*m/a) + 
			n3*pow(abs(sinMphi/b), n3-1)*cosMphi*m/b);
	t2 /= (R2*(pow(abs(cosMphi/a), n2) + pow(abs(sinMphi/b), n3)));

	t1 = t2*cosphi - sinphi*R;
#endif

	pParticle->n[0] = -(cosphi*R + sinphi*t2)*cosrho*t3;
	pParticle->n[1] = sinrho*t3*(cosphi*R + sinphi*t2);
	pParticle->n[2] = cosrho*t2*cosrho*t3 + sinrho*t2*sinrho*t3;
#endif


	CalcType t11, t22, t33;
//second derivative with respect to u
#if(PARTICLE_UUD != 0)

	t2 = -n1;
	t2 *= (n2*pow(abs(cosMphi/a), n2-1)*abs(sinMphi*m2/a) + 
			n3*pow(abs(sinMphi/b), n3-1)*cosMphi*m2/b);
	t2 /= (R*(pow(abs(cosMphi/a), n2) + pow(abs(sinMphi/b), n3)));

	t1 = t2*cosphi - sinphi*R;

	pParticle->uud[0] = cosrho;
	pParticle->uud[1] = sinrho;
	pParticle->uud[2] = 0;
#endif

//Here we differetiate the u-derivative with respect to v
#if(PARTICLE_UVD != 0)
	t2 = -n1;
	t2 *= (n2*pow(abs(cosMphi/a), n2-1)*abs(sinMphi*m2/a) + 
			n3*pow(abs(sinMphi/b), n3-1)*cosMphi*m2/b);
	t2 /= (R2*(pow(abs(cosMphi/a), n2) + pow(abs(sinMphi/b), n3)));

	t1 = t2*cosphi - sinphi*R2;

	t3 = t1;

	t2 = R*cosphi;
	t1 = -n1;
	t1 *= (n2*pow(abs(cosMrho/a), n2-1)*abs(sinMrho*m1/a) + 
			n3*pow(abs(sinMrho/b), n3-1)*cosMrho*m1/b);
	t1 /= (R1*(pow(abs(cosMrho/a), n2) + pow(abs(sinMrho/b), n3)));

	pParticle->uvd[0] = t3*(t1*cosrho - sinrho*R);
	pParticle->uvd[1] = t3*(R*cosrho + sinrho*t1);

	pParticle->uvd[2] = 0.0;		//zero
#endif

//second derivative with respect to v
#if(PARTICLE_VVD != 0)
	t2 = R2*cosphi;
	t1 = -n1;
	t1 *= (n2*pow(abs(cosMrho/a), n2-1)*abs(sinMrho*m1/a) + 
			n3*pow(abs(sinMrho/b), n3-1)*cosMrho*m1/b);
	t1 /= (R1*(pow(abs(cosMrho/a), n2) + pow(abs(sinMrho/b), n3)));

	t22 = (R1*(pow(abs(cosMrho/a), n2) + pow(abs(sinMrho/b), n3)));
	
	t11 = (111)*t22 - (111)*(111);

	t11 /= t22*t22;

	pParticle->vvd[0] = t2*((t11*cosrho - t1*sinrho) - (cosrho*R1 - sinrho*t1));
	pParticle->vvd[1] = t2*((t1*cosrho - R1*sinrho) + (cosrho*t1 + sinrho*t11));
	pParticle->vvd[2] = 0.0;		//zero
#endif
}



////////////////////////////////////////////////////////////
//// CALCULATE POSITIONS & DERIVATIVES USING SHADERS
////////////////////////////////////////////////////////////
///////////////  OpenGL-VERSION   //////////////////////////
////////////////////////////////////////////////////////////
////char* ogl_shader_sf_2d_init = 
////"";
////
////char* ogl_shader_sf_2d_pos = 
////"";
////
////char* ogl_shader_sf_2d_ud = 
////"";
////
////char* ogl_shader_sf_2d_vd = 
////"";
////
////char* ogl_shader_sf_2d_n = 
////"";
////
////char* ogl_shader_sf_2d_uud = 
////"";
////
////char* ogl_shader_sf_2d_uvd = 
////"";
////
////char* ogl_shader_sf_2d_vvd = 
////"";
////
////
////
////
////ShaderSources sf_2d_ogl_ShaderSources = {
////ogl_shader_sf_2d_init,
////ogl_shader_sf_2d_pos,
////ogl_shader_sf_2d_ud,
////ogl_shader_sf_2d_vd,
////ogl_shader_sf_2d_n,
////ogl_shader_sf_2d_uud,
////ogl_shader_sf_2d_uvd,
////ogl_shader_sf_2d_vvd };




