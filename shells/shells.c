
#include "../pasuli_const.h"
#include "../pasuli_macros.h"
#include "shells.h"
#include <math.h>

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




#if(COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddCornucopia = {
PSLDD_ID( CORNUCOPIA )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
-0.5f, 0.5f,  0, 2  , 0 };
#endif
/**
a \in R
b \in R

u \in [-pi , pi]
v \in [0 , 2pi]

x = e^{bv} cos(v) + e^{av} cos(u) cos(v)	
y = e^{bv} sin(v) + e^{av} cos(u) sin(v)
z = e^{av} sin(u)
*/
#if(COMPILE_DESC_SHELLS != 0)
char *descCornucopia = "";
#endif



#if(COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddSnail = {
PSLDD_ID( SNAIL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(0),
0, 6,  0, 2  , 0 };
#endif
#if(COMPILE_DESC_SHELLS != 0)
/**
u \in [0 , 6pi] 	
v \in [0 , 2pi]

h = e^{u/(6 pi)}
x = a (1 - h) cos(u) cos(0.5 v) cos(0.5 v)
y = 1 - e^{u/(b pi)} - sin(v) + h sin(v)
z = a (-1 + h) sin(u) cos(0.5 v) cos(0.5 v)
*/
char *descSnail = "";
#endif


#if(COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddSeashell = {
PSLDD_ID( SEASHELL )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_CONST_COUNT(4),
0, 2,  0, 2  , 0 };
#endif
#if(COMPILE_DESC_SHELLS != 0)
/**
a \in R : Width
b \in R : Height
c \in R: inner-radius
n \in R: number of turns

u \in [0 , 2]
v \in [0 , 2]

h = 1 - 0.5 v 	
x = a h cos(n v pi) (1 + cos(u pi)) + c cos(n v pi)
y = a h sin(n v pi) (1 + cos(u pi)) + c sin(n v pi)
z = b 0.5 v + a h sin(u pi)
*/
char *descSeashell = "";
#endif



#if(COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddSnailSurface = {
PSLDD_ID( SNAIL_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(0),
0, 2,  -1, 1  , 0 };
#endif
#if(COMPILE_DESC_SHELLS != 0)
/**
u \in [0, 2pi]
v \in [-pi, pi]

x = u cos(v) sin(u)
y = u cos(u) cos(v)
z = -u sin(v)
*/
char *descSnailSurface = "";
#endif



#if(COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddSnails = {
PSLDD_ID( SNAILS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CALC_U_START|PASULI_CALC_U_END| \
PASULI_V_END_PI|PASULI_CONST_COUNT(9),
0, 1,  0, 2  , 0 };
#endif
#if(COMPILE_DESC_SHELLS != 0)
/**
R \in R
a \in R
b \in R
c \in R
h \in R
k \in R
w \in R
u_min \in R
u_max \in R
x = exp(w u) (h + a cos(v)) cos(c u)
y = R exp(w u) (h + a cos(v)) sin(c u)
z = exp(w u) (k + b sin(v))

Die Konstanten a, b, c, h, k, und w bestimmen das Aussehen der Figur. 
Die Konstante R bestimmt die Drehrichtung der Spirale, 
R sollte nur die Werte -1 oder 1 annehmen.

u \in  [u_min, u_max]
v \in  [0, 2 pi]
*/
char *descSnails = "";
#endif


#if(COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddPseudohelicerasSubcatenatum = {
PSLDD_ID( PSEUDOHELICERAS_SUBCATENATUM )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CALC_U_START|PASULI_CALC_U_END| \
PASULI_V_END_PI|PASULI_CONST_CONSTANTS|PASULI_CONST_COUNT(9)| \
PASULI_DEF_DESC_USE_PASULI_CONSTTYPE_CONSTANTS,
-50, -1,  0, 2  , 0 };
#endif
#if(COMPILE_DESC_SHELLS != 0)
/**
a :1.6
b :1.6	 
c 	: 	1.0 	
h 	: 	1.5 	
k 	: 	-7.0 	
w 	: 	0.075 	
umin 	: -50.0 	
umax 	: -1.0
*/
char *descPseudohelicerasSubcatenatum = "";
#endif


#if(COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddAstroceras = {
PSLDD_ID( ASTROCERAS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CALC_U_START|PASULI_CALC_U_END| \
PASULI_V_END_PI|PASULI_CONST_CONSTANTS|PASULI_CONST_COUNT(9)| \
PASULI_DEF_DESC_USE_PASULI_CONSTTYPE_CONSTANTS,
-40, -1,  0, 2  , 0 };
#endif
#if(COMPILE_DESC_SHELLS != 0)
/**
a : 1.25
b : 1.25 
c 	: 	1.0 	
h 	: 	3.5 	
k 	: 	0.0 	
w 	: 	0.12 	
umin 	: 	-40.0 	
umax 	: 	-1.0
*/
char *descAstroceras = "";
#endif


#if(COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddBellerophina = {
PSLDD_ID( BELLEROPHINA )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_V_END_PI|PASULI_CONST_CONSTANTS|PASULI_CONST_COUNT(9)| \
PASULI_DEF_DESC_USE_PASULI_CONSTTYPE_CONSTANTS,
-10, -1,  0, 2  , 0 };
#endif
#if(COMPILE_DESC_SHELLS != 0)
/**
a : 0.85
b : 1.2 
c 	: 	1.0 	
h 	: 	0.75 	
k 	: 	0.0 	
w 	: 	0.06 	
umin 	: 	-10.0 	
umax 	: 	-1.0
*/
char *descBellerophina = "";
#endif

#if(COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddEuhoplites = {
PSLDD_ID( EUHOPLITES )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_V_END_PI|PASULI_CONST_CONSTANTS|PASULI_CONST_COUNT(9)| \
PASULI_DEF_DESC_USE_PASULI_CONSTTYPE_CONSTANTS,
-40, -1,  0, 2  , 0 };
#endif
#if(COMPILE_DESC_SHELLS != 0)
/**
a : 0.6
b : 0.4 
c 	: 	1.0 	
h 	: 	0.9 	
k 	: 	0.0 	
w 	: 	0.1626 	
umin 	: 	-40.0 	
umax 	: 	-1.0
*/
char *descEuhoplites = "";
#endif



#if(COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddNautilus = {
PSLDD_ID( NAUTILUS )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_V_END_PI|PASULI_CONST_CONSTANTS|PASULI_CONST_COUNT(2)| \
PASULI_DEF_DESC_USE_PASULI_CONSTTYPE_CONSTANTS,
-20, 1,  0, 2  , 0 };
#endif
#if(COMPILE_DESC_SHELLS != 0)
/**
a : 1.0
b : 0.6
c 	: 	1.0 	
h 	: 	1.0 	
k 	: 	0.0 	
w 	: 	0.18 	
umin 	: -20.0 	
umax 	: 	1.0
*/
char *descNautilus = "";
#endif

#if(COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddNaticaStellata = {
PSLDD_ID( NATICA_STELLATA )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_V_END_PI|PASULI_CONST_CONSTANTS|PASULI_CONST_COUNT(9)| \
PASULI_DEF_DESC_USE_PASULI_CONSTTYPE_CONSTANTS,
-20, 1,  0, 2  , 0 };
#endif
#if(COMPILE_DESC_SHELLS != 0)
/**
a : 2.6
b : 2.4 
c 	: 	1.0 	
h 	: 	1.25 	
k 	: 	-2.8 	
w 	: 	0.18 	
umin 	: 	-20.0 	
umax 	: 	1.0
*/
char *descNaticaStellata = "";
#endif


#if(COMPILE_DEF_DESC_SHELLS != 0)
PaSuLiDefDesc pslddMyaArenaria = {
PSLDD_ID( MYA_ARENARIA )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_V_END_PI|PASULI_CONST_CONSTANTS|PASULI_CONST_COUNT(9)| \
PASULI_DEF_DESC_USE_PASULI_CONSTTYPE_CONSTANTS,
-1, 0.52f,  0, 2  , 0 };
#endif
#if(COMPILE_DESC_SHELLS != 0)
/**
a : 0.85
b : 1.6 
	c 	: 	3.0 	
	h 	: 	0.9 	
	k 	: 	0 	
	w 	: 	2.5 	
	umin 	: 	-1.0 	
	umax 	: 	0.52
*/
char *descMyaArenaria = "";
#endif

