
#include "../torus_desc_inc.h"


#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddWaveTorus = {
PSLDD_ID( WAVE_TORUS )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(4),
0 , 2 , 0 , 2 , torus_def_constants };
#endif

#if(COMPILE_DESC_TORUS != 0)
char* descWaveTorus =
"start; \
name: wave torus; \
cat: torus; \
utype: closed; \
vtype: closed; \
ustart: 0; \
uend: pi : 2; \
vstart: 0; \
vend: pi: 2; \
c:1:R: 1.5; \
c:2:r: 0.5; \
c:3:a: 1.0; \
c:4:n: 1.0; \
x: (R + cos(v)*(r + a*sin(n*u)))*cos(u); \
y: (R + cos(v)*(r + a sin(n*u)))*sin(u); \
z: (r + a*sin(n*u))*sin(v); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: -R*sin(u) + cos(v)*(a*(n*cos(n*u)**cos(u) - sin(u)*sin(n*u)) -  r*sin(u)); \
yu: -R*cos(u) + cos(v)*(a*(n*cos(n*u)*sin(u) - cos(u)*sin(n*u)) -  r*cos(u)); \
zu: a*n*cos(n*u)*sin(v); "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: -(r + a*sin(n*u))*sin(v)*cos(u); \
yv: -(r + a*sin(n*u))*sin(v)*sin(u); \
zv: (r + a*sin(n*u))*cos(v); "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn:X; \
xn: ;\
yn:X; \
yn: ; \
zn:X; \
zn: "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: -cos(u)*(R + a*cos(v)*sin(n*u) + a*n*n*cos(v)*sin(n*u) + r*cos(v)) - 2*a*n*cos(v)*cos(n*u)*sin(u); \
yuu: -sin(u)*(R + a*cos(v)*sin(n*u) + a*n*n*cos(v)*sin(n*u) + r*cos(v)) -  2*a*n*cos(v)*cos(n*u)*cos(u); \
zuu: -a*n*n*sin(v)*sin(n*u); "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: (-a*n*cos(u)*cos(n*u) + sin(u)*(a*sin(n*u) + r))*sin(v); \
yuv: -(a*n*sin(u)*cos(n*u) + cos(u)*(a*sin(n*u) + r))*sin(v); \
zuv: a*n*cos(v)*cos(n*u); "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: -(r + a*sin(n*u))*cos(v)*cos(u); \
yvv: -(r + a*sin(n*u))*cos(v)*sin(u); \
zvv: (r + a*sin(n*u))*sin(v); "
#endif
"end;";
#endif

