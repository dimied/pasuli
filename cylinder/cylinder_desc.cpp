

#include "../pasuli_defs.h"
#include "../pasuli_const.h"
#include "cylinder_desc.h"


#if(COMPILE_DEF_DESC_CYLINDER != 0)
//pasulidefdesc_ct c_constants[] = {1};
PaSuLiDefDesc pslddCylinder = {
PSLDD_ID(CYLINDER )
PASULI_U_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(1) ,
-1, 1 , 0, 1 , (pasulidefdesc_ct*)0};	//c_constants};
#endif
#if(COMPILE_DESC_CYLINDER != 0)
char *descCylinder = 
"start; \
name: cylinder; \
utype: closed; \
vtype: open; \
ustart: pi : -1; \
uend: pi : 1; \
vstart: 0; \
vend: 1; \
x: r*cos(u); \
y: r*sin(u); \
z: v; \
c: 1 : r : 1.0; "
#if(COMPILE_DESC_DERIV_U_CYLINDER != 0)
"xu: -r*sin(u); \
yu: r*cos(u); \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_CYLINDER != 0)
"xv: 0; \
yv: 0; \
zv: 1; "
#endif
#if(COMPILE_DESC_NORMAL_CYLINDER != 0)
"xn: r*cos(u); \
yn: r*sin(u); \
zn: 0; "
#endif
"xuu: -r*cos(u); \
yuu: -r*sin(u); \
zuu: 0; "
"xuv: 0; \
yuv: 0; \
zuv 0; "
"xvv: 0; \
yvv: 0; \
zvv 0; "
"end;";
#endif



#if(COMPILE_DEF_DESC_CYLINDER != 0)
pasulidefdesc_ct ec_constants[] = {1.5, 1.0, 0.5, 1.0};
PaSuLiDefDesc pslddEpizykloidCylinder = {
PSLDD_ID( EPIZYKLOID_CYLINDER )
PASULI_U_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(4), 
-1, 1 , 0 , 1 , ec_constants};
#endif
#if(COMPILE_DESC_CYLINDER != 0)
char* descEpizykloidCylinder = 
"start; \
name: Epizykloid-Cylinder; \
utype: closed; \
vtype: open; \
ustart: pi : -1; \
uend: pi : 1; \
vstart: 0; \
vend: 1; \
x: (R + r)*cos(u) - h*cos((R + r)*u/r); \
y: H*v; \
z: (R + r)*sin(u) - h*sin((R + r)*u/r); \
c:1:R: 1.5; c:2:r: 1.0; \
c:3:h: 0.5; c:4:H: 1.0; "
#if(COMPILE_DESC_DERIV_U_CYLINDER != 0)
"xu: h*(R + r)*sin((R + r)*u/r)/r -(R + r)*sin(u); \
yu: 0; \
zu: -h*(R + r)*cos((R + r)*u/r)/r + (R + r)*cos(u); "
#endif
#if(COMPILE_DESC_DERIV_V_CYLINDER != 0)
"xv: 0; \
yv: H; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_CYLINDER != 0)
"xn: H*(h*(R + r)*cos((R + r)*u/r)/r - (R + r)*cos(u)); \
yn: 0; \
zn: H*(h*(R + r)*sin((R + r)*u/r)/r -(R + r)*sin(u)); "
#endif
"xuu: (2*R-r +R*cos((R + r)*u/r)/r)*h*cos((R + r)*u/r)/r -cos(u)*(R+r); \
yuu: -r*sin(u) \
zuu: (2*R-r+R*sin((R + r)*u/r)/r)*h*sin((R + r)*u/r)/r -sin(u)*(R+r); "
"xuv: 0; \
yuv: 0; \
zuv 0;"
"xvv: 0; \
yvv: 0; \
zvv 0; "
"end;";
#endif



#if(COMPILE_DEF_DESC_CYLINDER != 0)
pasulidefdesc_ct hc_constants[] = {1.5, 1.0, 0.5, 1.0};
PaSuLiDefDesc pslddHypozykloidCylinder = {
PSLDD_ID(HYPOZYKLOID_CYLINDER)
PASULI_U_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(4), 
-1, 1 , 0, 1 , hc_constants};
#endif
#if(COMPILE_DESC_CYLINDER != 0)
char* descHypozykloidCylinder = 
"start; \
name: Hypozykloid-Cylinder; \
utype: closed; \
vtype: open; \
ustart: pi : -1; \
uend: pi : 1; \
vstart: 0; \
vend: 1; \
c:1:R: 1.5; c:2:r: 1.0; \
c:3:h: 0.5; c:4:H: 1.0; \
x: (R - r)*cos(u) + h*cos(((R - r)/r)*u); \
y: H*v; \
z: (R - r)*sin(u) - h*sin(((R - r)/r)*u); "
#if(COMPILE_DESC_DERIV_U_CYLINDER != 0)
"xu: h*(R - r)*sin((R - r)*u/r)/r -(R - r)*sin(u); \
yu: 0; \
zu: -h*(R - r)*cos((R - r)*u/r)/r + (R - r)*cos(u); "
#endif
#if(COMPILE_DESC_DERIV_V_CYLINDER != 0)
"xv: 0; \
yv: H; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_CYLINDER != 0)
"xn: H*(h*(R - r)*cos((R - r)*u/r)/r - (R - r)*cos(u)); \
yn: 0; \
zn: H*(h*(R - r)*sin((R - r)*u/r)/r -(R - r)*sin(u)); "
#endif
"xuu: h*(2*R - r -R/r)*cos((R - r)*u/r)/r - (R-r)*cos(u) ; \
yuu: 0; \
zuu: h*(2*R - r -R/r)*sin((R - r)*u/r)/r - (R-r)*sin(u); "
"xuv: 0; \
yuv: 0; \
zuv 0; "
"xvv: 0; \
yvv: 0; \
zvv 0; "
"end;";
#endif



#if(COMPILE_DEF_DESC_CYLINDER != 0)
//pasulidefdesc_ct lc_constants[] = {1.0, 1.0};
PaSuLiDefDesc pslddLemniskateCylinder = {
PSLDD_ID( LEMNISKATE_CYLINDER )
PASULI_U_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(2), 
-1, 1 , 0, 1 , 0};	//lc_constants};
#endif
#if(COMPILE_DESC_CYLINDER != 0)
char *descLemniskateCylinder = 
"start; \
name: Lemniskate-Cylinder; \
utype: closed; \
vtype: open; \
ustart: pi : -1; \
uend: pi : 1; \
vstart: 0; \
vend: 1; \
c:1:r: 1.0; \
c:2:H: 1.0; \
x: r*cos(u)/(1 + sin(u)^2); \
y: H*v; \
z: r*sin(u)*cos(u)/(1 + sin(u)^2); "
#if(COMPILE_DESC_DERIV_U_CYLINDER != 0)
"xu: r*(-2 - cos(u)*cos(u))/((1 + sin(u)^2)^2); \
yu: 0; \
zu: r*(1-3*sin(u)*sin(u))/((1 + sin(u)^2)^2); "
#endif
#if(COMPILE_DESC_DERIV_V_CYLINDER != 0)
"xv: 0; \
yv: H; \
zv: 0; "
#endif
#if(COMPILE_DESC_DERIV_U_CYLINDER != 0)
"xn: H*r*(3*sin(u)*sin(u) - 1)/((1 + sin(u)^2)^2); \
yn: 0; \
zn: H*r*(-2 - cos(u)*cos(u))*sin(u)/((1 + sin(u)^2)^2); "
#endif
"xuu: r*cos(u)*(sin(u)*sin(u)*(5+cos(u)*cos(u))-1-2*cos(u)^2 + 4*sin(u)^2)/((1+sin(u)^2)^3); \
yuu: 0; \
zuu: 2*r*(-5+3*sin(u)*sin(u))*cos(u)*sin(u)/((1+sin(u)^2)^3); "
"xuv: 0; \
yuv: 0; \
zuv 0; "
"xvv: 0; \
yvv: 0; \
zvv 0; "
"end;";
#endif



#if(COMPILE_DEF_DESC_CYLINDER != 0)
//pasulidefdesc_ct sc_constants[] = {1.0, 1.0};
PaSuLiDefDesc pslddStrophoideCylinder = {
PSLDD_ID( STROPHOIDE_CYLINDER )
PASULI_U_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(2), 
-1, 1 , -2, 2 , 0};		//sc_constants};
#endif
#if(COMPILE_DESC_CYLINDER != 0)
char *descStrophoideCylinder = 
"start; \
name: Strophoide-Cylinder; \
utype: closed; \
vtype: open; \
ustart: pi : -1; \
uend: pi : 1; \
vstart: -2; \
vend: 2; \
c:1:R: 1.0; \
c:2:a: 1.0; \
x: (R + a*(v*v - 1)/(v*v + 1))*cos(u); \
y: a*v*(v*v - 1)/(v*v + 1); \
z: (R + a*(v*v - 1)/(v*v + 1))*sin(u); "
#if(COMPILE_DESC_DERIV_U_CYLINDER != 0)
"xu: sin(u)*(a-R-(R+a)*v*v)/(1+v*v); \
yu: 0; \
zu: cos(u)*(R-a+(R+a)*v*v)/(1+v*v); "
#endif
#if(COMPILE_DESC_DERIV_V_CYLINDER != 0)
"xv: 4*a*v*cos(u)*(1+v*v*(3+v*v*(3+v*v)))/((1+v*v)^5); \
yv: a*(-1+v*v*v*v*(11+v*v*(24+v*v*(21+v*v*(8+v*v)))))/((1+v*v)^6); \
zv: 4*a*v*sin(u)*(1+v*v*(3+v*v*(3+v*v)))/((1+v*v)^5); "
#endif
#if(COMPILE_DESC_NORMAL_CYLINDER != 0)
"xn: a*cos(u)*(R-a-v*v*((3*R-5*a) - v*v*((5*R-3*a)-(R+a)*v*v)))/((1+v*v)^3); \
yn: 4*a*v*(R-a+v*v*(R+a))/((1+v*v)^3); \
zn: a*sin(u)*(R-a-v*v*((3*R-5*a) - v*v*((5*R-3*a)-(R+a)*v*v)))/((1+v*v)^3); "
#endif
"xuu: cos(u)*(a-R - v*v*(R+a))/(1+v*v); \
yuu: 0; \
zuu: sin(u)*(a-R - v*v*(R+a))/(1+v*v); "
"xuv: 4*a*v*(-1-v*v*(3 + v*v*(3 + v*v)))*sin(u)/((1+v*v)^5); \
yuv: 0; \
zuv: 4*a*v*(1+v*v*(3 + v*v*(3 + v*v)))*cos(u)/((1+v*v)^5); "
"xvv: 4*a*cos(u)*(1+v*v*(5+v*v*(4-v*v*(28+v*v*(98+v*v*(154 + v*v*(140+v*v*(76+v*v*(23+3*v*v)))))))))/((1+v*v)^11); \
yvv: 4*a*v*(3+v*v*(14+v*v*(25+v*v*(20+v*v*(5-v*v*(2 + v*v))))))/((1+v*v)^8); \
zvv 4*a*sin(u)*(1+v*v*(5+v*v*(4-v*v*(28+v*v*(98+v*v*(154 + v*v*(140+v*v*(76+v*v*(23+3*v*v)))))))))/((1+v*v)^11); "
"end;";
#endif



#if(COMPILE_DEF_DESC_CYLINDER != 0)
//pasulidefdesc_ct zc_constants[] = {1.0, 1.0};
PaSuLiDefDesc pslddZissoideCylinder = {
PSLDD_ID( ZISSOIDE_CYLINDER )
PASULI_U_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(2), 
-1, 1 , -5, 5 , 0};		//zc_constants};
#endif
#if(COMPILE_DESC_CYLINDER != 0)
char *descZissoideCylinder = 
"start; \
name: Zissoide-Cylinder; \
utype: closed; \
vtype: open; \
ustart: pi : -1; \
uend: pi : 1; \
vstart: -5; \
vend: 5; \
c:1:R: 1.0; \
c:2:a: 1.0; \
x: (R + a*v*v/(1 + v*v))*cos(u); \
y: a*v^(3)/(1 + v*v); \
z: (R + a*v*v/(1 + v*v))*sin(u); "
#if(COMPILE_DESC_DERIV_U_CYLINDER != 0)
"xu: -sin(u)*(R+a*v*v/(1+v*v)); \
yu: 0; \
zu: cos(u)*(R+a*v*v/(1+v*v)); "
#endif
#if(COMPILE_DESC_DERIV_V_CYLINDER != 0)
"xv: 2*a*v*cos(u)/((1+v*v)^2); \
yv: a*v*v*(3+v*v*(4+v*v))/((1+v*v)^3); \
zv: 2*a*v*sin(u)/((1+v*v)^2); "
#endif
#if(COMPILE_DESC_NORMAL_CYLINDER != 0)
"xn: -cos(u)*a*v*v*(3*R+v*v*((4*R+3*a) + v*v*(R+a)))/((1+v*v)^3); \
yn: 2*a*v*(R+v*v*(R+a))/((1+v*v)^3); \
zn: -sin(u)*a*v*v*(3*R+v*v*((4*R+3*a) + v*v*(R+a)))/((1+v*v)^3); "
#endif
"xuu: -(R+(a*v*v)/(1+v*v))*cos(u); \
yuu: 0; \
zuu: -(R+(a*v*v)/(1+v*v))*sin(u); "
"xuv: -2*a*v*sin(u)/((1+v*v)^2); \
yuv: 0\
zuv 2*a*v*cos(u)/((1+v*v)^2); "
"xvv: 2*a*cos(u)*(1-v*v*v*v*(6 + v*v*(8+3*v*v))))/((1+v*v)^6); \
yvv: /((1+v*v)^3); \
zvv: 2*a*sin(u)*(1-v*v*v*v*(6 + v*v*(8+3*v*v))))/((1+v*v)^6); "
"end;";
#endif



#if(COMPILE_DEF_DESC_CYLINDER != 0)
//pasulidefdesc_ct vac_constants[] = {1.0, 1.0};
PaSuLiDefDesc pslddVACylinder = {
PSLDD_ID( VERSIERA_AGNESI_CYLINDER )
PASULI_U_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(2), 
-1, 1 , -3, 4 , 0};		//vac_constants};
#endif
#if(COMPILE_DESC_CYLINDER != 0)
char *descVACylinder = 
"start; \
name: Versiera-Agnesi-Cylinder; \
utype: closed; \
vtype: open; \
ustart: pi : -1; \
uend: pi : 1; \
vstart: -3; \
vend: 3; \
c:1:R: 1.0; \
c:2:a: 1.0; \
x: (R + 2*a/(1 + v*v))*cos(u); \
y: 2*a*v; \
z: (R + 2*a/(1 + v*v))*sin(u); "
#if(COMPILE_DESC_DERIV_U_CYLINDER != 0)
"xu: -sin(u)*(R+2*a/(1+v*v)); \
yu: 0; \
zu: cos(u)*(R+2*a/(1+v*v)); "
#endif
#if(COMPILE_DESC_DERIV_V_CYLINDER != 0)
"xv: -4*a*v*cos(u)/((1+v*v)^2); \
yv: 2*a; \
zv: -4*a*v*sin(u)/((1+v*v)^2); "
#endif
#if(COMPILE_DESC_NORMAL_CYLINDER != 0)
"xn: 2*a*cos(u)*(-R-2*a/((1+v*v))); \
yn: 4*a*v*(-R-2*a-R*v*v)/((1+v*v)^3); \
zn: 2*a*sin(u)*(-R-2*a/(1+v*v)); "
#endif
"xuu: -cos(u)*(R+2*a*/(1+v*v)); \
yuu: 0; \
zuu: -sin(u)*(R+2*a*/(1+v*v)); "
"xuv: 4*a*v*sin(u)/((1+v*v)^2); \
yuv: 0; \
zuv: -4*a*v*cos(u)/((1+v*v)^2); "
"xvv: 4*a*(3*v*v-1)*cos(u)/((1+v*v)^3); \
yvv: ;\
zvv 4*a*(3*v*v-1)*sin(u)/((1+v*v)^3); "
"end;";
#endif



#if(COMPILE_DEF_DESC_CYLINDER != 0)
//pasulidefdesc_ct gc_constants[] = {1.0, 1.0, 1.0};
PaSuLiDefDesc pslddGaussCylinder = {
PSLDD_ID( GAUSS_CYLINDER )
PASULI_U_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(3), 
-1, 1 , 0, 1 , 0};		//gc_constants};
#endif
#if(COMPILE_DESC_CYLINDER != 0)
char *descGaussCylinder = 
"start; \
name: Gauss-Cylinder; \
utype: closed; \
vtype: open; \
ustart: pi : -1; \
uend: pi : 1; \
vstart: 0; \
vend: 1; \
c:1:R: 1.0; \
c:2:a: 1.0; \
c:3:b: 1.0; \
x: (R + b*exp(-(a*a*v*v)))*cos(u); \
y: v; \
z: (R + b*exp(-(a*a*v*v)))*sin(u); "
#if(COMPILE_DESC_DERIV_U_CYLINDER != 0)
"xu: -sin(u)*(R+b*exp(-a*a*v*v)); \
yu: 0; \
zu: cos(u)*(R+b*exp(-a*a*v*v)); "
#endif
#if(COMPILE_DESC_DERIV_V_CYLINDER != 0)
"xv: -2*a*a*b*v*exp(-a*a*v*v)*cos(u); \
yv: 1; \
zv: -2*a*a*b*v*exp(-a*a*v*v)*sin(u); "
#endif
#if(COMPILE_DESC_NORMAL_CYLINDER != 0)
"xn: -cos(u)*(R+b*exp(-a*a*v*v)); \
yn: -2*a*a*b*v*exp(-2*a*a*v*v)*(b+R*exp(a*a*v*v)); \
zn: -sin(u)*(R+b*exp(-a*a*v*v)); "
#endif
"xuu: -cos(u)*(R+b*exp(-a*a*v*v));\
yuu: 0; \
zuu -sin(u)*(R+b*exp(-a*a*v*v)); "
"xuv: 2*a*a*b*v*exp(-a*a*v*v)*sin(u); \
yuv: 0; \
zuv: -2*a*a*b*v*exp(-a*a*v*v)*cos(u); "
"xvv: cos(u)*(2*a*a*b*exp(-a*a*v*v)*(2*a*a*v*v-1)); \
yvv: 0; \
zvv sin(u)*(2*a*a*b*exp(-a*a*v*v)*(2*a*a*v*v-1)); "
"end;";
#endif

