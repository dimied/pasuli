
#include "../torus_desc_inc.h"

#if(COMPILE_DEF_DESC_TORUS != 0)
PaSuLiDefDesc pslddGeronoLemniskateTorus1 = {
PSLDD_ID( GERONO_LEMNISKATE_TORUS_1 )
PASULI_U_CLOSED|PASULI_V_CLOSED|PASULI_U_END_PI|\
PASULI_V_END_PI|PASULI_CONST_COUNT(2),
0 , 2 , 0 , 2 , 0 };
#endif
#if(COMPILE_DESC_TORUS != 0)
char* descGeronoLemniskateTorus1 =
"start; \
name: Gerono Lemniskate Torus 1; \
cat: torus; \
ustart: 0; \
uend:pi:2; \
vstart: 0; \
vend: pi:2; \
c:1:R:1.0; \
c:2:1: 1.0; \
a:1:F: r*sin(v); \
x: (R + F)*cos(u); \
y: F*cos(v); \
z: (R + F)*sin(u); "
#if(COMPILE_DESC_DERIV_U_TORUS != 0)
"xu: 0; \
yu: 0; \
zu: 0; "
#endif
#if(COMPILE_DESC_DERIV_V_TORUS != 0)
"xv: 0; \
yv: 0; \
zv: 0; "
#endif
#if(COMPILE_DESC_NORMAL_TORUS != 0)
"xn: 0; \
yn: 0; \
zn: 0; "
#endif
#if(COMPILE_DESC_DERIV2_U_TORUS != 0)
"xuu: 0; \
yuu: 0; \
zuu: 0; "
#endif
#if(COMPILE_DESC_DERIV_UV_TORUS != 0)
"xuv: 0; \
yuv: 0; \
zuv: 0; "
#endif
#if(COMPILE_DESC_DERIV2_V_TORUS != 0)
"xvv: 0; \
yvv: 0; \
zvv: 0; "
#endif
"end;";
#endif


