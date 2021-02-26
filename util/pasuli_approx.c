
#include "pasuli_approx.h"

void approximatePaSuLi(int whatToApproximate, 
					pasuli_vartype u, pasuli_vartype v,
					pasuli_consttype* pConstants, PaSuLiObject* pO,
					parsurFunc f) {

	PaSuLiObject tempObject;

	f(u, v, pConstants, pO);
	pasuli_approx_type px = pO->pos[0];
	pasuli_approx_type py = pO->pos[1];
	pasuli_approx_type pz = pO->pos[2];

	if(whatToApproximate & PASULI_APPROXIMATE_UD) {
		f(u + PASULI_APPROX_DIFFERENCE, v, pConstants, &tempObject);
		pO->ud[0] = (tempObject.pos[0] - px)/PASULI_APPROX_DIFFERENCE;
		pO->ud[1] = (tempObject.pos[1] - py)/PASULI_APPROX_DIFFERENCE;
		pO->ud[2] = (tempObject.pos[2] - pz)/PASULI_APPROX_DIFFERENCE;
	}

	if(whatToApproximate & PASULI_APPROXIMATE_VD) {
		f(u , v + PASULI_APPROX_DIFFERENCE, pConstants, &tempObject);
		pO->vd[0] = (tempObject.pos[0] - px)/PASULI_APPROX_DIFFERENCE;
		pO->vd[1] = (tempObject.pos[1] - py)/PASULI_APPROX_DIFFERENCE;
		pO->vd[2] = (tempObject.pos[2] - pz)/PASULI_APPROX_DIFFERENCE;
	}

	if(whatToApproximate & PASULI_APPROXIMATE_N) {
		if((whatToApproximate & PASULI_APPROXIMATE_UD)&&
			(whatToApproximate & PASULI_APPROXIMATE_VD)) {
			pO->n[0] = pO->ud[1]*pO->vd[2] - pO->ud[2]*pO->vd[1];
			pO->n[1] = pO->ud[0]*pO->vd[2] - pO->ud[2]*pO->vd[0];
			pO->n[2] = pO->ud[0]*pO->vd[1] - pO->ud[1]*pO->vd[0];
		} else {

			f(u + PASULI_APPROX_DIFFERENCE, v , pConstants, &tempObject);
			pasuli_approx_type xu = (tempObject.pos[0] - px)/PASULI_APPROX_DIFFERENCE;
			pasuli_approx_type yu = (tempObject.pos[1] - py)/PASULI_APPROX_DIFFERENCE;
			pasuli_approx_type zu = (tempObject.pos[2] - pz)/PASULI_APPROX_DIFFERENCE;
			f(u , v + PASULI_APPROX_DIFFERENCE, pConstants, &tempObject);
			pasuli_approx_type xv = (tempObject.pos[0] - px)/PASULI_APPROX_DIFFERENCE;
			pasuli_approx_type yv = (tempObject.pos[1] - py)/PASULI_APPROX_DIFFERENCE;
			pasuli_approx_type zv = (tempObject.pos[2] - pz)/PASULI_APPROX_DIFFERENCE;
			pO->n[0] = yu*zv - zu*yv;
			pO->n[1] = xu*zv - zu*xv;
			pO->n[2] = xu*yv - yu*xv;
		}
	}

	pasuli_approx_type divisor = (PASULI_APPROX_DIFFERENCE*PASULI_APPROX_DIFFERENCE);

	if(whatToApproximate & PASULI_APPROXIMATE_UUD) {
		f(u + PASULI_APPROX_DIFFERENCE, v , pConstants, &tempObject);
		pasuli_approx_type px2 = (tempObject.pos[0] - px);
		pasuli_approx_type py2 = (tempObject.pos[1] - py);
		pasuli_approx_type pz2 = (tempObject.pos[2] - pz);

		px = tempObject.pos[0];
		py = tempObject.pos[1];
		pz = tempObject.pos[2];
		f(u + 2*PASULI_APPROX_DIFFERENCE, v , pConstants, &tempObject);
		pasuli_approx_type xu = (tempObject.pos[0] - px);
		pasuli_approx_type yu = (tempObject.pos[1] - py);
		pasuli_approx_type zu = (tempObject.pos[2] - pz);

		pO->uud[0] = (px2 - xu)/divisor;
		pO->uud[1] = (py2 - yu)/divisor;
		pO->uud[2] = (pz2 - zu)/divisor;
	}


	if(whatToApproximate & PASULI_APPROXIMATE_UVD) {
		f(u + PASULI_APPROX_DIFFERENCE, v  , pConstants, &tempObject);
		pasuli_approx_type px2 = (tempObject.pos[0] - px);
		pasuli_approx_type py2 = (tempObject.pos[1] - py);
		pasuli_approx_type pz2 = (tempObject.pos[2] - pz);

		//px = tO.pos[0];
		//py = tO.pos[1];
		//pz = tO.pos[2];
		f(u + PASULI_APPROX_DIFFERENCE , v + PASULI_APPROX_DIFFERENCE , pConstants, &tempObject);
		pasuli_approx_type xu = (tempObject.pos[0] - px);
		pasuli_approx_type yu = (tempObject.pos[1] - py);
		pasuli_approx_type zu = (tempObject.pos[2] - pz);
		pO->uvd[0] = (xu- px2 )/divisor;
		pO->uvd[1] = (yu - py2)/divisor;
		pO->uvd[2] = (zu - pz2)/divisor;
	}


	if(whatToApproximate & PASULI_APPROXIMATE_VVD) {
		f(u , v + PASULI_APPROX_DIFFERENCE , pConstants, &tempObject);
		pasuli_approx_type px2 = (tempObject.pos[0] - px);
		pasuli_approx_type py2 = (tempObject.pos[1] - py);
		pasuli_approx_type pz2 = (tempObject.pos[2] - pz);

		px = tempObject.pos[0];
		py = tempObject.pos[1];
		pz = tempObject.pos[2];
		f(u, v + 2*PASULI_APPROX_DIFFERENCE , pConstants, &tempObject);
		pasuli_approx_type xu = (tempObject.pos[0] - px);
		pasuli_approx_type yu = (tempObject.pos[1] - py);
		pasuli_approx_type zu = (tempObject.pos[2] - pz);
		pO->vvd[0] = (px2 - xu)/divisor;
		pO->vvd[1] = (py2 - yu)/divisor;
		pO->vvd[2] = (pz2 - zu)/divisor;
	}
}


