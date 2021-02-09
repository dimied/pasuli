
#include "../pasuli_const.h"
#include "surfaces_desc.h"


pasulidefdesc_ct psldd_15_05_constants[] = {1.5, 0.5, 1.0, 1.0, 1.0, 1.0};
pasulidefdesc_ct psldd_10_constants[] = {1.0};

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBohemianDomeSurface = {
PSLDD_ID( BOHEMIAN_DOME_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(3),
0, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBohemianDomeSurface =
"start; \
name: Bohemian Dome Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi:2; \
vstart:0; \
vend:pi:2; \
c:1:a:1.0; \
c:2:b:1.0; \
c:3:c:1.0; \
x: a*cos(u); \
y: b*cos(v) + a*sin(u); \
z: c*sin(v); "
#if(COMPILE_DESC_DERIV_U_SURFACES != 0)
"xu: -a*sin(u); \
yu: a*cos(u); \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_SURFACES != 0)
"xv: 0; \
yv: -b*sin(v); \
zv: c*cos(v); "
#endif
#if(COMPILE_DESC_NORMAL_SURFACES != 0)
"xn: a*c*cos(u)*cos(v); \
yn: -a*c*sin(u)*cos(v); \
zn: a*b*sin(u)*sin(v); "
#endif
#if(COMPILE_DESC_DERIV2_U_SURFACES != 0)
"xuu: -a*cos(u); \
yuu: -a*sin(u); \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_SURFACES != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_SURFACES != 0)
"xvv: 0; \
yvv: -b*cos(v); \
zvv: -c*sin(v); "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBoysSurface = {
PSLDD_ID( BOYS_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_END_PI| PASULI_CONST_COUNT(0),
-0.5, 0.5 , 0 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBoysSurface =
"start; \
name: Boys Surface; \
utype:closed; \
vtype:closed; \
ustart:pi: -0.5; \
uend:pi: 0.5; \
vstart:0; \
vend:pi: 1; \
a:1:a: sqrt(2) ; \
a:2:b: 2 - a*sin(3*u)*sin(2*v); \
x: a*cos(v)*cos(v)*cos(2*u) + cos(u)*sin(2*v)/b; \
y: 3*cos(v)*cos(v)/b; \
z: a*cos(v)*cos(v)*sin(2*u) + cos(u)*sin(2*v)/b; "
#if(COMPILE_DESC_DERIV_U_SURFACES != 0)
"xu: (3*a*cos(u)*cos(3*u)*sin(2*v)*sin(2*v))/((2-a*sin(2*v)*sin(3*u))^2) - 2*a*cos(v)*cos(v)*sin(2*u) + \
(sin(u)*sin(2*v))/(a*sin(2*v)*sin(3*u)-2); \
yu: (9*a*cos(v)*cos(v)*cos(3*u)*sin(2*v))/((2-a*sin(2*v)*sin(3*u))^2); \
zu: (3*a*cos(u)*cos(3*u)*sin(2*v)*sin(2*v))/((2-a*sin(2*v)*sin(3*u))^2) + 2*a*cos(v)*cos(v)*cos(2*u) + \
(sin(u)*sin(2*v))/(a*sin(2*v)*sin(3*u)-2); "
#endif
#if(COMPILE_DESC_DERIV_V_SURFACES != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
"xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif



#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCrossCup = {
PSLDD_ID( CROSS_CUP )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI,
0, 1 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCrossCup =
"start; \
name: Cross Cup; \
utype: closed; \
vtype: closed; \
ustart:0; \
uend: 1; \
vstart: 0; \
vend:pi: 2; \
x: 1 - u*u + u*u*sin(v)*sin(v); \
y: u*u*sin(v)*sin(v) + 2*u*u*sin(v)*cos(v); \
z: sqrt((1 - u*u)/2)*u*(sin(v) + cos(v)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif



#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDiniSurface = {
PSLDD_ID( DINI_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 4 , 0.01f , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descDiniSurface =
"start; \
name: Dini Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 4; \
vstart: 0.01: \
vend: 2; \
c:1:a: 1.5; \
c:2:b: 0.5; \
x: a*cos(u)*sin(v); \
y: a*sin(u)*sin(v); \
z: a*(cos(v) + ln(tan(v/2))) + b*u; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddEnneperSurface = {
PSLDD_ID( ENNEPER_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_FULL_IMPL,
-2, 2 , -2 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descEnneperSurface =
"start; \
name: Enneper Surface; \
utype: closed; \
vtype: closed; \
ustart: -2; \
uend: 2; \
vstart: -2; \
vend: 2; \
x: u - (u*u*u/3) + u*v*v; \
y: v - (v*v*v/3) + u*u*v; \
z: u*u - v*v; "
"xu: 1 - u*u + v*v; \
yu: 2*u*v; \
zu: 2*u; "
"xv: 2*u*v; \
yv: 1 + u*u - v*v; \
zv: -2*v; "
"xn: -2*u*(1+u*u+v*v); \
yn: 2*v*(1+u*u+v*v); \
zn: 1-((u*u + v*v)^2); "
"xuu: -2*u; \
yuu: 2*v; \
zuu: 2; "
"xuv: 2*v; \
yuv: 2*u; \
zuv: 0; "
"xvv: 2*u; \
yvv: -2*v; \
zvv: -2; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHandkerchief = {
PSLDD_ID( HANDKERCHIEF )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_FULL_IMPL,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHandkerchief =
"start; \
name: Handkerchief; \
utype: closed; \
vtype: closed; \
ustart: -1; \
uend: 1; \
vstart: -1; \
vend: 1; \
x: u; \
y: v; \
z: u*u*u/3 + u*v*v + 2*(u*u - v*v); "
"xu: 1; \
yu: 0; \
zu: u*(4+u)+v*v; "
"xv: 0; \
yv: 1; \
zv: v*(2*u - 4); "
"xn: -u*(4+u) - v*v; \
yn: 2*v*(2-u); \
zn: 1; "
"xuu: 0; \
yuu: 0; \
zuu: 4+2*u; "
"xuv: 0; \
yuv: 0; \
zuv: 2*v; "
"xvv: 0; \
yvv: 0; \
zvv: 2*u-4; "
"end;";
#endif


/**

r = 4 (1 - cos(u)/2)

0 <= u <pi
x = a cos(u) (1 + sin(u)) + r cos(u) cos(v)
y = b sin(u) + r sin(u) cos(v)
z = r sin(v)

pi < u <= 2pi
x = a cos(u) (1 + sin(u)) + r cos(v +pi)
y = b sin(u)
z = r sin(v)
*/
#if(COMPILE_DEF_DESC_SURFACES != 0)

PaSuLiDefDesc pslddKleinBottleSurface = {
PSLDD_ID( KLEIN_BOTTLE_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
//TODO TODO TODO
char *descKleinBottleSurface =
"start; \
name: Klein Bottle Surface; \
utype:closed; \
vtype:closed; \
ustart: 0;  \
uend:pi: 2;  \
vstart: 0;  \
vend:pi: 2;  \
c:1:a: 1.5; \
c:2:b: 0.5; \
x: 0; \
y: 0; \
z: 0; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddMoebiusBand = {
PSLDD_ID( MOEBIUS_BAND )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_FULL_IMPL| \
PASULI_CONST_COUNT(1),
-1, 1 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descMoebiusBand =
"start; \
name: Moebius Band; \
utype: closed; \
vtype: closed; \
ustart: -1; \
uend: 1; \
vstart: 0; \
vend:pi: 2; \
c:1:r: 1.5; \
x: (r + u*cos(v/2))*cos(v); \
y: (r + u*cos(v/2))*sin(v); \
z: u*sin(v/2); "
"xu: cos(v)*cos(0.5*v); \
yu: cos(0.5*v)*sin(v); \
zu: sin(0.5*v); "
"xv: -r*sin(v) - 0.5*u*cos(v)*sin(0.5*v)-u*cos(0.5*v)*sin(v); \
yv: r*cos(v) + u*(cos(v)*cos(0.5*v)-sin(v)*sin(0.5*v)); \
zv: 0.5*u*cos(0.5*v); "
"xn: -sin(0.5*v)*(r*cos(v) + u*cos(v)*cos(0.5*v)) + 0.5*u*sin(v); \
yn: -sin(0.5*v)*(r*sin(v)+u*cos(0.5*v)*sin(v)) - 0.5*u*cos(v); \
zn: (r+u*cos(0.5*v))*cos(0.5*v); "
"xuu: 0; \
yuu: 0; \
zuu: 0; "
"xuv: -0.5*cos(v)*sin(0.5*v) - cos(0.5*v)*sin(v); \
yuv: cos(v)*cos(0.5*v) - 0.5*sin(v)*sin(0.5*v); \
zuv: 0.5*cos(0.5*v); "
"xvv: u*(sin(v)*sin(0.5*v) - 1.25*cos(v)*cos(0.5*v)) - r*cos(v); \
yvv: -u*(cos(v)*sin(0.5*v) + 1.25*cos(0.5*v)*sin(v)) - r*sin(v); \
zvv: -0.25*u*sin(0.5*v); "
"end;";
#endif



#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddMonkeySaddle = {
PSLDD_ID( MONKEY_SADDLE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_FULL_IMPL,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descMonkeySaddle =
"start; \
name: Monkey Saddle; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart: -1; \
vend: 1; \
x: u; \
y: v; \
z: u*u*u - 3*u*v*v; "
"xu: 1; \
yu: 0; \
zu: 3*(u*u - v*v); "
"xv: 0; \
yv: 1; \
zv: -6*u*v; "
"xn: 3*(v*v - u*u); \
yn: 6*u*v; \
zn: 1; "
"xuu: 0; \
yuu: 0; \
zuu: 6*u; "
"xuv: 0; \
yuv: 0; \
zuv: -6*v; "
"xvv: 0; \
yvv: 0; \
zvv: -6*u; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPlueckerConoid = {
PSLDD_ID( PLUECKER_CONOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_FULL_IMPL,
-2, 2 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descPlueckerConoid =
"start; \
name: Pluecker Conoid; \
utype:closed; \
vtype:closed; \
ustart: -2; \
uend: 2; \
vstart: -1; \
vend: 1; \
x: u*sqrt(1 - v*v); \
y: u*v; \
z: 1 - v*v; "
"xu: sqrt(1-v*v); \
yu: v; \
zu: 0; "
"xv: -u*v/(sqrt(1-v*v)); \
yv: u; \
zv: -2*v; "
"xn: -2*v*v; \
yn: 2*v*(sqrt(1-v*v)); \
zn: u/(sqrt(1-v*v)); "
"xuu: 0; \
yuu: 0; \
zuu: 0; "
"xuv: -v/(sqrt(1-v*v)); \
yuv: 1; \
zuv: 0; "
"xvv: -u/(sqrt(1-v*v)*(1-v*v)); \
yvv: 0; \
zvv: -2; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddRomanSurface = {
PSLDD_ID( ROMAN_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_FULL_IMPL,
0, 1 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descRomanSurface =
"start; \
name: Roman Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend: 1; \
vstart: 0; \
vend:pi: 2; \
x: 2*u*cos(v)*sqrt(1 - u*u); \
y: 2*u*sin(v)*sqrt(1 - u*u); \
z: 1 - 2*u*u*cos(v)*cos(v); "
"xu: 2*(1-2*u*u)*cos(v)/(sqrt(1-u*u)); \
yu: 2*(1-2*u*u)*sin(v)/(sqrt(1-u*u)); \
zu: -4*u*cos(v)*cos(v); "
"xv: -2*u*sqrt(1-u*u)*sin(v); \
yv: 2*u*sqrt(1-u*u)*cos(v); \
zv: 4*u*u*cos(v)*sin(v); "
"xn: ((8*u*u*(1-u*u*(1+sin(v)*sin(v))))*cos(v))/(sqrt(1-u*u)); \
yn: 8*((u*u*cos(v))^2)*sin(v)/(sqrt(1-u*u)); \
zn: 4*u(1-2*u*u); "
"xuu: 2*u*(2*u*u-3)*cos(v)/(sqrt(1-u*u)*(1-u*u)); \
yuu: 2*u*(2*u*u-3)*sin(v)/(sqrt(1-u*u)*(1-u*u)); \
zuu: -4*cos(v)*cos(v); \
xuv: 2*sin(v)*(2*u*u-1)/(sqrt(1-u*u)); \
yuv: 2*cos(v)*(1-2*u*u)/(sqrt(1-u*u)); \
zuv: 8*u*cos(v)*sin(v); \
xvv: -2*u*(sqrt(1-u*u))*cos(v); \
yvv: -2*u*(sqrt(1-u*u))*sin(v); \
zvv: 4*u*u*(2*cos(v)*cos(v) - 1); \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddShoeSurface = {
PSLDD_ID( SHOE_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_FULL_IMPL,
-2, 2 , -2 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descShoeSurface =
"start; \
name: Shoe Surface; \
utype:closed; \
vtype:closed; \
ustart: -2; \
uend: 2; \
vstart: -2; \
vend: 2; \
x: u; \
y: v; \
z: u*u*u/3 - v*v/2; "
"xu: 1; \
yu: 0; \
zu: u*u; "
"xv: 0; \
yv: 1; \
zv: -v; "
"xn: -u*u; \
yn: v; \
zn: 1; "
"xuu: 0; \
yuu: 0; \
zuu: 2*u; "
"xuv: 0; \
yuv: 0; \
zuv: 0; "
"xvv: 0; \
yvv: 0; \
zvv: -1; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSineSurface = {
PSLDD_ID( SINE_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_FULL_IMPL,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSineSurface =
"start; \
name: Sine Surface; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart:pi: -1; \
vend:pi: 1; \
x: sin(u); \
y: sin(v); \
z: sin(u+v); "
"xu: cos(u); \
yu: 0; \
zu: cos(u+v); "
"xv: 0; \
yv: cos(v); \
zv: cos(u+v); "
"xn: -cos(v)*cos(u+v); \
yn: -cos(u)*cos(u+v); \
zn: cos(u)*cos(v); "
"xuu: -sin(u); \
yuu: 0; \
zuu: -sin(u+v); "
"xuv: 0; \
yuv: 0; \
zuv: -sin(u+v); "
"xvv: 0; \
yvv: -sin(v); \
zvv: -sin(u+v); "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSteinbachScrew = {
PSLDD_ID( STEINBACH_SCREW )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_FULL_IMPL,
-4, 4 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSteinbachScrew =
"start; \
name: Steinbach Screw; \
utype:closed; \
vtype:closed; \
ustart: -4; \
uend: 4; \
vstart: 0; \
vend:pi: 2; \
x: u*cos(v); \
y: u*sin(v); \
z: v*cos(u); "
"xu: cos(v); yu: sin(v); zu: -v*sin(u); "
"xv: -u*sin(v); yv: u*cos(v); zv: cos(u); "
"xn: u*v*cos(v)*sin(u) + cos(u)*sin(v); \
yn: u*v*sin(u)*sin(v) - cos(u)*cos(v); \
zn: u; "
"xuu: 0; \
yuu: 0; \
zuu: -v*cos(u); "
"xuv: -sin(v); \
yuv: cos(v); \
zuv: -sin(u); "
"xvv: -u*cos(v); \
yvv: -u*sin(v); \
zvv: 0; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddWhitneyUmbrella = {
PSLDD_ID( WHITNEY_UMBRELLA )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_FULL_IMPL,
-1.5, 1.5 , -1.5 , 1.5 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descWhitneyUmbrella =
"start; \
name: Whitney Umbrella; \
utype:closed; \
vtype:closed; \
ustart: -1.5; \
uend: 1.5; \
vstart: -1.5; \
vend: 1.5; \
x: u*v; \
y: u; \
z: v*v; "
"xu: v; yu: 1; zu: 0; "
"xv: u; yv: 0; zv: 2*v; "
"xn: 2*v; \
yn: -2*v*v; \
zn: -u; "
"xuu: 0; yuu: 0; zuu: 0; "
"xuv: 1; yuv: 0; zuv: 0; "
"xvv: 0; yvv: 0; zvv: 2; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCatenoid = {
PSLDD_ID( CATENOID )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_U_START_PI|PASULI_U_END_PI|PASULI_FULL_IMPL|PASULI_CONST_COUNT(1),
-1, 1 , -2 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCatenoid =
"start; \
name: Catenoid; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart: -2; \
vend: 2; \
c:1:c:!=0: 1.5 ; \
x: c*cosh(v/c)*cos(u); \
y: c*cosh(v/c)*sin(u); \
z: v; "
"xu: -c*cosh(v/c)*sin(u); \
yu: c*cosh(v/c)*cos(u); \
zu: 0; "
"xv: sinh(v/c)*cos(u); \
yv: sinh(v/c)*sin(u); \
zv: 1; "
"xn: c*cos(u)*cosh(v/c); \
yn: c*cosh(v/c)*sin(u); \
zn: -c*cosh(v/c)*sinh(v/c); "
"xuu: -c*cos(u)*cosh(v/c); \
yuu: -c*sin(u)*cosh(v/c); \
zuu: 0; "
"xuv: sinh(v/c)*sin(u); \
yuv: sinh(v/c)*cos(u); \
zuv: 0; "
"xvv: (cos(u)*cosh(v/c))/c; \
yvv: (sin(u)*cosh(v/c))/c; \
zvv: 0; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHelicoid = {
PSLDD_ID( HELICOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_FULL_IMPL| \
PASULI_CONST_COUNT(1),
0, 1 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHelicoid =
"start; \
name: Helicoid; \
utype: closed; \
vtype: closed; \
ustart: -2; \
uend: 2; \
vstart: 0; \
vend:pi: 2; \
c:1:c: 1.5; \
x: u*cos(v); \
y: u*sin(v); \
z: c*v; "
"xu: cos(v); yu: sin(v); zu: 0; "
"xv: -u*sin(v); yv: u*cos(v); zv: c; "
"xn: c*sin(v); yn: -c*cos(v); zn: u; "
"xuu: 0; yuu: 0; zuu: 0; "
"xuv: -sin(v); yuv: cos(v); zuv: 0; "
"xvv: -u*cos(v); yvv: -u*sin(v); zvv: 0; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddParaboloid = {
PSLDD_ID( PARABOLOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI| \
PASULI_U_END_PI|PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
-1, 1 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descParaboloid =
"start; \
name: Paraboloid; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart: 0; \
vend: 2; \
c:1:a: 1.5; \
c:2:b: 0.5; \
x: a*v*cos(u); \
y: a*v*sin(u); \
z: b*v*v; "
"xu: -a*v*sin(u); \
yu: a*v*cos(u); \
zu: 0; "
"xv: a*cos(u); \
yv: a*sin(u); \
zv: 2*b*v; "
"xn: 2*a*b*v*v*cos(u); \
yn: 2*a*b*v*v*sin(u); \
zn: -a*a*v; "
"xuu: -a*v*cos(u); \
yuu: -a*v*sin(u); \
zuu: 0; "
"xuv: -a*sin(u); yuv: a*cos(u); zuv: 0; "
"xvv: 0; yvv: 0; zvv: 2*b; "
"end;";
#endif



#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHyperbolicHelicoid = {
PSLDD_ID( HYPERBOLIC_HELICOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(1),
-4, 4 , -4 , 4 , &psldd_15_05_constants[1] };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHyperbolicHelicoid =
"start; \
name: Hyperbolic Helicoid; \
utype:closed; \
vtype:closed; \
ustart: -4; \
uend: 4; \
vstart: -4; \
vend: 4; \
c:1:a: 0.5; \
x: sinh(v)*cos(a*u)/(1+cosh(u)*cosh(v));  \
y: sinh(v)*sin(a*u)/(1+cosh(u)*cosh(v)); \
z: cosh(v)*sinh(u)/(1+cosh(u)*cosh(v)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddFunnel = {
PSLDD_ID( FUNNEL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_FULL_IMPL,
0.01f, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descFunnel =
"start; \
name: Funnel; \
utype:closed; \
vtype:closed; \
ustart: 0.1; \
uend: 2; \
vstart: 0; \
vend:pi: 2; \
x: u*cos(v); \
y: u*sin(v); \
z: log(u); "
"xu: cos(v); yu: sin(v); zu: 1/u; "
"xv: -u*sin(v); yv: u*cos(v); zv: 0; "
"xn: -cos(v); \
yn: -sin(v); \
zn: u; "
"xuu: 0; yuu: 0; zuu: -1/(u*u); "
"xuv: -sin(v); yuv: cos(v); zuv: 0; "
"xvv: -u*cos(v); yvv: -u*sin(v); zvv: 0; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTractroid = {
PSLDD_ID( TRACTROID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI,
0, 4 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTractroid =
"start; \
name: Tractroid; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend: 4; \
vstart: 0; \
vend:pi: 2; \
x: sech(u)*cos(v); \
y: sech(u)*sin(v); \
z: u - tanh(u); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCatalansSurface = {
PSLDD_ID( CATALANS_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED,
-2, 2 , -1.4f , 1.4f , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCatalansSurface =
"start; \
name: Catalans Surface; \
utype:closed; \
vtype:closed; \
ustart:pi: -2; \
uend:pi: 2; \
vstart: -1.4; \
vend: 1.4; \
x: u - cosh(v)*sin(u); \
y: 1 - cosh(v)*cos(u); \
z: -4*sin(u/2)*sinh(v/2); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHyperboloid = {
PSLDD_ID( HYPERBOLOID )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_U_START_PI|PASULI_U_END_PI|PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
-1, 1 , -2 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHyperboloid =
"start; \
name: Hyperboloid; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart: -2; \
vend: 2; \
c:1:a: 1.5; \
c:2:b: 0.5; \
x: a*cosh(v)*cos(u); \
y: a*cosh(v)*sin(u); \
z: b*sinh(v); "
"xu: -a*cosh(v)*sin(u); \
yu: a*cos(u)*cosh(v); \
zu: 0; "
"xv: a*cos(u)*sinh(v); \
yv: a*sin(u)*sinh(v); \
zv: b*cosh(v); "
"xn: a*b*cos(u)*cosh(v)*cosh(v); \
yn: a*b*sin(u)*cosh(v)*cosh(v); \
zn: -a*a*cosh(v)*sinh(v); "
"xuu: -a*cos(u)*cosh(v); \
yuu: -a*sin(u)*cosh(v); \
zuu: 0; "
"xuv: -a*sin(u)*sinh(v); \
yuv: a*cos(u)*sinh(v); \
zuv: 0; "
"xvv: a*cos(u)*cosh(v); \
yvv: a*sin(u)*cosh(v); \
zvv: b*sinh(v); "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHennebergsSurface = {
PSLDD_ID( HENNEBERGS_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -0.5 , 0.5 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHennebergsSurface =
"start; \
name: Hennerbergs Surface; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart:pi: -0.5; \
vend:pi: 0.5; \
x: 2*cos(v)*sinh(u) - (2.0/3.0)*cos(3*v)*sinh(3*u); \
y: 2*sin(v)*sinh(u) + (2.0/3.0)*sin(3*v)*sinh(3*u); \
z: 2*cos(2*v)*cosh(2*u); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSwallowSurface = {
PSLDD_ID( SWALLOW_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_FULL_IMPL,
-2, 2 , -0.75 , 0.75 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSwallowSurface =
"start; \
name: Swallow Surface; \
utype:closed; \
vtype:closed; \
ustart: -2; \
uend: 2; \
vstart: 0.75; \
vend: 0.75; \
x: u*v*v + 3*v*v*v*v; \
y: -2*u*v - 4*v*v*v; \
z: u; "
"xu: v*v; \
yu: -2*v; \
zu: 1; "
"xv: 2*v*(6*v*v + u); \
yv: -2*u - 12*v*v; \
zv: 0; "
"xn: 2*(u+6*v*v); \
yn: 2*v*(u+6*v*v); \
zn: 2*v*v*(u+6*v*v); "
"xuu: 0; yuu: 0; zuu: 0; "
"xuv: 2*v; yuv: -2; zuv: 0; "
"xvv: 2*u+36*v*v; \
yvv: -24*v; \
zvv: 0; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddWallisConicalSurface = {
PSLDD_ID( WALLIS_CONICAL_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_FULL_IMPL|PASULI_CONST_COUNT(3),
-1, 1 , 0 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descWallisConicalSurface =
"start; \
name: Wallis Conical Surface; \
utype: closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart: 0; \
vend: 1; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
x: v*cos(u); \
y: v*sin(u); \
z: c*sqrt(a*a - b*b*cos(u)*cos(u)); "
"xu: -v*sin(u); \
yu: v*cos(u); \
zu: (b*b*c*cos(u)*sin(u))/(sqrt(a*a-b*b*cos(u)*cos(u))); "
"xv: cos(u); yv: sin(u); zv: 0; "
"xn: -(b*b*c*cos(u)*sin(u)*sin(u))/(sqrt(a*a-b*b*cos(u)*cos(u))); \
yn: (b*b*c*cos(u)*cos(u)*sin(u))/(sqrt(a*a-b*b*cos(u)*cos(u))); \
zn: -v; "
"xuu: -v*cos(u); \
yuu: -v*sin(u); \
zuu: (b*b*c*(a*a*(cos(u)*cos(u)-sin(u)*sin(u)) - b*b*(cos(u)^4)))/((a*a-b*b*cos(u)*cos(u))*sqrt(a*a-b*b*cos(u)*cos(u))); "
"xuv: -sin(u); \
yuv: cos(u); \
zuv: 0; "
"xvv: 0; \
yvv: 0; \
zvv: 0; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddMaedersOwl = {
PSLDD_ID( MAEDERS_OWL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI,
0, 4 , 0.001f , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descMaedersOwl =
"start; \
name: Maeders Owl; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 4; \
vstart: 0.001; \
vend: 1; \
x: v*cos(u) - 0.5*v*v*cos(2*u); \
y: -v*sin(u) - 0.5*v*v*sin(2*u); \
z: 4*exp(1.5*log(v))*cos(3*u/2)/3; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddRichmondSurface = {
PSLDD_ID(RICHMOND_SURFACE)
PASULI_U_CLOSED|PASULI_V_CLOSED,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descRichmondSurface =
"start; \
name: Richmond Surface; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart: -1; \
vend: 1; \
x: (-3*u - u^(5) + 2*u*u*u*v*v + 3*u*v*v*v*v)/(6*(u*u + v*v)); \
y: (-3*v - 3*u*u*u*u*v - 2*u*u*v*v*v + v^(5))/(6*(u*u + v*v)); \
z: u; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddScherkSurface = {
PSLDD_ID( SCHERK_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_FULL_IMPL,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descScherkSurface =
"start; \
name: Scherk Surface; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart:pi: -1; \
vend:pi: 1; \
c:1:c:!=0: 1.5; \
x: u; \
y: v; \
z: log(cos(c*u)/cos(c*v))/c; "
"xu: 1; yu: 0; zu: -sin(c*u)/cos(c*u); "
"xv: 0; yv: 1; zv: sin(c*v)/cos(c*v); "
"xn: sin(c*u)/cos(c*u); \
yn: -sin(c*v)/cos(c*v); \
zn: 1; "
"xuu: 0; \
yuu: 0; \
zuu: -c/(cos(c*u)*cos(c*u)); "
"xuv: 0; yuv: 0; zuv: 0; "
"xvv: 0; yvv: 0; zvv: c/(cos(c*v)*cos(c*v)); "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCosineSurface = {
PSLDD_ID( COSINE_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_FULL_IMPL,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCosineSurface =
"start; \
name: Cosine Surface; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart:pi: -1; \
vend:pi: 1; \
x: cos(u); \
y: cos(v); \
z: cos(u + v); "
"xu: -sin(u); yu: 0; zu: -sin(u+v); "
"xv: 0; yv: -sin(v); zv: -sin(u+v); "
"xn: -sin(v)*sin(u+v); \
yn: -sin(u)*sin(u+v); \
zn: sin(u)*sin(v); "
"xuu: -cos(u); yuu: 0; zuu: -cos(u+v); "
"xuv: 0; yuv: 0; zuv: -cos(u+v); "
"xvv: 0; yvv: -cos(v); zvv: -cos(u+v); "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddEightSurface = {
PSLDD_ID( EIGHT_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_FULL_IMPL,
0, 2 , -0.5 , 0.5 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descEightSurface =
"start; \
name: Eight Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart:pi: -0.5; \
vend:pi: 0.5; \
x: cos(u)*sin(2*v); \
y: sin(u)*sin(2*v); \
z: sin(v); "
"xu: -sin(u)*sin(2*v); \
yu: cos(u)*sin(2*v); \
zu: 0; "
"xv: 2*cos(u)*cos(2*v); \
yv: 2*cos(2*v)*sin(u); \
zv: cos(v); "
"xn: cos(u)*cos(v)*sin(2*v); \
yn: sin(u)*cos(v)*sin(2*v); \
zn: -2*cos(2*v)*sin(2*v); "
"xuu: -cos(u)*sin(2*v); \
yuu: -sin(u)*sin(2*v); \
zuu: 0; "
"xuv: -2*cos(2*v)*sin(u); \
yuv: 2*cos(2*v)*cos(u); \
zuv: 0; "
"xvv: -4*cos(u)*sin(2*v); \
yvv: -4*sin(u)*sin(2*v); \
zvv: -sin(v); "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddJetSurface = {
PSLDD_ID( JET_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 1 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descJetSurface =
"start; \
name: Jet Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 1; \
vstart: 0; \
vend:pi: 2; \
x: (1 - cosh(u))*sin(u)*cos(v)/2; \
y: (1 - cosh(u))*sin(u)*sin(v)/2; \
z: cosh(u); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDrop = {
PSLDD_ID( DROP )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
0, 1 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descDrop =
"start; \
name: Drop; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 1; \
vstart: 0; \
vend:pi: 2; \
c:1:a: 1.5; \
c:2:b: 0.5; \
x: a*(b - cos(u))*sin(u)*cos(v); \
y: a*(b - cos(u))*sin(u)*sin(v); \
z: cos(u); "
"xu: a*cos(v)*(b*cos(u) - cos(u)*cos(u) + sin(u)*sin(u)); \
yu: a*sin(v)*(b*cos(u) - cos(u)*cos(u) + sin(u)*sin(u)); \
zu: -sin(u); "
"xv: sin(u)*sin(v)*a*(cos(u)-b); \
yv: sin(u)*cos(v)*a*(b - cos(u)); \
zv: 0; "
"xn: a*(b - cos(u))*cos(v)*sin(u)*sin(u); \
yn: a*(b - cos(u))*sin(u)*sin(u)*sin(v); \
zn: sin(u)*a*a*(b-cos(u)*(1 - b*b + 3*b*cos(u)-2*cos(u)*cos(u))); "
"xuu: sin(u)*a*cos(v)*(4*cos(u)-b); \
yuu: sin(u)*a*sin(v)*(4*cos(u)-b); \
zuu: -cos(u); "
"xuv: sin(v)*a*(cos(u)*cos(u)-sin(u)*sin(u)-b*cos(u)); \
yuv: -cos(v)*a*(cos(u)*cos(u)-sin(u)*sin(u)-b*cos(u)); \
zuv: 0; "
"xvv: sin(u)*a*cos(v)*(cos(u)-b); \
yvv: sin(u)*a*sin(v)*(cos(u)-b); \
zvv: 0; "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTriaxialTeardrop = {
PSLDD_ID( TRIAXIAL_TEARDROP )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 1 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTriaxialTeardrop =
"start; \
name: Triaxial Teardrop; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 1; \
vstart: 0; \
vend:pi: 2; \
x: (1 - cos(u))*cos(u + 2*pi/3)*cos(v + 2*pi/3)/2; \
y: (1 - cos(u))*cos(u + 2*pi/3)*cos(v - 2*pi/3)/2; \
z: cos(u - 2*pi/3); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPillowShape = {
PSLDD_ID( PILLOW_SHAPE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_FULL_IMPL| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descPillowShape =
"start; \
name:pillow Shape; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 1; \
vstart:pi: -1; \
vend:pi: 1; \
c:1:a: 1.5; \
x: cos(u); \
y: cos(v); \
z: a*sin(u)*sin(v); "
"xu: -sin(u); \
yu: 0; \
zu: a*cos(u)*sin(v); "
"xv: 0; \
yv: -sin(v); \
zv: a*cos(v)*sin(u); "
"xn: a*cos(u)*sin(v)*sin(v); \
yn: a*cos(v)*sin(u)*sin(u); \
zn: sin(u)*sin(v); "
"xuu: -cos(u); \
yuu: 0; \
zuu: -a*sin(u)*sin(v); "
"xuv: 0; \
yuv: 0; \
zuv: a*cos(u)*cos(v); "
"xvv: 0; \
yvv: -cos(v); \
zvv: -a*sin(u)*sin(v); "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddFishSurface = {
PSLDD_ID( FISH_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 1 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descFishSurface =
"start; \
name: Fish Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 1; \
vstart: 0; \
vend:pi: 2; \
x: (cos(u) - cos(2*u))*cos(v)/4; \
y: (sin(u) - sin(2*u))*sin(v)/4; \
z: cos(u); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHorn = {
PSLDD_ID( HORN )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI| \
PASULI_V_END_PI|PASULI_FULL_IMPL| \
PASULI_CONST_COUNT(3),
0, 1 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHorn =
"start; \
name: Horn; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend: 1; \
vstart:pi: -1; \
vend:pi: 1; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
x: (a + u*cos(v))*sin(b*pi*u); \
y: (a + u*cos(v))*cos(b*pi*u) + c*u; \
z: u*sin(v); "
"xu: b*pi*cos(b*pi*u)(a+u*cos(v)) + cos(v)*sin(b*pi*u); \
yu: c - b*pi*sin(b*pi*u)*(a+u*cos(v)) + cos(v)*cos(b*pi*u); \
zu: sin(v); "
"xv: -u*sin(v)*sin(b*pi*u); \
yv: -u*sin(v)*cos(b*pi*u); \
zv: u*cos(v); "
"xn: u*(b*pi*sin(b*pi*u)*cos(v)*(-a - u*cos(v)) +c*cos(v)+cos(b*pi*u)); \
yn: -u*(b*pi*cos(v)*cos(b*pi*u)*(a+u*cos(v)) + sin(b*pi*u)); \
zn: u*sin(v)*(-b*pi*(a+u*cos(v)) + c*sin(b*pi*u) ); "
"xuu: b*pi*(-b*pi*sin(b*pi*u)*(a + u*cos(v))) + 2*cos(v)*cos(b*pi*u); \
yuu: b*pi*(-b*pi*cos(b*pi*u)*(a + u*cos(v))) - 2*cos(v)*sin(b*pi*u); \
zuu: 0; "
"xuv: -sin(v)*(b*pi*u*cos(b*pi*u) + sin(b*pi*u)); \
yuv: sin(v)*(b*pi*u*sin(b*pi*u) - cos(b*pi*u)); \
zuv: cos(v); "
"xvv: -u*cos(v)*sin(b*pi*u); \
yvv: -u*cos(v)*cos(b*pi*u); \
zvv: -u_sin(v); "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBentHorns = {
PSLDD_ID( BENT_HORNS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -2 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBentHorns =
"start; \
name: Bent Horns; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart:pi: -2; \
vend:pi: 2; \
x: (2 + cos(u))*(v/3 - sin(v)); \
y: (2 + cos(u + 2*pi/3))*(cos(v) - 1); \
z: (2 + cos(u - 2*pi/3))*(cos(v) - 1); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHyperbolicOctahedron = {
PSLDD_ID( HYPERBOLIC_OCTAHEDRON )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_FULL_IMPL,
-0.5, 0.5 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHyperbolicOctahedron =
"start; \
name: Hyperbolic Octahedron; \
utype:closed; \
vtype:closed; \
ustart:pi: -0.5; \
uend:pi: 0.5; \
vstart:pi: -1; \
vend:pi: 1; \
x: (cos(u)*cos(v))^(3); \
y: (sin(u)*cos(v))^(3); \
z: sin(v)^(3); "
"xu: -3*(cos(u)^2)*(cos(v)^3)*sin(u); \
yu: 3*cos(u)*(cos(v)^3)*(sin(u)^2); \
zu: 0; "
"xv: -3*(cos(u)^3)*(cos(v)^2)*sin(v); \
yv: -3*(cos(v)^2)*(sin(u)^3)*sin(v); \
zv: 3*cos(v)*sin(v)*sin(v); "
"xn: 9*cos(u)*(cos(v)^4)*(sin(u)^2)*(sin(v)^2); \
yn: 9*(cos(u)^2)*(cos(v)^4)*sin(u)*(sin(v)^2); \
zn: 9*(cos(u)^2)*(cos(v)^5)*(sin(u)^2)*sin(v); "
"xuu: 3*cos(u)*(cos(v)^3)*(2-3*cos(u)*cos(u)); \
yuu: 3*sin(u)*(cos(v)^3)*(2-3*sin(u)*sin(u)); \
zuu: 0; "
"xuv: 9*((cos(u)*cos(v))^2)*sin(u)*sin(v); \
yuv: -9*(cos(u)*(cos(v)^2)*(sin(u)^2)*sin(v); \
zuv: 0; "
"xvv: 3*(2-3*cos(v)*cos(v))*(cos(u)^3)*cos(v); \
yvv: 3*(2-3*cos(v)*cos(v))*(sin(u)^3)*cos(v); \
zvv: 3*sin(v)*(2-3*sin(v)*sin(v)); "
"end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPseudoCrossCap = {
PSLDD_ID( PSEUDO_CROSS_CAP )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descPseudoCrossCap =
"start; \
name: Pseudo Cross Cap; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart:pi: -1; \
vend:pi: 1; \
x: (1 - u*u)*sin(v); \
y: (1 - u*u)*sin(2*v); \
z: u; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCresent = {
PSLDD_ID( CRESENT )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(3),
0, 1 , 0 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCresent =
"start; \
name: Cresent; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend: 1; \
vstart: 0; \
vend: 1; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
x: (a + sin(b*pi*u)*sin(b*pi*v))*sin(c*pi*v); \
y: (a + sin(b*pi*u)*sin(b*pi*v))*cos(c*pi*v); \
z: cos(b*pi*u)*sin(b*pi*v) + 4*v - 2; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddStilettoSurface = {
PSLDD_ID( STILETTO_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 2 , 0 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descStilettoSurface =
"start; \
name: Stiletto Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 1; \
x: (2+cos(u))*cos(v)*cos(v)*cos(v)*sin(v); \
y: (2+cos(u+2*pi/3))*cos(v+2*pi/3)*cos(v+2*pi/3)*sin(v+2*pi/3)*sin(v+2*pi/3); \
z: -(2+cos(u-2*pi/3))*cos(v+2*pi/3)*cos(v+2*pi/3)*sin(v+2*pi/3)*sin(v+2*pi/3); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddKuensSurface = {
PSLDD_ID( KUENS_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED,
-4.3f, 4.3f , 0.03f , 3.11f , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descKuensSurface =
"start; \
name: Kuens Surface; \
utype:closed; \
vtype:closed; \
ustart: -4.3; \
uend: 4.3; \
vstart: 0.01; \
vend: 3.11; \
a:1:h: 1 + u*u*sin(v)*sin(v); \
x: (2*(cos(u) + u sin(u))*sin(v))/h; \
y: (2*(-u*cos(u) + sin(u))*sin(v))/h; \
z: log(tan(v/2)) + 2*cos(v)/h; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTrefoilKnots = {
PSLDD_ID( TREFOIL_KNOTS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
0, 12 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTrefoilKnots =
"start; \
name: Trefoil Knots; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 12; \
vstart: 0; \
vend:pi: 2; \
c:1:R: 1.5; \
c:2:r: 0.5; \
a:1:Bx: (R + r*cos(u/2))*cos(u/3); \
a:2:By: (R + r*cos(u/2))*sin(u/3); \
a:3:Bz: r + sin(u/2); \
x: Bx + r*cos(u/3)*cos(v-pi); \
y: By + r*sin(u/3)*cos(v-pi); \
z: Bz + r*sin(v-pi); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTranguloidTrefoil = {
PSLDD_ID( TRANGULOID_TREFOIL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTranguloidTrefoil =
"start; \
name: Tranguloid Trefoil; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart:pi: -1; \
vend:pi: 1; \
x: 2*sin(3*u)/(2 + cos(v)); \
y: 2*(sin(u) + 2*sin(2*u))/(2 + cos(v + 2*pi/3)); \
z: (cos(u) - 2*cos(2*u))*(2 + cos(v))*(2 + cos(v + 2*pi/3))/4; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCrown = {
PSLDD_ID( CROWN )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCrown =
"start; \
name: Crown; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 2; \
x: cos(u + 4)/3; \
y: cos(u)*sin(v)*cos(v)*sin(u)*cos(v) + 0.5*cos(u); \
z: cos(v)*sin(u)*cos(u)*sin(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTwistedPipeSurface = {
PSLDD_ID( TWISTED_PIPE_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTwistedPipeSurface =
"start; \
name: Twistedpipe Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 2; \
a:1:h: sqrt(1 + sin(v)*sin(v)); \
x: cos(v)*(2 + cos(u))/h; \
y: sin(v - 2*pi/3)*(2 + cos(u - 2*pi/3))/h; \
z: sin(v + 2*pi/3)*(2 + cos(u + 2*pi/3))/h; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddLoop = {
PSLDD_ID( LOOP )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descLoop =
"start; \
name: Loop; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart:pi: -1; \
vend:pi: 1; \
x: sin(v)*cos(u); \
y: 2*cos(v); \
z: 4*sin(v)*cos(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDupinCyclide = {
PSLDD_ID( DUPIN_CYCLIDE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(4),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descDupinCyclide =
"start; \
name: Dupin Cyclide; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 2; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
c:4:d: 1.0; \
a:1:h: a - c*cos(u)*cos(v); \
x: (d*(c - a*cos(u)*cos(v)) + b*b*cos(u))/h; \
y: (b*sin(u)*(a - d*cos(v)))/h; \
z: b*sin(v)*(c*cos(u) - d)/h; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddGuimardSurface = {
PSLDD_ID( GUIMARD_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(3),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descGuimardSurface =
"start; \
name: Guimard Surface; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart: -1; \
vend: 1; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
x: ((1 - u)*a + u*b)*cos(v); \
y: b*u*sin(v); \
z: c*u*sin(v)*sin(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddMennsSurface = {
PSLDD_ID( MENNS_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(1),
-1, 1 , -1 , 1 , psldd_10_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descMennsSurface =
"start; \
name: Menns Surface; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart: -1; \
vend: 1; \
c:1:a: 1.0; \
x: u; \
y: v; \
z: a*u^(4) + u*u*v - v*v; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddMilkBag = {
PSLDD_ID( MILK_BAG )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(1),
-1, 1 , -1 , 1 , psldd_10_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descMilkBag =
"start; \
name: Milk Bag; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart:pi: -1; \
vend:pi: 1; \
c:1:k: 1.0; \
x: k*(1 + u)*cos(v); \
y: k*(1 - u)*sin(v); \
z: u; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTriaxialTritorus = {
PSLDD_ID( TRIAXIAL_TRITORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTriaxialTritorus =
"start; \
name: Triaxial Tritorus; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart:pi: -1; \
vend:pi: 1; \
x: sin(u)*(1 + cos(v)); \
y: sin(u + 2*pi/3)*(1 + cos(v + 2*pi/3)); \
z: sin(u + 4*pi/3)*(1 + cos(v + 4*pi/3)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddVerrillSurface = {
PSLDD_ID( VERRILL_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI,
0.5, 1 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descVerrillSurface =
"start; \
name: Verrill Surface; \
utype:closed; \
vtype:closed; \
ustart: 0.5; \
uend: 1; \
vstart: 0; \
vend:pi: 2; \
x: -2*u*cos(v) + (2*cos(v)/u) - 2*u^(3)*cos(3*v)/3; \
y: 6*u*sin(v) - 2*sin(v)/u - 2*u^(3)*cos(3*v)/3; \
z: 4*log(u); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddZindlersConoid = {
PSLDD_ID( ZINDLERS_CONOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(1),
-1, 1 , -0.75f , 0.75f , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descZindlersConoid =
"start; \
name: Zindlers Conoid; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart: -0.75; \
vend: 0.75; \
c:1:a: 1.5; \
x: u*cos(v); \
y: u*sin(v); \
z: a*tan(2*v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddFolium = {
PSLDD_ID( FOLIUM )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descFolium =
"start; \
name: Folium; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart:pi: -1; \
vend:pi: 1; \
x: cos(u)*(2*v/pi - tanh(v)); \
y: cos(u + 2*pi/3)/cosh(v); \
z: cos(u - 2*pi/3)/cosh(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddLemniscape = {
PSLDD_ID( LEMNISCAPE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 1 , 0 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descLemniscape =
"start; \
name: Lemniscape; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 1; \
vstart: 0; \
vend:pi: 1; \
x: cos(v)*sqrt(abs(sin(2*u)))*cos(u); \
y: cos(v)*sqrt(abs(sin(2*u)))*sin(u); \
z: x*x - y*y + 2*x*y*tan(v)^(2);  \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTriplePointTwist = {
PSLDD_ID( TRIPLE_POINT_TWIST )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(1),
-2, 1.7f , -1.5f , 1.5f , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTriplePointTwist =
"start; \
name: Triple point Twist; \
utype:closed; \
vtype:closed; \
ustart: -2; \
uend: 1.7; \
vstart: -1.5; \
vend: 1.5; \
c:1:c: 1.5; \
x: u; \
y: v^(3) + c*v; \
z: u*v + v^(5) + c*v^(3); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTrashcan = {
PSLDD_ID( TRASHCAN )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTrashcan =
"start; \
name: Trashcan; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend: 2; \
c:1:a: 1.5; \
c:2:b: 0.5; \
x: (b + v)*cos(u); \
y: v*sin(u); \
z: a*v*v; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSpring1 = {
PSLDD_ID( SPRING1 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(4)|PASULI_CALC_U_END,//MUL_BY_CONST(3),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSpring1 =
"start; \
name: Spring 1; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi:c4: 2; \
vstart: 0; \
vend:pi: 2; \
c:1:R: 1.5; \
c:2:r: 0.5; \
c:3:L: 1.0; \
c:4:N: 1.0; \
x: (R + r*cos(v))*cos(u); \
y: (R + r*cos(v))*sin(u); \
z: r*(sin(v) + L*u/pi); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSpring2 = {
PSLDD_ID( SPRING2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(3),
-1, 1 , 0 , 5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSpring2 =
"start; \
name: Spring 2; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart: 0; \
vend:pi: 5; \
c:1:R: 1.5; \
c:2:r: 0.5; \
c:3:h: 1.0; \
a:1:w: sqrt(R*R + r*r); \
x: (R + r*cos(u))*cos(v) + r*h*sin(u)*sin(v)/w; \
y: (R + r*cos(u))*sin(v) - r*h*sin(u)*cos(v)/w; \
z: h*v + R*r*sin(u)/w; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCone = {
PSLDD_ID( CONE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_CONST_COUNT(1),
1, 3 , 0 , 2 , psldd_10_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCone =
"start; \
name: Cone; \
utype:closed; \
vtype:closed; \
ustart: 1; \
uend: 3; \
vstart: 0; \
vend:pi: 2; \
c:1:a: 1; \
x: u; \
y: a*u*sin(v); \
z: a*u*cos(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddIsolator = {
PSLDD_ID( ISOLATOR )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(3),
1.5f, 9.5f , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descIsolator =
"start; \
name: Isolator; \
utype:closed; \
vtype:closed; \
ustart: 1.5; \
uend:pi: 9.5; \
vstart: 0; \
vend:pi: 2; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
x: u; \
y: (a + b*sin(c*u*2*pi))*sin(v); \
z: (a + b*sin(c*u*2*pi))*cos(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)		//TODO TODO
PaSuLiDefDesc pslddEgg = {
PSLDD_ID( EGG )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_CONST_COUNT(3)| \
PASULI_CALC_U_END,
0, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descEgg =
"start; \
name: Egg; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend: c1: 1; \
vstart: 0; \
vend:pi: 2; \
c:1:a:<=c1: 0.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
x: c*sqrt(u*(u - a)*(u - b))*sin(v); \
y: u; \
z: c*sqrt(u*(u - a)*(u - b))*cos(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHyperbolicParaboloid = {
PSLDD_ID( HYPERBOLIC_PARABOLOID )
PASULI_U_CLOSED|PASULI_V_CLOSED,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHyperbolicParaboloid =
"start; \
name: Hyperbolic Paraboloid; \
utype: closed; \
vtype: closed; \
ustart: -1; \
uend: 1; \
vstart: -1; \
vend: 1; \
x: u; \
y: v; \
z: u*v; \
xu: 1; \
yu: 0; \
zu: v; \
xv: 0; \
yv: 1; \
zv: u; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDropSurface = {
PSLDD_ID( DROP_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-0.5, 0.5 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descDropSurface =
"start; \
name: Drop Surface; \
utype:closed; \
vtype:closed; \
ustart:pi: -0.5; \
uend:pi: 0.5; \
vstart: 0; \
vend:pi: 2; \
c:1:a: 1.5; \
x: cos(v)*cos(u); \
y: sin(v)*cos(u); \
z: sin(u - a); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddFacingSnail = {
PSLDD_ID( FACING_SNAIL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-0.5f, 0.5f , 0 , 6 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descFacingSnail =
"start; \
name: Facing Snail; \
utype:closed; \
vtype:closed; \
ustart:pi: -0.5; \
uend:pi: 0.5; \
vstart: 0; \
vend:pi: 6; \
c:1:a: 1.5; \
x: cos(v)*cos(u); \
y: sin(v)*cos(u); \
z: (1 - a*v)*sin(u); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPaperBag = {
PSLDD_ID( PAPER_BAG )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descPaperBag =
"start; \
name: Paper Bag; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend: 2; \
c:1:a: 1.5; \
c:2:b: 0.5; \
x: v*cos(u); \
y: (v + b*u)*sin(u); \
z: a*v*v; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddJeenerKleinSurface = {
PSLDD_ID( JEENER_KLEIN_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(3),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descJeenerKleinSurface =
"start; \
name: Jeener Klein Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 2; \
c:1:S: 1.5; \
c:2:T: 0.5; \
c:3:a: 1.0; \
a:1:W: ((S + 1)/4)*cos((S + 1)*u +pi/T) + sqrt(a); \
x: S*cos(u) + cos(S*u) - W*sin((S - 1)*u/2)*cos(v); \
y: W*sin(v); \
z: S*sin(u) - sin(S*u) - W*cos((S - 1)*u/2)*cos(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBonanJeenerKleinSurface = {
PSLDD_ID( BONAN_JEENER_KLEIN_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBonanJeenerKleinSurface =
"start; \
name: Bonan Jeener Klein Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 2; \
c:1:M: 1.5; \
c:2:T: 0.5; \
a:1:W: sin((M - 1)*u) + T; \
x: M*cos(u) - cos(M*u) - ((M - 1)/M)*W*sin((M + 1)*u/2)*cos(v); \
y: W*sin(v); \
z: M*sin(u) - sin(M*u) + ((M - 1)/M)*W*cos((M + 1)*u/2)*cos(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddKleinCycloid = {			//TODO TODO
PSLDD_ID( KLEIN_CYCLOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI,
0, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descKleinCycloid =
"start; \
name: Klein Cycloid; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend:pi:c2:c3: 2; \
vstart: 0; \
vend:pi: 4; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
x: cos(u/c)*cos(u/b)*(a + cos(v)) + sin(u/b)*sin(v)*cos(v); \
y: sin(u/c)*cos(u/b)*(a + cos(v)) + sin(u/b)*sin(v)*cos(v); \
z: -sin(u/b)*(a + cos(v)) + cos(u/b)*sin(v)*cos(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDoubleCone = {
PSLDD_ID( DOUBLE_CONE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI,
0, 2 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descDoubleCone =
"start; \
name: Double Cone; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: -1; \
vend: 1; \
x: v*cos(u); \
y: (v - 1)*cos(u + 2*pi/3); \
z: (1 - v)*cos(u - 2*pi/3); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHoleDisc = {
PSLDD_ID( HOLE_DISC )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI,
0, 2 , 3 , 4.5 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHoleDisc =
"start; \
name: Hole Disc; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 3; \
vend: 4.5; \
x: sin(u)/(sqrt(2) + sin(v)); \
y: cos(u)/(sqrt(2) + sin(v)); \
z: cos(u)/(1 + sqrt(2)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPisotTriaxial = {
PSLDD_ID( PISOT_TRIAXIAL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_U_END_PI,
0, 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descPisotTriaxial =
"start; \
name:pisot Triaxial; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 2; \
x: 0.655866*cos(1.03002 + u)*(2 + cos(v)); \
y: 0.74878*cos(1.40772 - u)*(2 + 0.868837*cos(2.43773 + v)); \
z: 0.868837*cos(2.43773 + u)*(2 + 0.495098*cos(0.377696 - v)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTriaxialHexatorus = {
PSLDD_ID( TRIAXIAL_HEXATORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_U_END_PI,
0, 2 ,0 , 2 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTriaxialHexatorus =
"start; \
name: Triaxial Hexatorus; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 2; \
x: sin(u)/(sqrt(2) + cos(v)); \
y: sin(u + 2*pi/3)/(sqrt(2) + cos(v + 2*pi/3)); \
z: cos(u - 2*pi/3)/(sqrt(2) + cos(v - 2*pi/3)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTwistedHeart = {
PSLDD_ID( TWISTED_HEART )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
0, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTwistedHeart =
"start; \
name: Twisted Heart; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend:pi: 1; \
vstart:pi: -1; \
vend:pi: 1; \
a:1:m: 1/sqrt(2); \
x: (|v| - |u| - |tanh(m*u)/m| + |tanh(m*v)/m|)*sin(v); \
y: (|v| + |u| - |(tanh(m*u)/m| - |tanh(m*v)/m|)*cos(v); \
z: m*(u*u + v*v)/(cosh(m*u)*cosh(m*v)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddHoleDiscus = {
PSLDD_ID( HOLE_DISCUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
0, 2 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descHoleDiscus =
"start; \
name: Hole Discus; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 2; \
c:1:a: 1.5; \
c:2:b: 0.5; \
x: sin(u)/(a + sin(v)); \
y: cos(v)/b; \
z: cos(u)/(a + sin(v)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddDisc = {
PSLDD_ID( DISC )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI,
0, 2 , 0 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descDisc =
"start; \
name: Disc; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend: 1; \
x: v*sin(u); \
y: 0; \
z: v*sin(u); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddWaves = {
PSLDD_ID( WAVES )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(3),
-2, 2 , -2 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descWaves =
"start; \
name: Waves; \
utype:closed; \
vtype:closed; \
ustart:pi: -2; \
uend:pi: 2; \
vstart:pi: -2; \
vend:pi: 2; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
x: u; \
y: v; \
z: a*cos(b*u)*cos(c*v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSineWave = {
PSLDD_ID( SINE_WAVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(2),
-5 , 5 , -5 , 5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSineWave =
"start; \
name: Sine Wave; \
utype:closed; \
vtype:closed; \
ustart: -5; \
uend: 5; \
vstart: -5; \
vend: 5; \
c:1:a: 1.5; \
c:2:b: 0.5; \
x: u; \
y: v; \
z: a*sin(b*sqrt(u*u + v*v)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCosineWave = {
PSLDD_ID( COSINE_WAVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(2),
-5, 5 , -5 , 5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCosineWave =
"start; \
name: Cosine Wave; \
utype:closed; \
vtype:closed; \
ustart: -5; \
uend: 5; \
vstart: -5; \
vend: 5; \
c:1:a: 1.5; \
c:2:b: 0.5; \
x: u; \
y: v; \
z: a*cos(b*sqrt(u*u + v*v)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSpiralWave = {
PSLDD_ID( SPIRAL_WAVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(3),
0, 2 , 0 , 20 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSpiralWave =
"start; \
name: Spiral Wave; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend: 20; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
x: v*cos(u); \
y: a*cos(b*u + c*v); \
z: v*sin(u); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0 \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBell = {
PSLDD_ID( BELL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(2),
-5 , 5 , -5 , 5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBell =
"start; \
name: Bell; \
utype:closed; \
vtype:closed; \
ustart: -5; \
uend: 5; \
vstart: -5; \
vend: 5; \
c:1:a: 1.5; \
c:2:b: 0.5; \
a:1:r: sqrt(u*u + v*v); \
x: u; \
y: v; \
z: b*exp(-(a*r)^(2)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBellPolar = {
PSLDD_ID( BELL_POLAR )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0 , 12 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBellPolar =
"start; \
name: Bell Polar; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend: 12; \
c:1:a: 1.5; \
c:2:b: 0.5; \
a:1:r: sqrt(2*v*v) = sqrt(x*x + y*y); \
x: v*cos(u); \
y: v*sin(u); \
z: b*exp(-(a*r)^(2)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBellWave = {
PSLDD_ID( BELL_WAVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0 , 12 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBellWave =
"start; \
name: Bell Wave; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend: 12; \
c:1:a: 1.5; \
c:2:b: 0.5; \
a:1:r: sqrt(u*u + v*v); \
x: u; \
y: v; \
z: cos(c*r)*b*exp(-(a*r)^(2)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSoucoupoid = {
PSLDD_ID( SOUCOUPOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_END_PI,
-1, 1 , 0 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSoucoupoid =
"start; \
name: Soucoupoid; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart: 0; \
vend:pi: 1; \
x: cos(u)*cos(v); \
y: (sin(u))^(3); \
z: cos(u)*sin(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddEnneperSurfacePolar = {
PSLDD_ID( ENNEPER_SURFACE_POLAR )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI,
0, 2 , 0 , 2.5f , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descEnneperSurfacePolar =
"start; \
name: Enneper Surface Polar; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend: 2.5; \
a:1:s: v*cos(u); \
a:2:t: v*sin(u); \
x: s - s^(3)/3 + s*t*t; \
y: t - t^(3)/3 + t*s*s; \
z: s*s - t*t; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSineCone = {
PSLDD_ID( 0 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(2),
-10, 10 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSineCone =
"start; \
name: Sine Cone; \
utype:closed; \
vtype:closed; \
ustart: -10; \
uend: 10; \
vstart:pi: -1; \
vend:pi: 1; \
c:1:k: 1.5; \
c:2:N: 0.5; \
x: u*cos(v); \
y: k*u*cos(N*v); \
z: u*sin(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSpinner = {
PSLDD_ID( SPINNER )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI|PASULI_CONST_COUNT(2),
-1, 1 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSpinner =
"start; \
name: Spinner; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart: 0; \
vend:pi: 2; \
c:1:R: 1.5; \
c:2:r: 0.5; \
x: (|u|-1)^(2)*cos(v); \
y: u; \
z: (|u|-1)^(2)*sin(v); \
xu: 0; \
yu: 1; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddFresnel = {
PSLDD_ID( FRESNEL )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(3),
-1, 1 , -0.5 , 0.5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descFresnel =
"start; \
name: Fresnel; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart:pi: -0.5; \
vend:pi: 0.5; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:c: 1.0; \
a:1:d: (sin(v)^(2)+c*c*cos(v)^(2)*(cos(u)^(2)/a*a + sin(u)^(2)/b*b)); \
x: (c*c/a)*(cos(u)^(2))/d; \
y: (c*c/b)*(sin(u)*cos(v))/d; \
z: c*(sin(v))/d; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTrefoilKnots2 = {
PSLDD_ID( TREFOIL_KNOTS2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(4),
0, 4 , 0 , 2 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTrefoilKnots2 =
"start; \
name: Trefoil Knots 2; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 4; \
vstart: 0; \
vend:pi: 2; \
c:1:R: 1.5; \
c:2:r: 0.5; \
c:3:a: 1.0; \
c:4:N: 1.0; \
x: r*cos(v)*cos(u) + R*cos(u)*(1 + a*cos(N*u)); \
y: r*sin(v) + a*sin(N*u); \
z: r*cos(v)*sin(u) + R*sin(u)*(1 + a*cos(N*u)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBowCurve = {
PSLDD_ID( BOW_CURVE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_CONST_COUNT(1),
0, 1 , 0 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBowCurve =
"start; \
name: Bow Curve; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend: 1; \
vstart: 0; \
vend: 1; \
c:1:T: 1.5; \
x: (2 + T*sin(2*pi*u))*sin(4*pi*v); \
y: (2 + T*sin(2*pi*u))*cos(4*pi*v); \
z: T*cos(2*pi*u) + 3*cos(2*pi*v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTripleCorkScrew1 = {
PSLDD_ID( TRIPLE_CORK_SCREW1 )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(4),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTripleCorkScrew1 =
"start; \
name: Triple Cork Screw 1; \
utype: closed; \
vtype: closed; \
ustart: -1; \
uend: 1; \
vstart:pi: -1; \
vend:pi: 1; \
c:1:R: 1.5; \
c:2:r: 0.5; \
c:3:L: 1.0; \
c:4:N: 1.0; \
x: L*u; \
y: r*(1 - |u|)*cos(v) + R*(1 - |u|)*cos(u*N*pi); \
z: r*(1 - |u|)*sin(v) + R*(1 - |u|)*sin(u*N*pi); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTripleCorkScrew2 = {
PSLDD_ID( TRIPLE_CORK_SCREW2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(6),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTripleCorkScrew2 =
"start; \
name: Triple Cork Screw 2; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart:pi: -1; \
vend:pi: 1; \
c:1:R: 1.5; \
c:2:r: 0.5; \
c:3:L: 1.0; \
c:4:N: 1.0; \
c:5:a: 1.0; \
c:6:b: 1.0; \
a:1:c: r*exp(-(b*b*u*u)); \
a:2:d: R*exp(-(a*a*u*u)); \
x: L*u; \
y: c*cos(v) + d*cos(u*N*pi); \
z: c*sin(v) + d*sin(u*N*pi); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddTripleCorkScrew3 = {
PSLDD_ID( TRIPLE_CORK_SCREW3 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(4),
-1, 1 , -1 , 1 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descTripleCorkScrew3 =
"start; \
name: Triple Cork Screw 3; \
utype:closed; \
vtype:closed; \
ustart: -1; \
uend: 1; \
vstart:pi: -1; \
vend:pi: 1; \
c:1:R: 1.5; \
c:2:r: 0.5; \
c:3:L: 1.0; \
c:4:N: 1.0; \
a:1:a: r*(1 - |u|); \
a:2:b: R*cos(u*pi/2); \
x: L*u; \
y: a*cos(v) + b*cos(u*N*pi); \
z: a*sin(v) + b*sin(u*N*pi); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBicornSurface = {
PSLDD_ID( BICORN_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI,
0, 2 , 0 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBicornSurface =
"start; \
name: Bicorn Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 1; \
x: sin(v)*cos(u); \
y: sin(v)*sin(u); \
z: cos(v)*cos(v)*(2 + cos(v))/(3 + sin(v)*sin(v)); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddPiriformSurface = {
PSLDD_ID( PIRIFORM_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI|PASULI_CONST_COUNT(3),
0, 2 , -0.5 , 0.5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descPiriformSurface =
"start; \
name:piriform Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart:pi: -0.5; \
vend:pi: 0.5; \
c:1:a: 1.5; \
c:2:b: 0.5; \
c:3:r: 1.0; \
a:1:c: (r + sin(v)); \
a:2:d: b*(cos(v)*c; \
x: d*cos(u); \
y: d*sin(u); \
z: a*c; \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddKappaSurface = {
PSLDD_ID( KAPPA_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_CONST_COUNT(1),
0, 2 , 0.25f , 0.5 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descKappaSurface =
"start; \
name: Kappa Surface; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0.25; \
vend:pi: 0.5; \
c:1:a: 1.5; \
a:1:r: a*cos(v); \
x: r*cos(u); \
y: r*sin(u); \
z: -r/tan(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddBulletNose = {
PSLDD_ID( BULLET_NOSE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0, 2 , 0.25f , 0.5f , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descBulletNose =
"start; \
name: Bullet Nose; \
utype:closed; \
vtype:closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0.25; \
vend:pi: 0.5; \
c:1:a: 1.5; \
c:2:b: 0.5; \
a:1:c: a*cos(v); \
x: c*cos(u); \
y: c*sin(u); \
z: -b/tan(v); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif


#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddSievertSurface = {
PSLDD_ID( SIEVERT_SURFACE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_END_PI|PASULI_CONST_COUNT(1),
-0.5f , 0.5f , 0.1f , 3 , psldd_15_05_constants };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descSievertSurface =
"start; \
name: Sievert Surface; \
utype:closed; \
vtype:closed; \
ustart:pi: -0.5; \
uend:pi: 0.5; \
vstart: 0.1; \
vend:pi: 3; \
c:1:C: 1.5; \
a:1:p: -u/sqrt(C + 1) + atan(tan(u)*sqrt(C + 1)); \
a:2:a: 2/(C + 1 - C*sin(v)*sin(v)*cos(u)*cos(u)); \
a:3:r: a*sqrt((C + 1)*(1 + C*sin(u)*sin(u)))*sin(v)/sqrt(C); \
x: r*cos(p); \
y: r*sin(p); \
z: (ln(tan(v/2)) + a*(C + 1)*cos(v))/sqrt(C); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif

#if(COMPILE_DEF_DESC_SURFACES != 0)
PaSuLiDefDesc pslddCosineSurface2 = {
PSLDD_ID( COSINE_SURFACE2)
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI,
-1, 1 , -1 , 1 , 0 };
#endif
#if(COMPILE_DESC_SURFACES != 0)
char *descCosineSurface2 =
"start; \
name: Cosine Surface 2; \
utype:closed; \
vtype:closed; \
ustart:pi: -1; \
uend:pi: 1; \
vstart:pi: -1; \
vend:pi: 1; \
x: cos(u); \
y: cos(v); \
z: -cos(u + v)^(2); \
xu: 0; \
yu: 0; \
zu: 0; \
xv: 0; \
yv: 0; \
zv: 0; \
xn: 0; \
yn: 0; \
zn: 0; \
xuu: 0; \
yuu: 0; \
zuu: 0; \
xuv: 0; \
yuv: 0; \
zuv: 0; \
xvv: 0; \
yvv: 0; \
zvv: 0; \
end;";
#endif

