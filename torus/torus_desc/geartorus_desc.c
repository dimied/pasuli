
#include "../torus_desc_inc.h"

#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddGearTorus = {
PSLDD_ID( GEAR_TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_FULL_IMPL|PASULI_CONST_COUNT(4),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descGearTorus =
"start; \
name: GearTorus; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R: 1.0; \
c:2:a: 1.0; \
c:3:b: 1.0; \
c:4:N: 1.0; \
a:1:r: a + tanh(b*sin(n*v))/b; \
x: (R + r*cos(v))*cos(u); \
y: r*sin(v); \
z: (R + r*cos(v))*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: -(cos(v)*(a*b+tanh(b*sin(n*v)))+ R*b)*sin(u)/b; \
yu: 0; \
zu: (cos(v)*(a*b+tanh(b*sin(n*v)))+ R*b)*cos(u)/b; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: (-a*sin(v) + (n*cos(v)*cos(n*v))/(cosh(b*sin(n*v))^2) - sin(v)*tanh(b*sin(n*v))/b)*cos(u); \
yv: a*cos(v) + ()/(cosh(b*sin(n*v))^2) +cos(v)*tanh(b*sin(n*v))/b); \
zv: (-a*sin(v) + (n*cos(v)*cos(n*v))/(cosh(b*sin(n*v))^2) - sin(v)*tanh(b*sin(n*v))/b)*sin(u); "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn:X; \
xn: (-R*a*cos(v) - (R*n*cos(n*v)*sin(v))/(cosh(b*sin(n*v))^2) - \
(R*cos(v)*tanh(b*sin(n*v)))/b - (a*n*cos(v)*cos(n*v)*sin(v))/(cosh(b*sin(n*v))^2) - \
(2*a*cos(v)*cos(v)*tanh(b*sin(n*v)))/b - a*a*cos(v)*cos(v) - \
((cos(v)*tanh(b*sin(n*v))/(b))^2) - \
(n*cos(v)*cos(n*v)*sin(v)*tanh(b*sin(n*v)))/((cosh(b*sin(n*v))^2)*b) )*cos(u); \
yn:X; \
yn: -R*a*sin(v) + (R*n*cos(v)*cos(n*v))/(cosh(b*sin(n*v))^2) - (R*sin(v)*tanh(b*sin(n*v)))/b + \
(a*n*cos(v)*cos(v)*cos(n*v))/(cosh(b*sin(n*v))^2) - (2*a*cos(v)*sin(v)*tanh(b*sin(n*v)))/b - \
a*a*cos(v)*sin(v) - cos(v)*sin(v)*((tanh(b*sin(n*v)))/(b))^2 + \
(n*cos(v)*cos(v)*cos(n*v)*tanh(b*sin(n*v)))/(b*(cosh(b*sin(n*v))^2)); \
zn:X; \
zn: (-R*a*cos(v) - (R*n*cos(n*v)*sin(v))/(cosh(b*sin(n*v))^2) - \
(R*cos(v)*tanh(b*sin(n*v)))/b - (a*n*cos(v)*cos(n*v)*sin(v))/(cosh(b*sin(n*v))^2) - \
(2*a*cos(v)*cos(v)*tanh(b*sin(n*v)))/b - a*a*cos(v)*cos(v) - \
((cos(v)*tanh(b*sin(n*v))/(b))^2) - \
(n*cos(v)*cos(n*v)*sin(v)*tanh(b*sin(n*v)))/((cosh(b*sin(n*v))^2)*b) )*sin(u); "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: -(R*b + cos(v)*(a*b + tanh(b*sin(n*v))))*cos(u)/b; \
yuu: 0; \
zuu: -(R*b + cos(v)*(a*b + tanh(b*sin(n*v))))*sin(u)/b; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: sin(u)*(a*sin(v) - (n*cos(v)*cos(n*v))/(cosh(b*sin(n*v))^2) + (sin(v)*tanh(b*sin(n*v)))/b); \
yuv: 0; \
zuv: -cos(u)*(a*sin(v) - (n*cos(v)*cos(n*v))/(cosh(b*sin(n*v))^2) + (sin(v)*tanh(b*sin(n*v)))/b); "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: (-a*cos(v) - (2*b*n*n*cos(v)*(cos(n*v)^2)*sinh(b*sin(n*v)))/(cosh(b*sin(n*v))^3) - \
(2*n*cos(n*v)*sin(v))/(cosh(b*sin(n*v))^2) - (cos(v)*tanh(b*sin(n*v)))/b - \
(n*n*cos(v)*sin(n*v))/(cosh(b*sin(n*v))^2))*cos(u); \
yvv: -a*sin(v) - (2*b*n*n*(cos(n*v)^2)*sin(v)*sinh(b*sin(n*v)))/(cosh(b*sin(n*v))^3) + \
(2*n*cos(v)*cos(n*v))/(cosh(b*sin(n*v))^2) - (sin(v)*tanh(b*sin(n*v)))/b - \
(n*n*sin(v)*sin(n*v))/(cosh(b*sin(n*v))^2); \
zvv: (-a*cos(v) - (2*b*n*n*cos(v)*(cos(n*v)^2)*sinh(b*sin(n*v)))/(cosh(b*sin(n*v))^3) - \
(2*n*cos(n*v)*sin(v))/(cosh(b*sin(n*v))^2) - (cos(v)*tanh(b*sin(n*v)))/b - \
(n*n*cos(v)*sin(n*v))/(cosh(b*sin(n*v))^2))*sin(u); "
#endif
"end;";
#endif

