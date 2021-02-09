
#include "../torus_desc_inc.h"

#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddTorusKnot = {
PSLDD_ID( TORUS_KNOT )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(5),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descTorusKnot =
"start; \
name: TorusKnot; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R1: 1.0; \
c:2:R2: 1.0; \
c:3:r: 1.0; \
c:4:p: 1.0; \
c:5:q: 1.0; \
a:1:F: (R1 + R2*cos(p*u) + r*cos(v)); \
x: F*cos(q*u); \
y: r*sin(v) + R2*sin(p*u); \
z: F*sin(q*u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: -( q*sin(q*u)*(R1 +R2*cos(p*u) + r*cos(v)) + R2*p*cos(q*u)*sin(p*u) ); \
yu: R2*p*cos(p*u); \
zu: q*cos(q*u)*(R1 +R2*cos(p*u) + r*cos(v)) - R2*p*sin(q*u)*sin(p*u); "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: -r*cos(q*u)*sin(v); \
yv: r*cos(v); \
zv: -r*sin(v)*sin(q*u); "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn:X; \
yn:X; \
zn:X; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: -cos(q*u)*(q*q*(R1 + R2*cos(p*u) + r*cos(v)) - p*p*R2*cos(p*u) ) + \
2*R2*p*q*sin(q*u)*sin(p*u) ; \
yuu: -R2*p*p*sin(p*u); \
zuu: -sin(q*u)*(q*q*(R1 + R2*cos(p*u) + r*cos(v)) + p*p*R2*cos(p*u)) - \
2*R2*p*q*cos(q*u)*sin(p*u); "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: q*r*sin(v)*sin(q*u); \
yuv: 0; \
zuv: -q*r*sin(v)*cos(q*u); "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: -r*cos(v)*cos(q*u); \
yvv: -r*sin(v); \
zvv: -r*cos(v)*sin(q*u); "
#endif
"end;";
#endif
