
#include "../pasuli_const.h"
#include "../pasuli_macros.h"
#include "shells.h"

//#pragma warning(disable:4244)

#if((COMPILE_SHELLS != 0)||(COMPILE_DEF_DESC_SHELLS != 0))
pasuli_consttype PseudohelicerasSubcatenatumParams[] = {
	1.6f , 1.6f , 1.0f , 1.5f , -7.0f , 0.075f};
pasuli_consttype AstrocerasParams[] = {
	1.25f , 1.25f , 1.0f , 3.5f , 0.0f , 0.12f};
pasuli_consttype BellerophinaParams[] = {
	0.85f , 1.2f , 1.0f , 0.75f , 0.0f , 0.06f};
pasuli_consttype EuhoplitesParams[] = {
	0.6f , 0.4f , 1.0f , 0.9f , 0.0f , 0.1626f};
pasuli_consttype NautilusParams[] = {
	1.0f , 0.6f , 1.0f , 1.0f , 0.0f , 0.18f};
pasuli_consttype NaticaStellataParams[] = {
	2.6f , 2.4f , 1.0f , 1.25f , -2.8f , 0.18f};
pasuli_consttype MyaArenariaParams[] = {
	0.85f , 1.6f , 3.0f , 0.9f , 0 , 2.5f};
#endif


#if(COMPILE_SHELLS != 0)
void Cornucopia(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( CORNUCOPIA )

	double a = constants[0];
	double b = constants[1];

	double eav = exp(a*v);
	double ebv = exp(b*v);

	P_X( ebv* cos(v) + eav * cos(u) * cos(v) );
	P_Y( ebv * sin(v) + eav * cos(u) * sin(v) );
	P_Z( eav * sin(u) );
}
#endif


#if(COMPILE_SHELLS != 0)
void Snail(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SNAIL )

	double a = constants[0];
	double b = constants[1];

	double h = exp(u/(6*MY_PI));
	double eubpi = exp(u/(b*MY_PI));

	double cos_half_v_sq = cos(v * 0.5f);
	cos_half_v_sq *= cos_half_v_sq;
			
	P_X( a*(1-h)*cos(u)*cos_half_v_sq );
	P_Y( 1 - eubpi + (h - 1)*sin(v) );
	P_Z( a*(h-1)*sin(u)*cos_half_v_sq );
}
#endif



#if(COMPILE_SHELLS != 0)
void Seashell(double u, double v, double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SEASHELL)

	double ah;
	double a = constants[0];
	double b = constants[1];
	double c = constants[2];
	double turns = constants[3];
	double cos_u_pi_one;
	double cos_turns_v_pi;
	double sin_turns_v_pi;

	cos_u_pi_one = 1.0f + cos(u * MY_PI);

	ah = a*(1 - 0.5*v);	
	sin_turns_v_pi = turns*v*MY_PI;
	cos_turns_v_pi = cos(sin_turns_v_pi);
	sin_turns_v_pi = sin(sin_turns_v_pi);

	P_X( ah*cos_turns_v_pi*cos_u_pi_one + c*cos_turns_v_pi );
	P_Y( ah*sin_turns_v_pi*cos_u_pi_one + c*sin_turns_v_pi );
	P_Z( b*0.5*v + ah*sin(u*MY_PI) );
}
#endif



#if(COMPILE_SHELLS != 0)
void SnailSurface(double u, double v, 
				double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SNAIL_SURFACE )

	P_X( cos(v)*u*sin(u) );
	P_Y( cos(v)*u*cos(u) );
	P_Z( -(u*sin(v)) );
}
#endif



#if(COMPILE_SHELLS != 0)
void Snails(double u, double v, double* constants, PaSuLiObject* pO) {
	PASULI_SET_TYPE_ID( SNAILS )

	double cos_cu;
	double sin_cu;
	double R = constants[0];
	double a = constants[1];
	double b = constants[2];
	double c = constants[3];
	double h = constants[4];
	double K = constants[5];
	double w = constants[6];

	cos_cu = cos(c*u);
	sin_cu = sin(c*u);
	double hacv = h + a*cos(v);
	double ewu = exp(w*u);

	P_Z( ewu*(K + b*sin(v)) );
	P_X( ewu*hacv*cos_cu );
	P_Y( R*ewu*hacv*sin_cu );

}
#endif


#if(COMPILE_SHELLS != 0)

void PseudohelicerasSubcatenatum(double u, double v, 
			  double* constants, PaSuLiObject* pO) {
	//int k = 0;
	//double u , v;
	Snails(u, v, &PseudohelicerasSubcatenatumParams[0] , pO);
	PASULI_SET_TYPE_ID( PSEUDOHELICERAS_SUBCATENATUM )
}
#endif


#if(COMPILE_SHELLS != 0)
void Astroceras(double u, double v, double* constants, PaSuLiObject* pO) {

	//int k = 0;
	//double u , v;
	Snails( u, v, &AstrocerasParams[0] , pO);
	PASULI_SET_TYPE_ID( ASTROCERAS )
}
#endif



#if(COMPILE_SHELLS != 0)
void Bellerophina(double u, double v, 
			  double* constants, PaSuLiObject* pO ) {

	//int k = 0;
	//double u , v;
	Snails( u, v, &BellerophinaParams[0] , pO );
	PASULI_SET_TYPE_ID( BELLEROPHINA )
}
#endif



#if(COMPILE_SHELLS != 0)

void Euhoplites(double u, double v, 
			  double* constants, PaSuLiObject* pO) {

	//int k = 0;
	//double u , v;
	Snails( u, v, &EuhoplitesParams[0] , pO);
	PASULI_SET_TYPE_ID( EUHOPLITES )
}
#endif





#if(COMPILE_SHELLS != 0)
void Nautilus(double u, double v, 
			  double* constants, PaSuLiObject* pO) {

	//int k = 0;
	//double u , v;
	Snails( u, v, &NautilusParams[0] , pO);
	PASULI_SET_TYPE_ID( NAUTILUS )
}
#endif




#if(COMPILE_SHELLS != 0)

void NaticaStellata(double u, double v, 
					double* constants, PaSuLiObject* pO ) {

	//int k = 0;
	//double u , v;
	Snails( u, v, &NaticaStellataParams[0] , pO );
	PASULI_SET_TYPE_ID( NATICA_STELLATA )
}
#endif



#if(COMPILE_SHELLS != 0)
void MyaArenaria(double u, double v, 
				double* constants, PaSuLiObject* pO) {

	//int k = 0;
	//double u , v;
	Snails( u, v, &MyaArenariaParams[0] , pO);
	PASULI_SET_TYPE_ID( MYA_ARENARIA )
}
#endif


