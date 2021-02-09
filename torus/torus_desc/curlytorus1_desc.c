
#include "../torus_desc_inc.h"

#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddCurlyTorus1 = {
PSLDD_ID( CURLY_TORUS_1 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(4),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descCurlyTorus1 =
"start; \
name: Curly Torus 1; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R1: 1.0; \
c:2:R2: 1.0; \
c:3:r: 1.0; \
c:4:n: 1.0; \
x: (R1 + r*cos(v))*cos(u); \
y: r*sin(v) + R2*sin(n*u); \
z: (R1 + r*cos(v))*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: -(R1 + r*cos(v))*sin(u); \
yu: R2*n*cos(n*u); \
zu: (R1 + r*cos(v))*cos(u); "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: -r*cos(u)*sin(v); \
yv: r*cos(v); \
zv: -r*sin(u)*sin(v); "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn:X; \
xn: -r*(cos(u)*(cos(v)*(R1 + r*cos(v))) + R2*n*cos(n*u)*sin(u)*sin(v)); \
yn:X; \
yn: -r*(R1 + r*cos(v))*sin(v); \
zn:X; \
zn: r*(-sin(u)*cos(v)*R1 + r*cos(v) + R2*n*cos(u)*cos(n*u)*sin(v)); "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: -(R1 + r*cos(v))*cos(u); \
yuu: -R2*n*n*sin(n*u); \
zuu: -(R1 + r*cos(v))*sin(u); "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: r*sin(u)*sin(v); \
yuv: 0; \
zuv: -r*cos(u)*sin(v); "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: -r*cos(u)*cos(v); \
yvv: -r*sin(v); \
zvv: -r*cos(v)*sin(u); "
#endif
"end;";
#endif

