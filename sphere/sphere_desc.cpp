
#include "../pasuli_const.h"
#include "sphere_desc.h"


pasulidefdesc_ct sphere_def_constants[] = {1.5, 1.0, 1.0};

#if(COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddSphere = {
PSLDD_ID( SPHERE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(0),
0, 2, 0, 1, 0 };
#endif
#if(COMPILE_DESC_SPHERE != 0)
char *descSphere = 
"start; \
name: sphere; \
cat: sphere; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend:pi: 2; \
vstart: 0; \
vend:pi: 1; \
x: cos(u)*sin(v); \
y: sin(u)*sin(v); \
z: cos(v); "
#if(COMPILE_DESC_DERIV_U_SPHERE != 0)
"xu: -sin(u)*sin(v); \
yu: cos(u)*sin(v); \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_SPHERE != 0)
"xv: cos(u)*cos(v); \
yv: sin(u)*cos(v); \
zv: -sin(v); "
#endif
#if(COMPILE_DESC_NORMAL_SPHERE != 0)
"xn: -cos(u)*sin(v)*sin(v); \
yn: -sin(u)*sin(v)*sin(v); \
zn: -sin(v)*cos(v); "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xuu: -cos(u)*sin(v); \
yuu: -sin(u)*sin(v); \
zuu:  0; "
#endif
#if(COMPILE_DESC_DERIV_UV_SPHERE != 0)
"xuv: -sin(u)*cos(v); \
yuv: cos(u)*cos(v); \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_SPHERE != 0)
"xvv: -cos(u)*sin(v); \
yvv: -sin(u)*sin(v); \
zvv:  -cos(v); "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddEllipsoid = {
PSLDD_ID( ELLIPSOID )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|PASULI_V_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(3),
0, 2, 0, 1, sphere_def_constants };
#endif
#if(COMPILE_DESC_SPHERE != 0)
char *descEllipsoid = 
"start; \
name: ellipsoid; \
cat: sphere; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend: pi : 2; \
vstart: 0; \
vend: pi : 1; \
c:1:a: 1.5; \
c:2:b: 1.0; \
c:3:c: 1.0; \
x: a*cos(u)*sin(v); \
y: b*sin(u)*sin(v); \
z: c*cos(v); "
#if(COMPILE_DESC_DERIV_U_SPHERE != 0)
"xu: -a*sin(u)*sin(v); \
yu: b*cos(u)*sin(v); \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_SPHERE != 0)
"xv: a*cos(u)*cos(v); \
yv: b*sin(u)*cos(v); \
zv: -c*sin(v); "
#endif
#if(COMPILE_DESC_NORMAL_SPHERE != 0)
"xn: -b*c*sin(v)*sin(v)*cos(u); \
yn: -a*c*sin(v)*sin(v)*sin(u); \
zn: -a*b*sin(v)*cos(v); "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xuu: -a*cos(u)*sin(v); \
yuu: -b*sin(u)*sin(v); \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_SPHERE != 0)
"xuv: -a*sin(u)*cos(v); \
yuv: b*cos(u)*cos(v); \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xvv: -a*cos(u)*sin(v); \
yvv: -b*sin(u)*sin(v); \
zvv: -c*cos(v); "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddSphereV = {
PSLDD_ID( SPHERE_V)
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(0),
0, 1, -1, 1, 0 };
#endif
#if(COMPILE_DESC_SPHERE != 0)
char *descSphereV =
"start; \
name: sphere v; \
cat: sphere; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend: pi : 1; \
vstart: pi : -1; \
vend: pi : 1; \
x: cos(u)*cos(v); \
y: sin(v); \
z: sin(u)*cos(v); "
#if(COMPILE_DESC_DERIV_U_SPHERE != 0)
"xu: -sin(u)*cos(v); \
yu: 0; \
zu: cos(u)*cos(v); "
#endif
#if(COMPILE_DESC_DERIV_V_SPHERE != 0)
"xv: -cos(u)*sin(v); \
yv: cos(v); \
zv: -sin(u)*sin(v); "
#endif
#if(COMPILE_DESC_NORMAL_SPHERE != 0)
"xn: -cos(u)*cos(v)*cos(v); \
yn: -sin(v)*cos(v); \
zn: -sin(u)*cos(v)*cos(v); "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xuu: -cos(u)*cos(v); \
yuu: 0; \
zuu: -sin(u)*cos(v); "
#endif
#if(COMPILE_DESC_DERIV_UV_SPHERE != 0)
"xuv: sin(u)*sin(v); \
yuv: 0; \
zuv: -cos(u)*sin(v); "
#endif
#if(COMPILE_DESC_DERIV2_V_SPHERE != 0)
"xvv: -cos(u)*cos(v); \
yvv: -sin(v); \
zvv: -cos(v)*sin(u); "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddOpenSphere = {
PSLDD_ID( OPEN_SPHERE )
PASULI_FULL_IMPL|PASULI_U_CLOSED|PASULI_V_CLOSED,
-10, 10, -10, 10, 0 };
#endif
#if(COMPILE_DESC_SPHERE != 0)
char *descOpenSphere = 
"start; \
name: open sphere; \
cat: sphere; \
utype: open; \
vtype: open; \
ustart: -10; \
uend: 10; \
vstart: -10; \
vend: 10; \
x: 2*u/(1 + u*u + v*v); \
y: (u*u + v*v - 1)/(1 + u*u + v*v); \
z: 2*v/(1 + u*u + v*v); "
#if(COMPILE_DESC_DERIV_U_SPHERE != 0)
"xu: 2*(1 - u*u + v*v)/((1 + u*u + v*v)^2); \
yu: 4*u/((1 + u*u + v*v)^2); \
zu: -4*u*v/((1 + u*u + v*v)^2); "
#endif
#if(COMPILE_DESC_DERIV_V_SPHERE != 0)
"xv: -4*u*v/((1 + u*u + v*v)^2); \
yv: 4*v/((1 + u*u + v*v)^2); \
zv: 2*(1+u*u - v*v)/((1 + u*u + v*v)^2); "
#endif
#if(COMPILE_DESC_NORMAL_SPHERE != 0)
"xn: 8*u/((1 + u*u + v*v)^3); \
yn: 4*(-1 + u*u + v*v)/((1 + u*u + v*v)^3); \
zn: 8*v/((1 + u*u + v*v)^3); "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xuu: 4*u*(u*u - 3*(1+v*v))/((1 + u*u + v*v)^3); \
yuu: 4*(1+v*v-3*u*u)/((1 + u*u + v*v)^3); \
zuu: 4*v*(3*u*u - (1+v*v))/((1 + u*u + v*v)^3); "
#endif
#if(COMPILE_DESC_DERIV_UV_SPHERE != 0)
"xuv: 4*v*(3*u*u - (1+v*v))/((1 + u*u + v*v)^3); \
yuv: -(16*u*v)/((1 + u*u + v*v)^3); \
zuv: 4*u*(3*v*v - (1+u*u))/((1 + u*u + v*v)^3); "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xvv: 4*u*(3*v*v - (1+u*u))/((1 + u*u + v*v)^3); \
yvv: 4*(1+u*u-3*v*v)/((1 + u*u + v*v)^3); \
zvv: 4*v*(v*v - 3*(1+u*u))/((1 + u*u + v*v)^3); "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddSphereUV = {
PSLDD_ID( SPHERE_UV )
PASULI_FULL_IMPL|PASULI_U_CLOSED|PASULI_V_CLOSED,
0, 10, -10, 10, 0 };
#endif
#if(COMPILE_DESC_SPHERE != 0)
char *descSphereUV = 
"start; \
name: sphere uv; \
cat: sphere; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend: 10; \
vstart: -10; \
vend: 10; \
x: 2*u*(1 - v*v)/((1 + u*u)*(1 + v*v)); \
y: (1 - u*u)/(1 + u*u); \
z: (4*u*v)/((1 + u*u)*(1 + v*v)); "
#if(COMPILE_DESC_DERIV_U_SPHERE != 0)
"xu: 2*(2*u*u*v*v - 2*u*u + (1 + u*u)*(1-v*v))/((1 + u*u)^2)*(1 + v*v)); \
yu: -4*u/(1+u*u)^2; \
zu: 4*v*(1 - u*u)/((1 + u*u)^2)*(1 + v*v)); "
#endif
#if(COMPILE_DESC_DERIV_V_SPHERE != 0)
"xv: -8*u*v/((1 + u*u))*((1 + v*v))^2); \
yv: 0; \
zv: 4*u*(1-v*v)/((1 + u*u))*((1 + v*v))^2); "
#endif
#if(COMPILE_DESC_NORMAL_SPHERE != 0)
"xn: 16*u*u(v*v - 1)/((1 + u*u)^3)*((1 + v*v))^2); \
yn: 8*u*(u*u*(1+v*v)-(1+v*v))/((1 + u*u)^3)*((1 + v*v))^2); \
zn: -32*u*u*v/((1 + u*u)^3)*((1 + v*v))^2); "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xuu: 4*u*(u*u*(1-v*v) + 3*(v*v-1))/((1 + u*u)^3)*(1 + v*v)); \
yuu: 4*(-1 + u*u*(-2 + u*u*(5 * u*u*(20 + u*u*(50 + u*u*(14 + 3*u*u))))))/((1 + u*u)^8); \
zuu: 8*u*v*(u*u - 3)/((1 + u*u)^3)*(1 + v*v)); "
#endif
#if(COMPILE_DESC_DERIV_UV_SPHERE != 0)
"xuv: 8*v*(u*u - 1)/((1 + u*u)^2)*(1 + v*v)^2); \
yuv: 0; \
zuv: 4*(u*u*(v*v-1) - (v*v-1))/((1 + u*u)^2)*(1 + v*v)^2); "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xvv: 8*u*(-1 + v*v*(-5 + v*v*(-4 + v*v*(28 + v*v*(98 + v*v*(154 + v*v*(140 + v*v*(76 + v*v*(23 + 3*v*v)))))))))/((1 + u*u))*(1 + v*v)^11); \
yvv: 0; \
zvv: 8*u*v*(v*v-3)/((1 + u*u))*(1 + v*v)^3); "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddTwistedSphere = {
PSLDD_ID( TWISTED_SPHERE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI| \
PASULI_V_START_PI|PASULI_V_END_PI| \
PASULI_FULL_IMPL|PASULI_CONST_COUNT(2),
0, 2, -1, 1, 0 };
#endif
#if(COMPILE_DESC_SPHERE != 0)
char *descTwistedSphere =
"start; \
name: twisted sphere; \
cat: sphere; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend: pi : 2; \
vstart: pi : -1; \
vend: pi : 1; \
c:1:a: 1.0; \
c:2:b: 1.0; \
x: a*cos(u)*cos(v); \
y: a*sin(v) + b*u; \
z: a*sin(u)*cos(v); "
#if(COMPILE_DESC_DERIV_U_SPHERE != 0)
"xu: -a*sin(u)*cos(v); \
yu: b; \
zu: a*cos(u)*cos(v); "
#endif
#if(COMPILE_DESC_DERIV_V_SPHERE != 0)
"xv: -a*cos(u)*sin(v); \
yv: a*cos(v); \
zv: -a*sin(u)*sin(v); "
#endif
#if(COMPILE_DESC_NORMAL_SPHERE != 0)
"xn: -a*(a*cos(u)*cos(v)*cos(v) + b*sin(u)*sin(v)); \
yn: -a*a*(cos(v)*sin(v)); \
zn: a*(b*cos(u)*sin(v) - a*cos(v)*cos(v)*sin(u)); "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xuu: -a*cos(u)*cos(v); \
yuu: 0; \
zuu: -a*cos(v)*sin(u); "
#endif
#if(COMPILE_DESC_DERIV_UV_SPHERE != 0)
"xuv: a*sin(u)*sin(v); \
yuv: 0; \
zuv: -a*cos(u)*sin(v); "
#endif
#if(COMPILE_DESC_DERIV2_V_SPHERE != 0)
"xvv: -a*cos(u)*cos(v); \
yvv: -a*sin(v); \
zvv: -a*cos(v)*sin(u); "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddWaveSphere = {
PSLDD_ID( WAVE_SPHERE )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_V_END_PI| \
PASULI_FULL_IMPL,
0, 14, 0, 2, 0 };
#endif
#if(COMPILE_DESC_SPHERE != 0)
char *descWaveSphere = 
"start; \
name: wave sphere; \
cat: sphere; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend: 14; \
vstart: 0; \
vend: pi : 2; \
x: u*cos(cos(u))*cos(v); \
y: u*cos(cos(u))*sin(v); \
z: u*sin(cos(u)); "
#if(COMPILE_DESC_DERIV_U_SPHERE != 0)
"xu: cos(v)*(cos(cos(u)) + u*sin(u)*sin(cos(u))); \
yu: sin(v)*(cos(cos(u)) + u*sin(u)*sin(cos(u))); \
zu: sin(cos(u)) - u*cos(cos(u))*sin(u); "
#endif
#if(COMPILE_DESC_DERIV_V_SPHERE != 0)
"xv: -u*cos(cos(u))*sin(v); \
yv: u*cos(v)*cos(cos(u)); \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_SPHERE != 0)
"xn: u*cos(cos(u))(u*cos(cos(u)*sin(u)-sin(cos(u))))*cos(v); \
yn: u*cos(cos(u))(u*cos(cos(u)*sin(u)-sin(cos(u))))*sin(v); \
zn: u*(cos(cos(u))^2 + u*cos(cos(u))*sin(u)*sin(cos(u))); "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xuu: cos(v)*(u*cos(u)*sin(cos(u)) - u*cos(cos(u))*sin(u)^2 + 2*sin(u)*sin(cos(u))); \
yuu: sin(v)*(u*cos(u)*sin(cos(u)) - u*cos(cos(u))*sin(u)^2 + 2*sin(u)*sin(cos(u))); \
zuu: -(cos(cos(u))*(2*sin(u) + u*cos(u)) + u*sin(cos(u))*sin(u)*sin(u)); "
#endif
#if(COMPILE_DESC_DERIV_UV_SPHERE != 0)
"xuv: -sin(v)*(cos(cos(u)) + u*sin(u)*sin(cos(u))); \
yuv: cos(v)*(cos(cos(u)) + u*sin(u)*sin(cos(u))); \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_SPHERE != 0)
"xvv: -u*cos(cos(u))*cos(v); \
yvv: -u*sin(v)*cos(cos(u)); \
zvv: 0; "
#endif
"end;";
#endif


#if(COMPILE_DEF_DESC_SPHERE != 0)
PaSuLiDefDesc pslddPseudoSphere = {
PSLDD_ID( PSEUDOSPHERE )
PASULI_U_CLOSED|PASULI_V_CLOSED| \
PASULI_U_START_PI|PASULI_U_END_PI| \
PASULI_FULL_IMPL,
-1, 1, 0.1f, 3.1f, 0 };
#endif
#if(COMPILE_DESC_SPHERE != 0)
char *descPseudoSphere = 
"start; \
name: pseudo sphere; \
cat: sphere; \
utype: closed; \
vtype: closed; \
ustart: pi : -1; \
uend: pi : 1; \
vstart: 0.1; \
vend: 3.10; \
x: cos(u)*sin(v); \
y: sin(u)*sin(v); \
z: cos(v) + log(tan(v/2)); "
#if(COMPILE_DESC_DERIV_U_SPHERE != 0)
"xu: -sin(v)*sin(u) ; \
yu: sin(v)*cos(u); \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_SPHERE != 0)
"xv: cos(u)*cos(v); \
yv: sin(u)*cos(v); \
zv: -sin(v) + 1/(2*cos(0.5*v)*cos(0.5*v)*tan(0.5*v)); "
#endif
#if(COMPILE_DESC_NORMAL_SPHERE != 0)
"xn: (-sin(v) + 1/(2*cos(0.5*v)*cos(0.5*v)*tan(0.5*v)))*cos(u)*sin(v); \
yn: (-sin(v) + 1/(2*cos(0.5*v)*cos(0.5*v)*tan(0.5*v)))*sin(u)*sin(v); \
zn: -cos(v)*sin(v); "
#endif
#if(COMPILE_DESC_DERIV2_U_SPHERE != 0)
"xuu: -cos(u)*sin(v); \
yuu: -sin(u)*sin(v); \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_SPHERE != 0)
"xuv: -cos(v)*sin(u); \
yuv: cos(u)*cos(v); \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_SPHERE != 0)
"xvv: -cos(u)*sin(v); \
yvv: -sin(u)*sin(v); \
zvv: -cos(v) - (1/(2*cos(0.5*v)*cos(0.5*v)*tan(0.5*v)))^2 + 1/(2*cos(0.5*v)*cos(0.5*v)); "
#endif
"end;";
#endif

