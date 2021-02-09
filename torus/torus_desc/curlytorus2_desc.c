
#include "../torus_desc_inc.h"

#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddCurlyTorus2 = {
PSLDD_ID( CURLY_TORUS_2 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(4),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descCurlyTorus2 =
"start; \
name: Curly Torus 2; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R1: 1.0; \
c:2:R2: 1.0; \
c:3:r: 1.0; \
c:4:n: 1.0; \
a:1:F: (R1 + R2*cos(n*u) + r*cos(v)); \
x: F*cos(u); \
y: r*sin(v); \
z: F*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: -((R1 + R2*cos(n*u) + r*cos(v))*sin(u) + R2*n*cos(u)*sin(n*u)); \
yu: 0; \
zu: (R1 + R2*cos(n*u) + r*cos(v))*cos(u) - R2*n*sin(u)*sin(n*u); "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: -r*cos(u)*sin(v); \
yv: r*cos(v); \
zv: -r*sin(u)*sin(v); "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn:X; \
xn: (R2*n*sin(n*u)*sin(u) - (R1 + R2*cos(n*u) + r*cos(r))*cos(u))*r*cos(v); \
yn:X; \
yn: -(R1 + R2*cos(n*u) + r*cos(v))*r*sin(v)); \
zn:X; \
zn: -(R2*n*cos(n*u)*sin(u) + (R1 + R2*cos(n*u) + r*cos(r))*sin(u))*r*cos(v); "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: -(R1 + R2*(1 + n*n)*cos(n*u) + r*cos(v))*cos(u) + 2*R2*n*sin(u)*sin(n*u); \
yuu: 0; \
zuu: -(R1 + R2*(1 + n*n)*cos(n*u) + r*cos(v))*sin(u) - 2*R2*n*cos(u)*sin(n*u); "
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

